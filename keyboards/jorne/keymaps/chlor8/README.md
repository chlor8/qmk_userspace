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

Both halves flash the same way. Flash both after every keymap change.

1. Unplug the keyboard and the TRRS cable.
2. Hold BOOT while plugging the half in (or double-tap reset). An `RPI-RP2` drive appears.
3. Copy that half's file onto the drive: `jorne-LEFT-blok.uf2` for the left, `jorne-RIGHT-rp2040ce.uf2` for the right. It reboots by itself.

## Hardware caveats

- Plug USB into the left (Blok) half.
- The halves use different converters (`blok` and `rp2040_ce`), so flash each half with its own file.
