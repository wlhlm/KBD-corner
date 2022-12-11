/* Copyright 2022 Wilhelm Schuster
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

#include QMK_KEYBOARD_H
#include "indicator_bar.h"

/* The AVR WS2812 driver only supports a single chain for which the pin is
 * hardcoded at compile time. The following is a workaround by redefining the
 * pin and including (copying) the WS2812 driver. This works because the main
 * driving function is marked static and thus local to the translation unit.
 * Only ws2812_setleds has to be redefined as it would otherwise clash with the
 * function in the main driver. We give it a dummy name here. The same approach
 * is used by the work_louder keyboards.
 */
#undef RGB_DI_PIN
#define RGB_DI_PIN INDICATOR_BAR_PIN

#define ws2812_setleds dummy_ws2812_setleds

#include "ws2812.c"

static uint8_t indicator_leds[INDICATOR_BAR_NUM_LEDS] = {0, 0, 0, 0, 0};

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
