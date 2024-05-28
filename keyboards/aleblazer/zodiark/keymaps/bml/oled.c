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

#ifdef OLED_ENABLE

#include "layers.h"

static void print_status_narrow(void) {
    // Print current layer
    oled_write_P(PSTR("L "), false);
    switch (get_highest_layer(layer_state)) {
        case _MACRO:
            oled_write_P(PSTR("|  0  |"), false);
            oled_write_P(PSTR(" Macro      "), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("|  1  |"), false);
            oled_write_P(PSTR(" Numberpad  "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("|  2  |"), false);
            oled_write_P(PSTR(" Nav        "), false);
            break;
        case _MIX:
            oled_write_P(PSTR("|  3  |"), false);
            oled_write_P(PSTR(" Mix        "), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("|  4  |"), false);
            oled_write_P(PSTR(" Gaming     "), false);
            break;
        case _WAT:
            oled_write_P(PSTR("|  5  |"), false);
            oled_write_P(PSTR(" ?          "), false);
            break;
        default:
            oled_write_P(PSTR("|  ?  |"), false);
            oled_write_P(PSTR(" Undef      "), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_P(PSTR(" | "), false);
    oled_write_P(PSTR("NUMLK"), led_usb_state.num_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        //render_logo();
    }
    return false;
}

#endif
