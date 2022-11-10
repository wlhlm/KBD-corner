/* Copyright 2022
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

// TODO decide between grave escape and Lwr+Escape

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    KM_BASE_LAYER,
    KM_LOWER_LAYER,
    KM_RAISE_LAYER,
	KM_TRI_LAYER
};

#define LOWER MO(KM_LOWER_LAYER)
#define RAISE MO(KM_RAISE_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ \ │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │Tab │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Enter│
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * │Shift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │Shft│
     * ├────┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼────┤
     * │Ctrl│GUI│Alt│         Space          │ Lwr│ Rse│
     * └────┴───┴───┴────────────────────────┴────┴────┘
     */
    [KM_BASE_LAYER] = LAYOUT_625_space(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             LOWER,   RAISE
    ),

    /* Function Layer 1 (Lower)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │ = │ ▴ │   │   │   │ [ │ ] │ ; │ ' │      │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * │      │ ◂ │ ▾ │ ▸ │NKT│   │   │   │   │   │    │
     * ├────┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼────┤
     * │    │   │   │        Backspace       │    │    │
     * └────┴───┴───┴────────────────────────┴────┴────┘
     */
    [KM_LOWER_LAYER] = LAYOUT_625_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        _______, KC_EQL,  KC_UP,   _______, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT,          _______,
        _______,          KC_LEFT, KC_DOWN, KC_RGHT, NK_TOGG, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            KC_BSPC,                            _______, _______
    ),

    /* Function Layer 2 (Raise)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Btl│F1 │F2 │F3 │F4 │F5 │F6 │   │Hom│PgU│   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │F7 │F8 │F9 │F10│F11│F12│   │End│PgD│      │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * │      │RGB│Mod│HuD│HuI│VaD│VaI│SaD│SaI│BLS│    │
     * ├────┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼────┤
     * │    │   │   │         Delete         │    │    │
     * └────┴───┴───┴────────────────────────┴────┴────┘
     */
    [KM_RAISE_LAYER] = LAYOUT_625_space(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_HOME, KC_PGUP, _______, _______,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_END,  KC_PGDN,          _______,
        _______,          RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, BL_STEP, _______,
        _______, _______, _______,                            KC_DEL,                             _______, _______
    ),

    /* Function Layer 3 (Tri)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │    │   │   │   │   │   │   │   │   │   │      │
     * ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * │      │   │   │   │   │   │   │   │   │   │    │
     * ├────┬─┴─┬─┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼────┤
     * │    │   │   │                        │    │    │
     * └────┴───┴───┴────────────────────────┴────┴────┘
     */
    [KM_TRI_LAYER] = LAYOUT_625_space(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______
    )
};

/* https://docs.qmk.fm/#/ref_functions?id=update_tri_layer_statestate-x-y-z
 * N.B. this will block KM_TRI_LAYER from ever being activated without
 * KM_LOWER_LAYER and KM_RAISE_LAYER being active since layer_state_set_user()
 * will always be called before activating a layer.
 *
 * TODO debug/console print active layers when layer_state_set is called.
 */
layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, KM_LOWER_LAYER, KM_RAISE_LAYER, KM_TRI_LAYER);
}

bool restore_backlight_on_wakeup = false;
void suspend_power_down_user(void) {
	if (is_backlight_enabled()) {
		restore_backlight_on_wakeup = true;
		backlight_disable();
	}
}

void suspend_wakeup_init_user(void) {
	if (restore_backlight_on_wakeup) {
		backlight_enable();
		restore_backlight_on_wakeup = false;
	}
}
