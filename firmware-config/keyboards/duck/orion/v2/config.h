/* Copyright 2022 Wilhelm Schuter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

// key matrix size
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/*
 * Keyboard Matrix Assignments
 * The Orion V2 uses demultiplexers for all but one col.
 * See matrix.c for more details.
 */
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D5, B7 }
#define MATRIX_COL_PINS { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, B5 }

#define MATRIX_COL_MUX_ADDRESS_PINS { F0, F1, C7 }
#define MATRIX_COL_MUX_ENABLE_PINS { C6, B6 }

// Backspace is a special snowflake
#define BACKSPACE_PIN E2
#define BACKSPACE_MATRIX_ROW 5
#define BACKSPACE_MATRIX_COL 7

// LED pin definitions
#define BACKLIGHT_FROW_PIN E6   // F-keys
#define BACKLIGHT_ALPHA_PIN B1  // alphas
#define BACKLIGHT_NAV_PIN B2    // nav cluster
#define BACKLIGHT_MODNUM_PIN B3 // modifiers, bottom, and number row

#define INDICATOR_BAR_NUM_LEDS 5
#define INDICATOR_BAR_PIN D4
#define INDICATOR_BAR_MAX_BRIGHTNESS 50

#define DEBUG_MATRIX_SCAN_RATE

/* Bootmagic Lite key configuration */
// Backspace key, ie. the top right key in the main key cluster
#define BOOTMAGIC_LITE_ROW BACKSPACE_MATRIX_ROW
#define BOOTMAGIC_LITE_COLUMN BACKSPACE_MATRIX_COL
