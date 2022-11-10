/* Copyright 2022 DZTECH <moyi4681@Live.cn>
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

enum layer_names {
    KM_BASE_LAYER,
    KM_FUNCTION_LAYER
};

#define FN MO(KM_FUNCTION_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [KM_BASE_LAYER] = LAYOUT_tkl_f13_ansi_tsangan(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,     KC_PSCR, KC_SLCK, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        FN,      KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, KC_RGUI, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [KM_FUNCTION_LAYER] = LAYOUT_tkl_f13_ansi_tsangan(
        QK_BOOT, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, _______,    RGB_HUI, RGB_SAI, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______,    _______, _______, _______
    )

};

const key_override_t volume_up_override = ko_make_with_layers_negmods_and_options(
	MOD_MASK_SHIFT,                   // Trigger modifiers: ctrl
	KC_VOLU,                          // Trigger key: play/pause
	KC_MNXT,                          // Replacement key
	~0,                               // Activate on all layers
	MOD_MASK_CAG,                     // Do not activate when any modifier other than shift is pressed
	ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting shift

const key_override_t volume_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_VOLD,
	KC_MPRV, ~0, MOD_MASK_CAG, ko_option_no_reregister_trigger);

const key_override_t **key_overrides = (const key_override_t *[]){
    &volume_up_override,
    &volume_down_override,
    NULL
};
