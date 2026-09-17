#include "chlor8.h"

uint8_t mod_state;

// Linux mode = Ctrl<->GUI swap on (OS_TOG).
static bool os_is_linux(void) {
    return keymap_config.swap_lctl_lgui;
}

// Returns the concrete chord for an OS-dependent keycode, or KC_NO if not one.
static uint16_t os_chord(uint16_t keycode) {
    bool on_linux = os_is_linux();
    switch (keycode) {
        case LN_BEG:  return on_linux ? KC_HOME : LGUI(KC_LEFT);
        case LN_END:  return on_linux ? KC_END : LGUI(KC_RGHT);
        case WD_LEFT: return on_linux ? LCTL(KC_LEFT) : LALT(KC_LEFT);
        case WD_RGHT: return on_linux ? LCTL(KC_RGHT) : LALT(KC_RGHT);
        case SCRNSHT: return on_linux ? KC_PSCR : LSG(KC_4);
    }
    return KC_NO;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {

    //
    // SHIFT + Backspace → Send Delete
    //
    case KC_BSPC: {
        static bool delkey_registered;

        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }

        return true;
    }

    case LN_BEG:
    case LN_END:
    case WD_LEFT:
    case WD_RGHT:
    case SCRNSHT: {
        // Remember the chord sent on press so a mid-hold OS toggle can't strand keys.
        static uint16_t held[SCRNSHT - LN_BEG + 1];
        uint8_t slot = keycode - LN_BEG;
        if (record->event.pressed) {
            held[slot] = os_chord(keycode);
            register_code16(held[slot]);
        } else {
            unregister_code16(held[slot]);
        }
        return false;
    }

    //
    // CUSTOM: Dump Dilemma firmware config
    //
case DUMP_CFG:
    if (record->event.pressed) {
        return false;
    }
    break;

    }

    return true;
}

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case KC_UNDERSCORE:
        // case NUM_SYM:
        // case TAB_NAV:
            return true;
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // pinky keys are slowest to release
        case CTL_A:
            return TAPPING_TERM + 100;
        case CTL_QUOT:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
