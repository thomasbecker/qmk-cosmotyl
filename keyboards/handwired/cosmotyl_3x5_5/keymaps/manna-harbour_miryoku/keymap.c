#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)

enum layer_names { BASE = 0, MEDIA = 6, NAV = 4, MOUSE = 5, SYM = 8, NUM = 7, FUN = 9 };
// clang-format off
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

    // [0] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    // [4] = {ENCODER_CCW_CW(RM_PREV, RM_NEXT)},
    // [5] = {ENCODER_CCW_CW(RM_SATD, RM_SATU)},
    // [6] = {ENCODER_CCW_CW(QK_RGB_MATRIX_VALUE_DOWN, QK_RGB_MATRIX_VALUE_UP)},
    // [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // [2] = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    // [3] = {ENCODER_CCW_CW(RM_SPDD, RM_SPDU)},
    // [7] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // [8] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // You can add more layers here if you need them, or you can also delete lines for layers you are not using
};
#endif
// clang-format on
int leds[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};

#define NUM_LEDS (sizeof(leds) / sizeof(leds[0]))

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    // Define colors for each layer
    for (uint8_t i = led_min; i < led_max; i++) {
        if (i != NO_LED) {
            switch (layer) {
                case NUM:
                    // Number keys are on the home row (indices 5-9 for left side, 25-29 for right side)
                    if (i == 3 || (i >= 6 && i <= 8) || (i >= 11 && i <= 13) || (i >= 16 && i <= 18)) {
                        rgb_matrix_set_color(i, 255, 0, 255); // Bright magenta for number keys
                    } else {
                        rgb_matrix_set_color(i, 0, 0, 255); // Blue for other keys
                    }
                    break;
                case BASE:
                    rgb_matrix_set_color(i, 0, 255, 0); // Green
                    break;
                case MEDIA:
                    rgb_matrix_set_color(i, 255, 0, 0); // Red
                    break;
                case NAV:
                    if ((i >= 26 && i <= 32)) {
                        rgb_matrix_set_color(i, 0, 255, 0); // green for arrow keys
                    } else {
                        rgb_matrix_set_color(i, 0, 255, 255); // Cyan for other keys
                    }
                    break;
                case MOUSE:
                    rgb_matrix_set_color(i, 128, 0, 128); // Purple
                    break;
                case SYM:
                    rgb_matrix_set_color(i, 255, 165, 0); // Orange
                    break;
                case FUN:
                    rgb_matrix_set_color(i, 255, 255, 0); // Yellow
                    break;
                default:
                    rgb_matrix_set_color(i, 50, 50, 50); // Dim white for unknown layers
                    break;
            }
        }
    }
    return false;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     uint8_t layer = get_highest_layer(state | default_layer_state);
//     dprintf("Layer changed to: %u\n", layer);
//
//     if (!rgb_matrix_is_enabled()) {
//         rgb_matrix_enable();
//         dprintf("RGB Matrix was disabled, enabling...\n");
//     }
//
//     // Force disable any effects and ensure we're in direct control
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_set_speed_noeeprom(0);
//
//     dprintf("Current RGB mode: %d\n", rgb_matrix_get_mode());
//
//     // Disable any running animations
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//
//     // Set the color based on layer
//     for (uint8_t i = 0; i < NUM_LEDS; i++) {
//         switch (layer) {
//             case 7: // NUM layer
//                 dprintf("NUM layer (7): Setting blue\n");
//                 // rgb_matrix_sethsv_noeeprom(HSV_BLUE);
//                 rgb_matrix_set_color(leds[i], 255, 0, 255);
//                 break;
//             case 9: // FUN layer
//                 dprintf("FUN layer (9): Setting bright blue\n");
//                 // rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
//                 rgb_matrix_set_color(leds[i], 0, 255, 255);
//                 break;
//             case 8: // SYM layer
//                 dprintf("SYM layer (8): Setting red\n");
//                 // rgb_matrix_sethsv_noeeprom(HSV_RED);
//                 rgb_matrix_set_color(leds[i], 0, 128, 255);
//                 break;
//             case 6: // MEDIA layer
//                 dprintf("MEDIA layer (6): Setting green\n");
//                 // rgb_matrix_sethsv_noeeprom(HSV_GREEN);
//                 rgb_matrix_set_color(leds[i], 128, 0, 255);
//                 break;
//             default:
//                 dprintf("Default case: Layer %u - Setting white %u\n", layer, leds[i]);
//                 rgb_matrix_set_color(leds[i], 255, 255, 255);
//                 break;
//         }
//     }
//
//     dprintf("Color update complete. Mode: %d, Enabled: %d\n", rgb_matrix_get_mode(), rgb_matrix_is_enabled());
//     return state;
// }

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;

    // Initialize RGB Matrix with more explicit configuration
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    rgb_matrix_set_speed_noeeprom(0);

    // Set initial color
    rgb_matrix_set_color_all(0, 255, 0);

    // Debug RGB state
    dprintf("Initial RGB mode: %d\n", rgb_matrix_get_mode());
    dprintf("RGB enabled: %d\n", rgb_matrix_is_enabled());
    dprintf("RGB flags: 0x%08X\n", rgb_matrix_get_flags());

    // Initialize debug output
    print("Keyboard initialized.\n");
}
