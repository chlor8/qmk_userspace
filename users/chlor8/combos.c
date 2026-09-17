#include "chlor8.h"

const uint16_t PROGMEM jk[] = {CMD_J, SFT_K, COMBO_END};
const uint16_t PROGMEM kl[] = {SFT_K, OPT_L, COMBO_END};
const uint16_t PROGMEM sd[] = {OPT_S, SFT_D, COMBO_END};
const uint16_t PROGMEM sf[] = {OPT_S, CMD_F, COMBO_END};

combo_t key_combos[] = {
    [ENDLINE] = COMBO(jk, LN_BEG),
    [STARTLINE] = COMBO(kl, LN_END),
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

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
