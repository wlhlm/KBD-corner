// Copyright 2024 Wilhelm Schuster
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

static const uint8_t indicator_bar_all_off[INDICATOR_BAR_NUM_LEDS] = {0, 0, 0, 0, 0};

#ifdef INDICATOR_BAR_MAX_BRIGHTNESS
static const uint8_t indicator_bar_all_on[INDICATOR_BAR_NUM_LEDS] = {
    INDICATOR_BAR_MAX_BRIGHTNESS,
    INDICATOR_BAR_MAX_BRIGHTNESS,
    INDICATOR_BAR_MAX_BRIGHTNESS,
    INDICATOR_BAR_MAX_BRIGHTNESS,
    INDICATOR_BAR_MAX_BRIGHTNESS
};
#else
static const uint8_t indicator_bar_all_on[INDICATOR_BAR_NUM_LEDS] = {255, 255, 255, 255, 255};
#endif

void indicator_bar_setleds(const uint8_t *leds);

void indicator_bar_setleds_single(size_t led, uint8_t value);
