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

On plug-in, QMK OS detection picks the mode:

- **macOS / iOS:** Mac mode. Cmd keys send Cmd.
- **Linux / Windows:** Linux mode. The same keys send Ctrl, so Ctrl+C, Ctrl+Z and the rest work without remapping software.
- **Unsure:** keeps the last `OS_TOG` setting.

Detection only changes the mode in RAM, so plugging in never writes EEPROM.

`OS_TOG` (QMK `CG_TOGG`) flips the mode by hand and stores it in EEPROM. Use it when detection guesses wrong, for example through a KVM or hub. The next plug-in re-runs detection.

If you use Toshy on Linux, turn detection off (`OS_DETECTION_ENABLE = no` in `users/chlor8/rules.mk`) and keep the board in Mac mode. Toshy expects Cmd, not Ctrl.

Some keys aren't just a modifier swap. These send a different chord per mode (see `users/chlor8/chlor8.c`):

| Key | Mac | Linux |
|---|---|---|
| `LN_BEG` / `LN_END` | Cmd+← / Cmd+→ | Home / End |
| `WD_LEFT` / `WD_RGHT` | Opt+← / Opt+→ | Ctrl+← / Ctrl+→ |
| `SCRNSHT` | Cmd+Shift+4 | PrintScreen |


## Build

```sh
keyboards/jorne/keymaps/chlor8/build.sh [out_dir]
```

This builds both halves from upstream QMK (`~/qmk_firmware`, cloned if missing) inside the `ghcr.io/qmk/qmk_cli` container via podman, so nothing gets installed on the host. Output goes to `~/Documents/jorne-firmware/` by default:

- `jorne-LEFT-blok.uf2`: left half (Blok).
- `jorne-RIGHT-promicro.hex`: right half (Pro Micro).

The Dilemma builds from `Bastardkb/bastardkb-qmk@bkb-develop` (CI). It doesn't build on current `bkb-develop`: `DPI_MOD`, `DPI_RMOD` and `SNP_TOG` are undeclared there.

## Flash

Flash both halves after every keymap change.

- **Left (Blok):** hold BOOT while plugging in, then copy `jorne-LEFT-blok.uf2` onto the `RPI-RP2` drive.
- **Right (Pro Micro):** start the command below, then short RST to GND twice. The bootloader stays open for about 8 s.

  ```sh
  podman run --rm -it --privileged -v /dev:/dev -v ~/Documents/jorne-firmware:/fw ghcr.io/qmk/qmk_cli \
    sh -c 'until ls /dev/ttyACM* 2>/dev/null; do sleep 0.5; done; avrdude -p atmega32u4 -c avr109 -P $(ls /dev/ttyACM* | head -1) -U flash:w:/fw/jorne-RIGHT-promicro.hex:i'
  ```

## Hardware caveats

- **USB:** always plug USB into the left (Blok) half. Handedness comes from `MASTER_LEFT`.
- **Voltage:** the RP2040 is 3.3 V and its pins aren't 5 V tolerant. A 5 V Pro Micro drives the split serial line (D2 ↔ GP1) at 5 V, which can damage the Blok.
- **Mixed controllers:** QMK doesn't officially support splits with two different MCUs. If the right half is dead after flashing, suspect the link between the halves, not the keymap. Two matching controllers fix it.
