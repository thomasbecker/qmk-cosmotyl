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
#define SAFE_BRIGHTNESS 180 // Reduce from 255 to help with power management

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_sethsv_noeeprom(0, 255, SAFE_BRIGHTNESS);
    }

    // Reset brightness if it changes
    static uint8_t last_val    = SAFE_BRIGHTNESS;
    uint8_t        current_val = rgb_matrix_get_val();
    if (current_val != last_val) {
        rgb_matrix_sethsv_noeeprom(0, 255, SAFE_BRIGHTNESS);
        last_val = SAFE_BRIGHTNESS;
    }

    // Set colors for all LEDs based on current layer
    for (uint8_t i = led_min; i < led_max; i++) {
        dprintf("Setting color for LED %u for layer: %u\n", i, layer);
        switch (layer) {
            case NUM:
                dprintf("NUM layer (7): Setting blue/magenta for: %d\n", i);
                if (i == 3 || (i >= 6 && i <= 8) || (i >= 11 && i <= 13) || (i >= 16 && i <= 18)) {
                    rgb_matrix_set_color(i, 255, 0, 255); // Bright magenta for number keys
                } else {
                    rgb_matrix_set_color(i, 0, 0, 255); // Blue for other keys
                    dprintf("NUM layer setting color from layer_state_set_user for LED %d\n", i);
                }
                break;
            case BASE:
                rgb_matrix_set_color(i, 0, 255, 0); // Green
                break;
            case MEDIA:
                rgb_matrix_set_color(i, 255, 0, 0); // Red
                break;
            case NAV:
                if ((i >= 30 && i <= 33)) {
                    rgb_matrix_set_color(i, 0, 255, 0); // green for arrow keys
                } else {
                    rgb_matrix_set_color(i, 0, 96, 255); // Cyan for other keys
                }
                break;
            case MOUSE:
                rgb_matrix_set_color(i, 128, 0, 128); // Purple
                break;
            case SYM:
                rgb_matrix_set_color(i, 255, 128, 0); // Orange
                break;
            case FUN:
                rgb_matrix_set_color(i, 255, 255, 0); // Yellow
                break;
            default:
                rgb_matrix_set_color(i, 50, 50, 50); // Dim white for unknown layers
                break;
        }
    }

    return true;
}

bool rgb_matrix_indicators_user(void) {
    dprintf("rgb_matrix_indicators_user called\n");
    return true; // Let the normal RGB processing continue
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;

    // Initialize RGB Matrix with maximum brightness
    rgb_matrix_disable_noeeprom(); // First disable to ensure clean state
    rgb_matrix_enable_noeeprom();  // Then enable
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_set_flags(LED_FLAG_ALL);
    rgb_matrix_set_speed_noeeprom(0);

    // Set HSV values all at once (hue, saturation, brightness)
    rgb_matrix_sethsv_noeeprom(0, 255, 255);

    // Debug LED configuration
    dprintf("LED Configuration:\n");
    // dprintf("Number of LEDs in config: %d\n", g_led_config.num_leds);
    // dprintf("DRIVER LED COUNT: %d\n", DRIVER_LED_TOTAL);
    dprintf("RGB MATRIX LED COUNT: %d\n", RGB_MATRIX_LED_COUNT);

    // Initialize RGB Matrix with more explicit configuration
    // rgb_matrix_enable_noeeprom();
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    // rgb_matrix_set_speed_noeeprom(0);

    // Set initial color
    // rgb_matrix_set_color_all(0, 255, 0);

    // Debug RGB state
    dprintf("Initial RGB mode: %d\n", rgb_matrix_get_mode());
    dprintf("RGB enabled: %d\n", rgb_matrix_is_enabled());
    dprintf("RGB flags: 0x%08X\n", rgb_matrix_get_flags());

    // Initialize debug output
    print("Keyboard initialized.\n");
}
