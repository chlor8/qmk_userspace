#!/usr/bin/env bash
set -eEuo pipefail

userspacePath="$1"

echo "Select QMK repo:"
select choice in "bkb" "main"; do
  case "$choice" in
    bkb)  QMK_HOME=/workspaces/qmk/bkb;  break ;;
    main) QMK_HOME=/workspaces/qmk/main; break ;;
    *) echo "Invalid choice";;
  esac
done

python3 -m pip install -U pip qmk milc

git config --global --add safe.directory "$userspacePath"
git config --global --add safe.directory "$QMK_HOME"

cd "$QMK_HOME"
git submodule update --init --recursive

qmk config user.qmk_home="$QMK_HOME"
qmk config user.overlay_dir="$userspacePath"
qmk config user.build_dir=/workspaces/qmk/builds
qmk git-submodule
