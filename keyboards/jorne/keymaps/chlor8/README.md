# Jorne — chlor8

The Jorne here is snapped down to 3x5+3 (36 keys). The left half has a Boardsource Blok (RP2040) and the right half has a Pro Micro (ATmega32u4). The keymap shares `users/chlor8` with the Dilemma, crkbd and 3w6.

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
  - `OS_TOG` sits on the A position.
  - Screenshot sits on V.
  - `QK_BOOT` is on the inner thumbs.
- **Combos:**
  - J+K: line start. K+L: line end.
  - S+D: Enter. S+F: Esc.
- **GAMING:** toggle from NAV, bottom-right key.
  - Letters are shifted one column right. The pinky column is Esc/Alt, Enter/Ctrl, Z/Shift.
  - Hold the left outer thumb (Tab) for numbers: 1–5 on the top row, 6–0 on the home row.

## Mac / Linux mode

`OS_TOG` (QMK `CG_TOGG`) swaps Ctrl and Cmd, and the setting is stored in EEPROM.

- **Mac mode (default):** Cmd keys send Cmd.
- **Linux mode:** the same keys send Ctrl, so Ctrl+C, Ctrl+Z and the rest work on Linux without any remapping software.

Some keys aren't just a modifier swap. These send a different chord per mode (see `users/chlor8/chlor8.c`):

| Key | Mac | Linux |
|---|---|---|
| `LN_BEG` / `LN_END` | Cmd+← / Cmd+→ | Home / End |
| `WD_LEFT` / `WD_RGHT` | Opt+← / Opt+→ | Ctrl+← / Ctrl+→ |
| `SCRNSHT` | Cmd+Shift+4 | PrintScreen |

A flash that clears EEPROM starts in Mac mode. Tap `OS_TOG` once when you're on Linux.

## Build

The Jorne builds from upstream QMK (`qmk/qmk_firmware`). The Dilemma builds from `Bastardkb/bastardkb-qmk@bkb-develop`, which CI uses. The toolchain runs in the QMK container, so nothing gets installed on the host:

```sh
podman run --rm --security-opt label=disable \
  -v ~/qmk_firmware:/qmk -v "$PWD":/us -w /us ghcr.io/qmk/qmk_cli \
  bash -c 'git config --global --add safe.directory "*"; qmk config user.qmk_home=/qmk user.overlay_dir=/us; \
           qmk compile -kb jorne/rev1 -km chlor8 && qmk compile -kb jorne/rev1 -km chlor8 -e CONVERT_TO=blok'
```

Run it from the userspace root. It produces:

- `jorne_rev1_chlor8.hex`: right half (Pro Micro).
- `jorne_rev1_chlor8_blok.uf2`: left half (Blok).

The Dilemma doesn't build on current `bkb-develop`: `DPI_MOD`, `DPI_RMOD` and `SNP_TOG` are undeclared there.

## Flash

Flash both halves after every keymap change.

- **Left (Blok):** hold BOOT while plugging in, then copy the `.uf2` onto the `RPI-RP2` drive.
- **Right (Pro Micro):** start the command below, then short RST to GND twice. The bootloader stays open for about 8 s.

  ```sh
  podman run --rm -it --privileged -v /dev:/dev -v "$PWD":/fw ghcr.io/qmk/qmk_cli \
    sh -c 'until ls /dev/ttyACM* 2>/dev/null; do sleep 0.5; done; avrdude -p atmega32u4 -c avr109 -P $(ls /dev/ttyACM* | head -1) -U flash:w:/fw/jorne_rev1_chlor8.hex:i'
  ```

## Hardware caveats

- **USB:** always plug USB into the left (Blok) half. Handedness comes from `MASTER_LEFT`.
- **Voltage:** the RP2040 is 3.3 V and its pins aren't 5 V tolerant. A 5 V Pro Micro drives the split serial line (D2 ↔ GP1) at 5 V, which can damage the Blok.
- **Mixed controllers:** QMK doesn't officially support splits with two different MCUs. If the right half is dead after flashing, suspect the link between the halves, not the keymap. Two matching controllers fix it.
