#pragma once

#include "quantum.h"

enum layers {
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _FUNCTION,
    _GAMING,
    _NUM_GAMING,
};

enum combo_events {
    ENDLINE,
    STARTLINE,
    C_ENTER,
    C_ESC,
};

enum custom_keycodes {
    DUMP_CFG = SAFE_RANGE,
};

#define QWERTY DF(_QWERTY)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define GAME TG(_GAMING)
#define GAMEN MO(_NUM_GAMING)

// Mac shortcuts on every host; Linux gets them via Toshy (keyboard type "Apple").
#define LN_BEG  LGUI(KC_LEFT)
#define LN_END  LGUI(KC_RGHT)
#define WD_LEFT LALT(KC_LEFT)
#define WD_RGHT LALT(KC_RGHT)
#define SCRNSHT LSG(KC_4)

#define SHIFT_Z LSFT_T(KC_Z)
#define TAB_NAV LT(_NAV, KC_TAB)
#define TAB_NGAME LT(_NUM_GAMING, KC_TAB)
#define BSP_NAV LT(_NAV, KC_BSPC)
#define BSP_GAME LT(_NUM_GAMING, KC_BSPC)
#define ESC_ALT LALT_T(KC_ESC)
#define CTL_ENT LCTL_T(KC_ENT)

#define KC_UNDO LGUI(KC_Z)
#define KC_REDO LSG(KC_Z)
#define KC_COPY LGUI(KC_C)
#define KC_CUT  LGUI(KC_X)
#define KC_PASTE LGUI(KC_V)

#define CTLSHFT OSM(MOD_LCTL | MOD_LSFT)
#define CTLALT OSM(MOD_LCTL | MOD_RALT)
#define ALTSHFT OSM(MOD_RSFT | MOD_RALT)

// homerow mods, Cmd on index
// left hand
#define CTL_A    MT(MOD_LCTL, KC_A)
#define OPT_S    MT(MOD_LALT, KC_S)
#define SFT_D    MT(MOD_LSFT, KC_D)
#define CMD_F    MT(MOD_LGUI, KC_F)
// right hand
#define CMD_J    MT(MOD_LGUI, KC_J)
#define SFT_K    MT(MOD_RSFT, KC_K)
#define OPT_L    MT(MOD_LALT, KC_L)
#define CTL_QUOT MT(MOD_LCTL, KC_QUOTE)
