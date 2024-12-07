#pragma once

#include "quantum.h"

#define XXX KC_NO

// clang-format off
#define LAYOUT( \
    L00, L01, L02, L03, L04,     R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,     R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,     R20, R21, R22, R23, R24, \
              L25, L26, L27,     R25, R26, R27, \
                   L28, L29,     R28, R29 \
) { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, XXX, L25, L26, L27 }, \
    { XXX, XXX, XXX, L28, L29 }, \
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { XXX, XXX, R25, R26, R27 }, \
    { XXX, XXX, XXX, R28, R29 } \
}
