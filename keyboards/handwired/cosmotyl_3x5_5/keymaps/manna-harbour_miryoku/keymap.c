#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},  // Mapping for Base layer
    [4] = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},  // Mapping for Layer 1
    [5] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},  // Mapping for Layer 2
    [6] = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}, // Mapping for Layer 3
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Mapping for Layer 3
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Mapping for Layer 3
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Mapping for Layer 3
    [7] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Mapping for Layer 3
    [8] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Mapping for Layer 3

    // You can add more layers here if you need them, or you can also delete lines for layers you are not using
};
#endif
