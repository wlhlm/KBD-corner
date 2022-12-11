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
