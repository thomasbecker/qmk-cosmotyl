// Copyright 2022 Shem Sedrick (@ssedrick)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS // Store which side I am in EEPROM

// Wiring pins
// #define MATRIX_ROW_PINS {GP4, GP5, GP6, GP7, GP8}
// #define MATRIX_COL_PINS {GP9, GP10, GP19, GP20, GP18}

/* Encoders */
// #define ENCODERS_PAD_A { GP21, GP20 }
// #define ENCODERS_PAD_B { GP18, GP19 }

/* Trackball */
// #define SPI_DRIVER SPID0
// #define SPI_SCK_PIN GP18
// #define SPI_MISO_PIN GP20
// #define SPI_MOSI_PIN GP19
// #define POINTING_DEVICE_CS_PIN GP10
// #define ROTATIONAL_TRANSFORM_ANGLE -30 // Optional: Rotates the trackball
// #define POINTING_DEVICE_INVERT_X // Optional: Inverts trackball X

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
