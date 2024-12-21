// Copyright 2022 Shem Sedrick (@ssedrick)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOOTMAGIC_ROW_RIGHT 6
#define BOOTMAGIC_COLUMN_RIGHT 4

#define WS2812_PIO_USE_PIO1
#define RGBLED_NUM 40

#define RGB_MATRIX_LED_COUNT RGBLED_NUM

/* Trackball */
// #define SPI_DRIVER SPID0
// #define SPI_SCK_PIN GP18
// #define SPI_MISO_PIN GP20
// #define SPI_MOSI_PIN GP19
// #define PMW33XX_CS_PIN GP29
// #define PMW33XX_CPI 1600
// #define PMW33XX_LIFTOFF_DISTANCE 0x02
// #define POINTING_DEVICE_INVERT_Y
// #define ROTATIONAL_TRANSFORM_ANGLE -30 // Optional: Rotates the trackball
// #define ROTATIONAL_TRANSFORM_ANGLE 90
// #define POINTING_DEVICE_TASK_THROTTLE_MS 50
// #define POINTING_DEVICE_INVERT_X // Optional: Inverts trackball X
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_TASK_THROTTLE_MS 1
// #define POINTING_DEVICE_DEBUG

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
