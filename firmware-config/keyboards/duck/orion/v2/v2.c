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

#include "v2.h"

#include "indicator_bar.h"

layer_state_t layer_state_set_kb(layer_state_t state) {
	uint8_t layer_num = get_highest_layer(state);
	if (layer_num < INDICATOR_BAR_NUM_LEDS) {
		indicator_bar_setleds(indicator_bar_all_off);
		indicator_bar_setleds_single(layer_num, 255);
	}

	return state;
}
