#include "chlor8.h"

uint8_t mod_state;

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
        case GUI_QUOT:
            return TAPPING_TERM + 100;
        case GUI_A:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
