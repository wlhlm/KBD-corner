// Copyright 2024 Wilhelm Schuster
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

layer_state_t layer_state_set_kb(layer_state_t state) {
    uint8_t layer_num = get_highest_layer(state);
    if (layer_num < INDICATOR_BAR_NUM_LEDS) {
        indicator_bar_setleds(indicator_bar_all_off);
        indicator_bar_setleds_single(layer_num, 255);
    }

    return state;
}
