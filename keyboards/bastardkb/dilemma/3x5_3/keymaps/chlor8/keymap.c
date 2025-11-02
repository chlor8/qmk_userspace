

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _FUNCTION,
    _GAMING,
    _NUM_GAMING,
};

#define LAYOUT LAYOUT_split_3x5_3
#define QWERTY DF(_QWERTY)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define GAME TG(_GAMING)
#define GAMEN MO(_NUM_GAMING)


#define SHIFT_Z LSFT_T(KC_Z)
#define SHIFT__ RSFT_T(KC_UNDERSCORE)
#define CTRL_A MT(MOD_LCTL, KC_A)
#define ALT_QUOT MT(OSM(MOD_LALT), KC_QUOTE)
#define TAB_NAV LT(NAV, KC_TAB)
#define TAB_NGAME LT(GAMEN, KC_TAB)
#define BSP_NAV LT(NAV, KC_BSPC)

#define KC_REDO LCTL(KC_Y)
#define KC_UNDO LCTL(KC_Z)
#define KC_COPY LCTL(KC_C)
#define KC_CUT  LCTL(KC_X)
#define KC_PASTE LCTL(KC_V)

#define CTLSHFT OSM(MOD_LCTL | MOD_LSFT)
#define CTLALT OSM(MOD_LCTL | MOD_RALT)
#define ALTSHFT OSM(MOD_RSFT | MOD_RALT)
#define BSP_NAV LT(NAV, KC_BSPC)
#define ESC_ALT MT(OSM(MOD_LALT), KC_ESC)
#define CTL_ENT MT(OSM(MOD_LCTL), KC_ENTER)
// homerow mods
// left hand
#define GUI_A    MT(MOD_LGUI, KC_A)
#define ALT_S    MT(MOD_LALT, KC_S)
#define SHIFT_D  MT(MOD_LSFT, KC_D)
#define CTRL_F   MT(MOD_LCTL, KC_F)
// right hand
#define GUI_QUOT MT(MOD_LGUI, KC_QUOTE)
#define ALT_L    MT(MOD_LALT, KC_L)
#define SHIFT_K  MT(MOD_RSFT, KC_K)
#define CTRL_J   MT(MOD_LCTL, KC_J)

enum combos {
  ENDLINE,
  STARTLINE,
  C_ENTER,
  C_ESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
  KC_Q   ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,
  GUI_A ,  ALT_S   ,  SHIFT_D  ,   CTRL_F ,   KC_G ,                                     KC_H,   CTRL_J ,  SHIFT_K ,   ALT_L ,GUI_QUOT,
  KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,                                     KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_UNDERSCORE ,
                    KC_ENTER, TAB_NAV , KC_BSPC,                                              KC_SPACE, SYM, FKEYS
),

[_NAV] = LAYOUT(
  KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_REDO,                                    _______, KC_PGDN, KC_PGUP, _______, FKEYS,
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                   KC_LEFT , KC_DOWN , KC_UP   ,KC_RIGHT, _______,
  QK_REP, _______, _______, _______, _______,                                       _______, _______, _______, _______, GAME,
  _______, _______, _______,                                               _______, _______, _______
),

[_SYM] = LAYOUT(
  KC_PERC , KC_LBRC , KC_RBRC ,  KC_GRV, KC_HASH ,                                  KC_PIPE   , KC_AMPR , KC_ASTR ,KC_CIRC , KC_SCLN,
  KC_QUES  , KC_LPRN , KC_RPRN , KC_COLN , KC_DQUO,                                  KC_MINS , KC_EQL , KC_LT ,KC_GT, KC_EXLM,
  KC_AT , KC_LCBR , KC_RCBR , KC_BSLS , KC_DLR ,                                    KC_PLUS , KC_SLSH  , KC_TRNS   ,KC_TRNS , KC_TILD,
                     _______, _______, _______,                                                _______, _______, _______
),

[_NUM] = LAYOUT(
  KC_1  , KC_2  , KC_3  , KC_4 ,  KC_5 ,                                            KC_6, KC_7, KC_8, KC_9, KC_0,
  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                     _______, _______, _______,                                                _______, _______, _______
),


[_FUNCTION] = LAYOUT(

  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                       KC_F6,  KC_F7 ,  KC_F8,  KC_F9,  KC_F10,
   _______, _______, _______, _______, _______,                                     KC_F11,  KC_F12 ,  _______ ,   _______,  _______ ,
   _______, _______, _______, _______, _______,                                     _______,  _______ ,  _______ ,  _______ ,  _______ ,
                     _______, _______, QK_BOOT,                                                QK_BOOT, _______, _______
),

[_GAMING] = LAYOUT(
  ESC_ALT,  KC_Q   ,  KC_W  ,   KC_E ,   KC_R,                                      KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,
  CTL_ENT,  KC_A   ,  KC_S  ,   KC_D ,   KC_F ,                                     KC_H,   KC_J ,  KC_K ,   KC_L ,_______,
  SHIFT_Z,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,                                     KC_N,   KC_M ,KC_COMM, KC_ESC ,GAME,
                     TAB_NGAME, BSP_NAV , KC_SPACE,                                  KC_SPACE, SYM, _______
),

[_NUM_GAMING] = LAYOUT(
  KC_1  , KC_2  , KC_3  ,  KC_4 ,  KC_5 ,                                          _______, _______, _______, _______, _______,
  KC_6  , KC_7  , KC_8  ,  KC_9 ,  KC_0 ,                                          _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                     _______, _______, _______,                                                _______, _______, _______
)

};

// combos
const uint16_t PROGMEM jk[] = {CTRL_J, SHIFT_K, COMBO_END};
const uint16_t PROGMEM kl[] = {SHIFT_K, ALT_L, COMBO_END};
const uint16_t PROGMEM sd[] = {ALT_S, SHIFT_D, COMBO_END};
const uint16_t PROGMEM sf[] = {ALT_S, CTRL_F, COMBO_END};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    switch (index) {
        case C_ENTER:
            return 300;
    }
    return COMBO_TERM;
}

combo_t key_combos[] = {
    [ENDLINE] = COMBO(jk, KC_HOME),
    [STARTLINE] = COMBO(kl, KC_END),
    [C_ENTER] = COMBO(sd,KC_ENTER),
    [C_ESC] = COMBO(sf,KC_ESC),
};


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
            return TAPPING_TERM + 50;
        case GUI_A:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
