#!/usr/bin/env bash
# Build both Jorne halves in the QMK container and collect them in one folder.
# usage: build.sh [out_dir]   (default ~/Documents/jorne-firmware)
set -euo pipefail

userspace=$(cd "$(dirname "$0")/../../../.." && pwd)
qmk_home=${QMK_HOME:-$HOME/qmk_firmware}
out=${1:-$HOME/Documents/jorne-firmware}

[ -d "$qmk_home" ] || git clone --depth 1 --recurse-submodules --shallow-submodules https://github.com/qmk/qmk_firmware "$qmk_home"

# label=disable: SELinux would otherwise block the bind mounts under $HOME.
podman run --rm --security-opt label=disable \
  -v "$qmk_home":/qmk -v "$userspace":/us -w /us ghcr.io/qmk/qmk_cli \
  bash -c 'git config --global --add safe.directory "*"
           qmk config user.qmk_home=/qmk user.overlay_dir=/us >/dev/null
           qmk compile -kb jorne/rev1 -km chlor8 -j 8
           qmk compile -kb jorne/rev1 -km chlor8 -e CONVERT_TO=blok -j 8'

mkdir -p "$out"
mv "$userspace/jorne_rev1_chlor8.hex" "$out/jorne-RIGHT-promicro.hex"
mv "$userspace/jorne_rev1_chlor8_blok.uf2" "$out/jorne-LEFT-blok.uf2"
ls -l "$out"
