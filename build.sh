#!/usr/bin/env bash
# Build keyboard firmware in the QMK container; files land in ~/Documents/keyboards/<board>/,
# with a timestamped copy under erebor so earlier builds are never lost.
# usage: build.sh [board...]   boards: jorne 3w6 dilemma (default: all)
set -uo pipefail

userspace=$(cd "$(dirname "$0")" && pwd)
out_root=${OUT_ROOT:-$HOME/Documents/keyboards}
main_home=${QMK_HOME:-$HOME/qmk_firmware}
bkb_home=${BKB_HOME:-$HOME/bastardkb-qmk}
backup_root=${BACKUP_ROOT:-/var/home/bazzite/erebor/keyboards/builds}
stamp=$(date +%Y-%m-%d_%H%M)

ensure_tree() { # dir url branch
    [ -d "$1" ] || git clone --depth 1 --recurse-submodules --shallow-submodules -b "$3" "$2" "$1"
}

# qmk_compile <qmk_home> <compile args...>
qmk_compile() {
    local home=$1; shift
    # label=disable: SELinux would otherwise block the bind mounts under $HOME.
    podman run --rm --security-opt label=disable \
      -v "$home":/qmk -v "$userspace":/us -w /us ghcr.io/qmk/qmk_cli \
      bash -c 'git config --global --add safe.directory "*"
               qmk config user.qmk_home=/qmk user.overlay_dir=/us >/dev/null
               qmk compile -j 8 "$@"' _ "$@"
}

# collect <board> <built file> <dest name>
collect() {
    mkdir -p "$out_root/$1"
    mv "$userspace/$2" "$out_root/$1/$3"
    if [ -d "$(dirname "$backup_root")" ]; then
        mkdir -p "$backup_root/$1/$stamp" && cp "$out_root/$1/$3" "$backup_root/$1/$stamp/"
    else
        echo "WARN: $(dirname "$backup_root") not mounted; no backup of $3"
    fi
}

build_jorne() {
    ensure_tree "$main_home" https://github.com/qmk/qmk_firmware master || return
    # Both halves are RP2040: Blok left, RP2040-CE Pro Micro right.
    qmk_compile "$main_home" -kb jorne/rev1 -km chlor8 -e CONVERT_TO=blok &&
    qmk_compile "$main_home" -kb jorne/rev1 -km chlor8 -e CONVERT_TO=rp2040_ce &&
    collect jorne jorne_rev1_chlor8_blok.uf2 jorne-LEFT-blok.uf2 &&
    collect jorne jorne_rev1_chlor8_rp2040_ce.uf2 jorne-RIGHT-rp2040ce.uf2
}

build_3w6() {
    ensure_tree "$main_home" https://github.com/qmk/qmk_firmware master || return
    qmk_compile "$main_home" -kb 3w6/rev2 -km chlor8 &&
    collect 3w6 3w6_rev2_chlor8.hex 3w6.hex
}

build_dilemma() {
    ensure_tree "$bkb_home" https://github.com/Bastardkb/bastardkb-qmk bkb-develop || return
    qmk_compile "$bkb_home" -kb bastardkb/dilemma/3x5_3_procyon -km chlor8 &&
    collect dilemma bastardkb_dilemma_3x5_3_procyon_chlor8.uf2 dilemma.uf2
}

boards=("$@"); [ ${#boards[@]} -eq 0 ] && boards=(jorne 3w6 dilemma)
failed=()
for b in "${boards[@]}"; do
    echo "=== $b"
    "build_$b" || failed+=("$b")
done
ls -lR "$out_root"
[ ${#failed[@]} -eq 0 ] || { echo "FAILED: ${failed[*]}"; exit 1; }
