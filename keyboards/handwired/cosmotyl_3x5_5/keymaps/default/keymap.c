// Copyright 2022 Shem Sedrick (@ssedrick)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

enum key_layers {
    _COLEMAK
} //, _RAISE, _LOWER };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Colemak
     * ,----------------------------------,                  ,----------------------------------,
     * |   q  |   w  |   f  |   p  |   g  |                  |   j  |   l  |   u  |   y  |   ;  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   a  |   r  |   s  |   t  |   d  |                  |   h  |   n  |   e  |   i  |   o  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                  |   k  |   m  |   ,  |   .  |   /  |
     * '------+------+------+-------------'                  '------+------+------+------+------'
     *        |  [   |   ]  |                                              |   '  |  `~  |
     *        '-------------+------,                                ,------|-------------'
     *                      | ESC  |                                | BSPC |
     *                      |-------------,                  ,------+------|
     *                      | GUI  |  TAB |                  | SHIFT| SPACE|
     *                      |------+------|                  |------+------|
     *                      | RAISE| CTRL |                  | LOWER| ENTER|
     *                      '-------------'                  '-------------'
     */
    [_COLEMAK] = LAYOUT(
        // clang-format off
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_ESC,  KC_LGUI, KC_TAB,           KC_BSPC, KC_RSFT, KC_SPC,
                                RAISE,   KC_LCTL,             LOWER,  KC_ENT
        // clang-format on
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %d, time: %u, interrupt: %d, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    // switch (keycode) {
    //     case COLEMAK:
    //         if (record->event.pressed) {
    //             set_single_persistent_default_layer(_COLEMAK);
    //         }
    //         return false;
    //         break;
    // }
    return true;
}
