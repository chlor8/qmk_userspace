#ifndef USERSPACE
#define USERSPACE
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

enum tap_dance_codes {
    NUM_SYM,
};

enum combo_events {
    ENDLINE,
    STARTLINE,
    C_ENTER,
    C_ESC,
};

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

// extern combo_t key_combos[];

#endif