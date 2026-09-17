#include QMK_KEYBOARD_H
#include "chlor8.h"
#include "combos.c"

// Outer columns are snapped off; map the 3x5_3 core onto the 44-key LAYOUT.
// clang-format off
#define LAYOUT_jorne_3x5_3( \
    L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, \
              LT0, LT1, LT2,   RT0, RT1, RT2 \
) LAYOUT( \
    XXXXXXX, XXXXXXX, L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, XXXXXXX, XXXXXXX, \
             XXXXXXX, L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, XXXXXXX, \
             XXXXXXX, L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, XXXXXXX, \
                                LT0, LT1, LT2,   RT0, RT1, RT2 \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_jorne_3x5_3(
  KC_Q   ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,
  CTL_A  ,  OPT_S  ,  SFT_D ,   CMD_F ,  KC_G ,                                     KC_H,   CMD_J , SFT_K ,  OPT_L , CTL_QUOT,
  KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,                                       KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_UNDERSCORE ,
                    _______, TAB_NAV , KC_BSPC,                                              KC_SPACE, SYM, KC_DEL
),

[_NAV] = LAYOUT_jorne_3x5_3(
  KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_REDO,                                    _______, KC_PGDN, KC_PGUP, _______, FKEYS,
  KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, _______,                                   KC_LEFT , KC_DOWN , KC_UP   ,KC_RIGHT, _______,
  QK_REP, _______, _______, _______, _______,                                       WD_LEFT, WD_RGHT, _______, KC_DEL, GAME,
  _______, _______, _______,                                               _______, _______, _______
),

[_SYM] = LAYOUT_jorne_3x5_3(
  KC_PERC , KC_LBRC , KC_RBRC ,  KC_GRV, KC_HASH ,                                  KC_PIPE   , KC_AMPR , KC_ASTR ,KC_CIRC , KC_SCLN,
  KC_QUES  , KC_LPRN , KC_RPRN , KC_COLN , KC_DQUO,                                  KC_MINS , KC_EQL , KC_LT ,KC_GT, KC_EXLM,
  KC_AT , KC_LCBR , KC_RCBR , KC_BSLS , KC_DLR ,                                    KC_PLUS , KC_SLSH  , KC_TRNS   ,KC_TRNS , KC_TILD,
                     _______, _______, _______,                                                _______, _______, _______
),

[_NUM] = LAYOUT_jorne_3x5_3(
  KC_1  , KC_2  , KC_3  , KC_4 ,  KC_5 ,                                            KC_6, KC_7, KC_8, KC_9, KC_0,
  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                     _______, _______, _______,                                                _______, _______, _______
),

[_FUNCTION] = LAYOUT_jorne_3x5_3(
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                       KC_F6,  KC_F7 ,  KC_F8,  KC_F9,  KC_F10,
   OS_TOG, _______, _______, _______, _______,                                      KC_F11,  KC_F12 ,  _______ ,   _______,  _______ ,
   _______, _______, _______, SCRNSHT, _______,                                     _______,  _______ ,  _______ ,  _______ ,  _______ ,
                     _______, _______, QK_BOOT,                                                QK_BOOT, _______, _______
),

[_GAMING] = LAYOUT_jorne_3x5_3(
  ESC_ALT,  KC_Q   ,  KC_W  ,   KC_E ,   KC_R,                                      KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,
  CTL_ENT,  KC_A   ,  KC_S  ,   KC_D ,   KC_F ,                                     KC_H,   KC_J ,  KC_K ,   KC_L ,_______,
  SHIFT_Z,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,                                     KC_N,   KC_M ,KC_COMM, KC_ESC ,GAME,
                     TAB_NGAME, BSP_NAV , KC_SPACE,                                  KC_SPACE, SYM, _______
),

[_NUM_GAMING] = LAYOUT_jorne_3x5_3(
  KC_1  , KC_2  , KC_3  ,  KC_4 ,  KC_5 ,                                          _______, _______, _______, _______, _______,
  KC_6  , KC_7  , KC_8  ,  KC_9 ,  KC_0 ,                                          _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                     _______, _______, _______,                                                _______, _______, _______
)

};
// clang-format on
