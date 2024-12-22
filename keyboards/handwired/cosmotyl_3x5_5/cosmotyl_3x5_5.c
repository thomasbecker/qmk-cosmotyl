#include "cosmotyl_3x5_5.h"

// LED Matrix layout
//   Each LED position corresponds to the physical key layout
//   The numbers represent the LED index

/*
    Left Half:                Right Half:
    0  1  2  3  4            25 26 27 28 29
    5  6  7  8  9            30 31 32 33 34
    10 11 12 13 14           35 36 37 38 39
          15 16 17           40 41 42
             18 19           43 44
                20
*/
// clang-format off
#if defined(RGB_MATRIX_ENABLE)
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index - must match the LAYOUT matrix exactly
        { 19, 18, 17, 16, 15 },         // { L00, L01, L02, L03, L04 }
        { 10, 11, 12, 13, 14 },         // { L10, L11, L12, L13, L14 }
        { 9,  8,  7,  6,  5  },         // { L20, L21, L22, L23, L24 }
        { NO_LED, NO_LED, 4, 3, 2 },    // { XXX, XXX, L25, L26, L27 }
        { NO_LED, NO_LED, NO_LED, 1, 0 },// { XXX, XXX, XXX, L28, L29 }
        // { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }, // { XXX, XXX, XXX, XXX, L30 }

        { 39, 38, 37, 36, 35 },         // { R00, R01, R02, R03, R04 }
        { 30, 31, 32, 33, 34 },         // { R10, R11, R12, R13, R14 }
        { 29, 28, 27, 26, 25 },         // { R20, R21, R22, R23, R24 }
        { 24, 23, 22, NO_LED, NO_LED }, // { R25, R26, R27, XXX, XXX }
        { 21, 20, NO_LED, NO_LED, NO_LED } // { R28, R29, XXX, XXX, XXX }
    },
    {
        // LED Index to Physical Position
        // Left half
        {0,0},   {20,0},   {40,0},   {60,0},   {80,0},    // L00, L01, L02, L03, L04
        {0,16},  {20,16},  {40,16},  {60,16},  {80,16},   // L10, L11, L12, L13, L14
        {0,32},  {20,32},  {40,32},  {60,32},  {80,32},   // L20, L21, L22, L23, L24
                                     {40,48},  {60,48},  {80,48},   // L25, L26, L27
                                              {60,64},  {80,64},    // L28, L29
        // Right half
        {124,0},  {144,0},  {164,0},  {184,0},  {204,0},   // R00-R04
        {124,16}, {144,16}, {164,16}, {184,16}, {204,16},  // R10-R14
        {124,32}, {144,32}, {164,32}, {184,32}, {204,32},  // R20-R24
        {124,48}, {144,48}, {164,48},                       // R25-R27
        {124,64}, {144,64}                                  // R28-R29
    },
    {
        // LED Index to Flag
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        // Right half
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
#endif
