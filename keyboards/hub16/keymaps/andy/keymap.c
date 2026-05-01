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
            KC_MUTE,                      KC_MPLY,
    KC_ESC,        KC_ENT,        KC_TAB,         MO(1),
    KC_F1,         KC_F2,         KC_F3,          KC_F4,
    KC_F21,        KC_F22,        KC_F23,         KC_F24,
    KC_LEFT,       KC_DOWN,       KC_UP,          KC_RGHT
  ),

  [1] = LAYOUT(
            _______,                      _______,
    QK_BOOT,       _______,       RGB_TOG,        _______,
    _______,       _______,       _______,        _______,
    _______,       _______,       _______,        _______,
    RGB_RMOD,      RGB_VAD,       RGB_VAI,        RGB_MOD
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left Encoder */
		switch(biton32(layer_state)){
			case 1:
				if (clockwise){
					rgblight_increase_hue();
				} else {
					rgblight_decrease_hue();
				}
				break;
			default:
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				}
				break;
			}
		}
    else if (index == 1) { /* Right Encoder */
		switch(biton32(layer_state)){
			case 1:
				if (clockwise){
					rgblight_increase_sat();
				} else{
					rgblight_decrease_sat();
				}
				break;
			default:
				if (clockwise) {
					tap_code(KC_MNXT);
				} else {
					tap_code(KC_MPRV);
				}
				break;
			}
		}
    return true;
}
