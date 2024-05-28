/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

#define KC_NLCK KC_NUM_LOCK

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,                       KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      MO(3),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_MINS,                        KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_GRV, KC_MUTE,      RGB_TOG, KC_DEL,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
      KC_LCTL, KC_LALT, KC_LGUI, KC_APP, MO(1),       KC_SPC,   KC_ENT,           KC_ENT,   KC_SPC,  MO(2),    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

	[1] = LAYOUT(
      _______, KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,                                KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11,
      KC_PSLS, KC_P7, KC_P8, KC_P9, KC_NLCK, _______, _______,                   _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_F12,
      KC_CAPS, KC_P4, KC_P5, KC_P6, KC_NLCK, _______, _______,                   _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_NLCK,
      _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______,  _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______,
      _______, KC_P0, KC_PDOT, KC_PENT, _______,     _______,  _______,   _______,    _______,   _______, KC_P0, KC_PDOT, KC_PENT, _______
      ),

	[2] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      KC_PSLS, KC_P7, KC_P8, KC_P9, KC_NLCK, _______, _______,                    _______, _______, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_F12,
      KC_CAPS, KC_P4, KC_P5, KC_P6, KC_NLCK, _______, _______,                    _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_NLCK,
      _______, KC_P1, KC_P2, KC_P3, _______, _______, _______, _______,  _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______,
      _______, KC_P0, KC_PDOT, KC_PENT, _______,    _______,   _______,  _______,    _______,    _______, KC_P0, KC_PDOT, KC_PENT, _______
      ),

	[3] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,                     _______, _______, _______, _______, _______, _______, KC_F12,
      _______, RGB_TOG, _______, _______, _______, _______, KC_F12,                   _______, _______, RGB_TOG, _______, _______, _______, _______,
      _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
      _______, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD,      RGB_VAD,     _______, _______,     _______,      RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
      )

};

void bml_set_layer_indicator(layer_state_t state){
    int highest_layer = get_highest_layer(state);
    if (highest_layer == 0)
        highest_layer = get_highest_layer(default_layer_state);

    switch (highest_layer)
    {
    case _MACRO:
        rgblight_sethsv_noeeprom(HSV_CYAN);
        break;
    case _NUMPAD:
        rgblight_sethsv_noeeprom(HSV_GREEN);
        break;
    case _GAMING:
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_sethsv_at(HSV_WHITE, 9);
        rgblight_sethsv_range(HSV_WHITE, 15, 18);
        break;
    case _MIX:
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        break;
    case _NAV:
        rgblight_sethsv_noeeprom(HSV_ORANGE);
    case _WAT:
    default:
        rgblight_sethsv_noeeprom(HSV_WHITE);
        break;
    }
}

layer_state_t default_layer_state_set_user(layer_state_t state){
    bml_set_layer_indicator(state);
    return state;
}

void keyboard_post_init_user(void){
    #ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    rgblight_sethsv_noeeprom(HSV_WHITE);

    #endif
    bml_set_layer_indicator(default_layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state){

    bml_set_layer_indicator(state);
    return state;
}


void suspend_wakeup_init_user(void) {
    bml_set_layer_indicator(default_layer_state);

    oled_on();
}

void suspend_power_down_user(void){
    oled_off();
}
