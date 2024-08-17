// Copyright 2024 Wilhelm Schuster
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "indicator_bar.h"

/* The Orion V2 features a bar of 5 single color LEDs driven by a chain of two
 * WS2811 chips. This requires some hacking to make it work with the RGB
 * underglow on the AVR platform.
 *
 * The AVR WS2811/12 driver only supports a single chain for which the pin is
 * hardcoded at compile time. The following is a workaround by redefining the
 * pin and including (copying) the WS2812 driver. This works because the main
 * driving function is marked static and thus local to the translation unit.
 * Only ws2812_setleds has to be redefined as it would otherwise clash with the
 * function in the main driver. We give it a dummy name here. The same approach
 * is used by the work_louder keyboards.
 */
#undef WS2812_DI_PIN
#define WS2812_DI_PIN INDICATOR_BAR_PIN

#define ws2812_setleds dummy_ws2812_setleds

#include "ws2812_bitbang.c"

static uint8_t indicator_leds[INDICATOR_BAR_NUM_LEDS] = {0, 0, 0, 0, 0};

// Converts 5 individual brightness values to 2 RGB groups.
static void indicator_bar_showleds(void) {
    LED_TYPE indicator_leds_out[] = {{}, {}};

    // LED_TYPE is in GRB order
    indicator_leds_out[0].g = indicator_leds[0];
    indicator_leds_out[0].r = indicator_leds[1];
    indicator_leds_out[0].b = indicator_leds[2];
    indicator_leds_out[1].g = indicator_leds[3];
    indicator_leds_out[1].r = indicator_leds[4];

    ws2812_setleds(indicator_leds_out, 2);
}

void indicator_bar_setleds(const uint8_t *leds) {
    for (int8_t i = 0; i < INDICATOR_BAR_NUM_LEDS; i++) {
#ifdef INDICATOR_BAR_MAX_BRIGHTNESS
        indicator_leds[i] = MIN(leds[i], INDICATOR_BAR_MAX_BRIGHTNESS);
#else
        indicator_leds[i] = leds[i];
#endif
    }
    indicator_bar_showleds();
}

void indicator_bar_setleds_single(size_t led, uint8_t value) {
#ifdef INDICATOR_BAR_MAX_BRIGHTNESS
    indicator_leds[led] = MIN(value, INDICATOR_BAR_MAX_BRIGHTNESS);
#else
    indicator_leds[led] = value;
#endif
    indicator_bar_showleds();
}
