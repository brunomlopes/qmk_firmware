 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

//Sets up what the OLED screens display.
#define QMK_KEYBOARD_H "sofle.h"

#include QMK_KEYBOARD_H
#include "rotary.h"
#include "layers.h"

#ifdef OLED_DRIVER_ENABLE

static void print_rotary_mode(int8_t mode){
    switch(mode){
        case ROTARY_MODE_VOLUME:
            oled_write_P(PSTR("R vol"), false);
            break;
        case ROTARY_MODE_VERTICAL_MOVE:
            oled_write_P(PSTR("R m^ "), false);
            break;
        case ROTARY_MODE_HORIZONTAL_MOVE:
            oled_write_P(PSTR("R m<>"), false);
            break;
        case ROTARY_MODE_VERTICAL_SCROLL:
            oled_write_P(PSTR("R ^  "), false);
            break;
        case ROTARY_MODE_HORIZONTAL_SCROLL:
            oled_write_P(PSTR("R <> "), false);
            break;
        default:
            oled_write_P(PSTR("R ?  "), false);
    }
}

static void print_status_narrow(void) {
    // char status_buffer[7];
    int highest_layer = get_highest_layer(layer_state);
    // Print current mode
    oled_write_P(PSTR("\n"), false);

    switch (highest_layer) {
        case _BASE:
            oled_write_P(PSTR("Qwrt "), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Clmk "), false);
            break;
        default:
            oled_write_P(PSTR("Mod  "), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_P(PSTR("_ "), false);
    oled_write_char('0' + highest_layer, false);
    oled_write_P(PSTR(" _"), false);
    switch (highest_layer) {
        case _BASE:
        case _COLEMAK:
            oled_write_P(PSTR("base "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("lower"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("nav  "), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("symbl"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("numpd"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("game "), false);
            break;
        default:
            oled_write_P(PSTR("undef"), false);
    }
    print_rotary_mode(left_rotary_current_mode);
    print_rotary_mode(right_rotary_current_mode);
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("NMLCK"), led_usb_state.num_lock);

}

static void print_status_narrow_right(void) {
    print_rotary_mode(right_rotary_current_mode);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_status_narrow_right();
    }
}

#endif
