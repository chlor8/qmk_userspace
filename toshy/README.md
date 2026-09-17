# Toshy (Linux)

The boards send Mac shortcuts (Cmd on the index finger). On Linux, [Toshy](https://github.com/RedBearAK/toshy) makes them behave like macOS, including per-app cases such as terminal copy and Cmd+Tab.

## Install

```sh
sh -c "$(curl -L https://raw.githubusercontent.com/RedBearAK/toshy/main/scripts/bootstrap.sh)"
```

Needs sudo. On Bazzite it layers packages with `rpm-ostree` and adds the user to the `input` group, so reboot afterwards. The services start at login.

Mac-style app switcher, and other KDE tweaks, from the unpacked installer folder:

```sh
./setup_toshy.py apply-tweaks --fancy-pants
```

This switches the task switcher to large icons with one icon per app, installs the Application Switcher KWin script, stops the Meta key from opening the app menu (use Cmd+Space), turns off single-click open, and installs a coding font. Log out for the shortcuts to apply.

## Config edits

Both go in `~/.config/toshy/toshy_config.py`, inside the named slices. Toshy keeps slice contents across upgrades. Run `toshy-services-restart` after editing.

**`kbtype_override`**: the boards send real Cmd/Opt, so Toshy must treat them as Apple keyboards. Get device names from `toshy-devices`.

```python
keyboards_UserCustom_dct = {
    'joric Jorne': 'Apple',
}
```

**`user_custom_lists`**: skip remapping in games so Ctrl stays Ctrl (e.g. game-layer crouch).

```python
remotes += ["steam_app_.*", "gamescope"]
remoteStr = toRgxStr(remotes)
```

`steam_app_.*` covers Steam/Proton game windows. Add other game window classes to the same list. To pause remapping entirely, use the Toshy tray icon.
