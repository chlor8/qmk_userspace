#include QMK_KEYBOARD_H
#include "chlor8.h"
#include "combos.c"
#include "dilemma_chlor8.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q   ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,
  GUI_A ,  ALT_S   ,  SHIFT_D  ,   CTRL_F ,   KC_G ,                                     KC_H,   CTRL_J ,  SHIFT_K ,   ALT_L ,GUI_QUOT,
  KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,                                     KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_UNDERSCORE ,
                    FKEYS, TAB_NAV , KC_BSPC,                                              KC_SPACE, SYM, FKEYS
),

[_NAV] = LAYOUT_split_3x5_3(
  KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_REDO,                                    _______, KC_PGDN, KC_PGUP, _______, FKEYS,
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, QK_MOUSE_BUTTON_1,                                   KC_LEFT , KC_DOWN , KC_UP   ,KC_RIGHT, _______,
  _______, _______, _______, _______, QK_MOUSE_BUTTON_2,                                       _______, _______, _______, _______, GAME,
  _______, _______, _______,                                               _______, _______, _______
),

[_SYM] = LAYOUT_split_3x5_3(
  KC_PERC , KC_LBRC , KC_RBRC ,  KC_GRV, KC_HASH ,                                  KC_PIPE   , KC_AMPR , KC_ASTR ,KC_CIRC , KC_SCLN,
  KC_QUES  , KC_LPRN , KC_RPRN , KC_COLN , KC_DQUO,                                  KC_MINS , KC_EQL , KC_LT ,KC_GT, KC_EXLM,
  KC_AT , KC_LCBR , KC_RCBR , KC_BSLS , KC_DLR ,                                    KC_PLUS , KC_SLSH  , KC_DOT   ,KC_TRNS , KC_TILD,
                     _______, _______, _______,                                                _______, _______, _______
),

[_NUM] = LAYOUT_split_3x5_3(
  KC_1  , KC_2  , KC_3  , KC_4 ,  KC_5 ,                                            KC_6, KC_7, KC_8, KC_9, KC_0,
  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                     _______, _______, _______,                                                _______, _______, _______
),


[_FUNCTION] = LAYOUT_split_3x5_3(

  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                       KC_F6,  KC_F7 ,  KC_F8,  KC_F9,  KC_F10,
   _______, SNP_TOG, DPI_MOD, DPI_RMOD, _______,                                     KC_F11,  KC_F12 ,  _______ ,   _______,  _______ ,
   _______, _______, _______, KC_PRINT_SCREEN, _______,                                     _______,  _______ ,  _______ ,  _______ ,  _______ ,
                     _______, _______, QK_BOOT,                                                QK_BOOT, _______, _______
),

[_GAMING] = LAYOUT_split_3x5_3(
  ESC_ALT,  KC_Q   ,  KC_W  ,   KC_E ,   KC_R,                                      KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,
  CTL_ENT,  KC_A   ,  KC_S  ,   KC_D ,   KC_F ,                                     KC_H,   KC_J ,  KC_K ,   KC_L ,_______,
  SHIFT_Z,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,                                     KC_N,   KC_M ,KC_COMM, KC_ESC ,GAME,
                     _______, BSP_GAME , KC_SPACE,                                  KC_SPACE, SYM, _______
),

[_NUM_GAMING] = LAYOUT_split_3x5_3(
  KC_1  , KC_2  , KC_3  ,  KC_4 ,  KC_5 ,                                          _______, _______, _______, _______, _______,
  KC_6  , KC_7  , KC_8  ,  KC_9 ,  KC_0 ,                                          _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                     _______, _______, _______,                                                _______, _______, _______
)

};
