#include "chlor8.h"

const uint16_t PROGMEM jk[] = {CTRL_J, SHIFT_K, COMBO_END};
const uint16_t PROGMEM kl[] = {SHIFT_K, ALT_L, COMBO_END};
const uint16_t PROGMEM sd[] = {ALT_S, SHIFT_D, COMBO_END};
const uint16_t PROGMEM sf[] = {ALT_S, CTRL_F, COMBO_END};

combo_t key_combos[] = {
    [ENDLINE] = COMBO(jk, KC_HOME),
    [STARTLINE] = COMBO(kl, KC_END),
    [C_ENTER] = COMBO(sd, KC_ENTER),
    [C_ESC] = COMBO(sf, KC_ESC),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    switch (index) {
        case C_ENTER:
            return 300;
    }
    return COMBO_TERM;
}
