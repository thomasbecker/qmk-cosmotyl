#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)

enum layer_names { BASE = 0, MEDIA = 6, NAV = 4, MOUSE = 5, SYM = 8, NUM = 7, FUN = 9 };
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]  = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},    // Mouse wheel scroll
    [MEDIA] = {ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)}, // Track prev/next
    [NAV]   = {ENCODER_CCW_CW(KC_HOME, KC_END)},              // Start/End of line
    [MOUSE] = {ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)}, // Horizontal scroll
    [SYM]   = {ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y))},      // Undo/Redo
    [NUM]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},            // Volume control
    [FUN]   = {ENCODER_CCW_CW(LCTL(KC_MINUS), LCTL(KC_PLUS))}, // Zoom in/out
};
#endif
// clang-format on
#define SAFE_BRIGHTNESS 180 // Reduce from 255 to help with power management

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("thomas.becker00@gmail.com");
            } else {
                // when keycode EMAIL is released
            }
            break;
    }
    return true;
};

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
        // dprintf("Setting color for LED %u for layer: %u\n", i, layer);
        switch (layer) {
            case NUM:
                // dprintf("NUM layer (7): Setting blue/magenta for: %d\n", i);
                if (i == 3 || (i >= 6 && i <= 8) || (i >= 11 && i <= 13) || (i >= 16 && i <= 18)) {
                    rgb_matrix_set_color(i, 255, 0, 255); // Bright magenta for number keys
                } else {
                    rgb_matrix_set_color(i, 0, 0, 255); // Blue for other keys
                    // dprintf("NUM layer setting color from layer_state_set_user for LED %d\n", i);
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
    // dprintf("rgb_matrix_indicators_user called\n");
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
    // dprintf("LED Configuration:\n");
    // dprintf("Number of LEDs in config: %d\n", g_led_config.num_leds);
    // dprintf("DRIVER LED COUNT: %d\n", DRIVER_LED_TOTAL);
    // dprintf("RGB MATRIX LED COUNT: %d\n", RGB_MATRIX_LED_COUNT);

    // Initialize RGB Matrix with more explicit configuration
    // rgb_matrix_enable_noeeprom();
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    // rgb_matrix_set_speed_noeeprom(0);

    // Set initial color
    // rgb_matrix_set_color_all(0, 255, 0);

    // Debug RGB state
    // dprintf("Initial RGB mode: %d\n", rgb_matrix_get_mode());
    // dprintf("RGB enabled: %d\n", rgb_matrix_is_enabled());
    // dprintf("RGB flags: 0x%08X\n", rgb_matrix_get_flags());

    // Initialize debug output
    print("Keyboard initialized.\n");
}
