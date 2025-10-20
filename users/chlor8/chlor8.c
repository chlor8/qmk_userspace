#include "chlor8.h"

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};

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