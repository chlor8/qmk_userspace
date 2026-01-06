#pragma once

#include "quantum.h"

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef ENCODER_MAP_ENABLE

#define ENC(CCW, CW) ENCODER_CCW_CW(CCW, CW)
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]     = { ENC(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN) },
    [_NAV]        = { ENC(QK_RGB_MATRIX_HUE_UP, QK_RGB_MATRIX_HUE_DOWN) },
    [_SYM]        = { ENC(DPI_MOD, DPI_RMOD) },
    [_NUM]        = { ENC(QK_UNDERGLOW_MODE_NEXT, QK_UNDERGLOW_MODE_PREVIOUS) },
    [_FUNCTION]   = { ENC(QK_RGB_MATRIX_MODE_NEXT, QK_RGB_MATRIX_MODE_PREVIOUS) },
    [_GAMING]     = { ENC(QK_RGB_MATRIX_VALUE_UP, QK_RGB_MATRIX_VALUE_DOWN) },
    [_NUM_GAMING] = { ENC(MS_WHLU, MS_WHLD) },
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

#define DILEMMA_AUTO_SNIPING_ON_LAYER _NAV
#define DILEMMA_MINIMUM_SNIPING_DPI 100
#define DILEMMA_SNIPING_DPI_CONFIG_STEP 50
#define Dilemma_MINIMUM_DEFAULT_DPI 2000
#define Dilemma_DEFAULT_DPI_CONFIG_STEP 500

// disable the layer light
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Return false to completely disable keyboard-level RGB behavior
    return false;
}


