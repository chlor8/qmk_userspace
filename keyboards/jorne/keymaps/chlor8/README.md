# Jorne — chlor8

The Jorne here is snapped down to 3x5+3 (36 keys). Both halves are RP2040: a Boardsource Blok on the left and an RP2040-CE Pro Micro on the right. The keymap shares `users/chlor8` with the Dilemma, crkbd and 3w6.

## Layout

- **Home-row mods (pinky → index):** Ctrl, Opt, Shift, Cmd on both hands.
- **NAV** (hold left thumb Tab):
  - Top row: undo, cut, copy, paste, redo. These send Cmd shortcuts.
  - Arrows sit on H J K L.
  - Bottom row: word left/right under Left/Down.
- **SYM** (hold right middle thumb): symbols.
- **NUM:** hold NAV and SYM together.
- **FUNCTION** (NAV + P position):
  - F1–F12.
  - Screenshot sits on V.
  - `QK_BOOT` is on the inner thumbs.
- **Combos:**
  - J+K: line start. K+L: line end.
  - S+D: Enter. S+F: Esc.
- **GAMING:** toggle from NAV, bottom-right key.
  - Letters are shifted one column right. The pinky column is Esc/Alt, Enter/Ctrl, Z/Shift.
  - Hold the left outer thumb (Tab) for numbers: 1–5 on the top row, 6–0 on the home row.

## Mac shortcuts everywhere

The board always sends Mac modifiers and shortcuts, so the same fingers do the same thing on every computer:

- Index finger is Cmd, pinky is Ctrl.
- Line start/end is Cmd+←/→, word jump is Opt+←/→, screenshot is Cmd+Shift+4.

On Linux, [Toshy](https://github.com/RedBearAK/toshy) turns those Mac shortcuts into Linux ones, including per-app cases like terminal copy and Cmd+Tab. The board must be set as an Apple keyboard in Toshy:

1. Run `toshy-devices` and note the board's device name.
2. Add it to the custom keyboard dictionary in `~/.config/toshy/toshy_config.py` as `'<device name>': 'Apple'`.
3. Run `toshy-services-restart`.

## Build

From the userspace root:

```sh
./build.sh            # all boards: jorne 3w6 dilemma
./build.sh jorne      # just this one
```

Builds run inside the `ghcr.io/qmk/qmk_cli` container via podman, so nothing gets installed on the host. Files land in `~/Documents/keyboards/<board>/`, and each build is also copied to `erebor/keyboards/builds/<board>/<timestamp>/`. Older, hand-made builds are in `erebor/keyboards/`.

- `jorne/jorne-LEFT-blok.uf2`: left half (Blok).
- `jorne/jorne-RIGHT-rp2040ce.uf2`: right half (RP2040-CE).

The Jorne and 3w6 build from upstream QMK (`~/qmk_firmware`). The Dilemma builds from `Bastardkb/bastardkb-qmk@bkb-develop` (`~/bastardkb-qmk`). Missing trees are cloned on first run.

The Dilemma doesn't build on current `bkb-develop`: `DPI_MOD`, `DPI_RMOD` and `SNP_TOG` are undeclared there.

## Flash

Flash both halves after every keymap change. Each half enters its bootloader on its own, with USB plugged into that half.

1. Unplug USB and the TRRS cable. TRRS carries power: never hot-plug it.
2. Plug USB into the half you're flashing and enter the bootloader. Any of these works:
   - Hold **Q** (left) or **P** (right) while plugging in (Bootmagic; also clears EEPROM).
   - Double-tap that half's reset button within 500 ms.
   - Hold the controller's BOOT button while plugging in. This works even with broken firmware.
   - Press `QK_BOOT` (NAV + P position, then an inner thumb). It resets the USB-connected half only.
3. An `RPI-RP2` drive appears. Copy that half's file onto it: `jorne-LEFT-blok.uf2` for the left, `jorne-RIGHT-rp2040ce.uf2` for the right. It reboots by itself.
4. Unplug, reconnect TRRS, then plug USB into the left half.

## Hardware caveats

- Plug USB into the left (Blok) half.
- The halves use different converters (`blok` and `rp2040_ce`), so flash each half with its own file.
