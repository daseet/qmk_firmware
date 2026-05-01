/* Copyright 2019 Josh Johnson
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
           KC_ESC,                      KC_ENT,
    KC_E,          KC_R,          KC_U,           KC_I,
    KC_D,          KC_F,          KC_J,           KC_K,
    KC_LEFT,       KC_DOWN,       KC_UP,          KC_RGHT,
    KC_ENT,        KC_C,          KC_M,           MO(1)
  ),

  [1] = LAYOUT(
            _______,                      _______,
    QK_BOOT,       _______,       RGB_TOG,        _______,
    _______,       _______,       _______,        _______,
    RGB_RMOD,      _______,       _______,        RGB_MOD,
    _______,       RGB_VAD,       RGB_VAI,        _______
  ),
};

bool encoder_update_user(uint8_t index, bool anticlockwise) {
    if (index == 0) { /* Left Encoder */
		switch(biton32(layer_state)){
			case 1:
				if (anticlockwise){
					rgblight_decrease_hue();
				} else {
					rgblight_increase_hue();
				}
				break;
			default:
				if (anticlockwise) {
					tap_code(KC_Q);
				} else {
					tap_code(KC_W);
				}
				break;
			}
		}
    else if (index == 1) { /* Right Encoder */
		switch(biton32(layer_state)){
			case 1:
				if (anticlockwise){
					rgblight_decrease_sat();
				} else {
					rgblight_increase_sat();
				}
				break;
			default:
				if (anticlockwise) {
					tap_code(KC_O);
				} else {
					tap_code(KC_P);
				}
				break;
			}
		}
    return false;
}
