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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.
#define QMK_KEYBOARD_H "sofle.h"

#include QMK_KEYBOARD_H
#include "rotary.h"
#include "layers.h"

#ifdef ENCODER_ENABLE

#define THRICE(X) X; X; X;

void encoder_update_user(uint8_t index, bool clockwise) {
    int* current_mode_pointer = &left_rotary_current_mode;

    if (index == 1) {
        current_mode_pointer = &right_rotary_current_mode;
    }

    // shift+encoder changes the encoder mode
    if ( get_mods() & MOD_MASK_SHIFT ){
        if(clockwise){
            switch (*current_mode_pointer)
            {
            case ROTARY_MODE_HORIZONTAL_SCROLL:
                *current_mode_pointer = ROTARY_MODE_VOLUME;
                break;

            default:
                *current_mode_pointer += 1;
                break;
            }
        }else{
            switch (*current_mode_pointer)
            {
            case ROTARY_MODE_VOLUME:
                *current_mode_pointer = ROTARY_MODE_HORIZONTAL_SCROLL;
                break;

            default:
                *current_mode_pointer -= 1;
                break;
            }
        }
        return;
    }

    // Sometimes the cursor sticks in front of the text,
    // this gives me an easy way to get the mouse out of the way on the symbol layer.
    if(IS_LAYER_ON(ROTARY_MOUSE_MODE_LAYER)){
        if (index == 0){
            if (clockwise) {
                THRICE(tap_code(KC_MS_RIGHT));
            } else {
                THRICE(tap_code(KC_MS_LEFT));
            }
        }
        else{
            if (clockwise) {
                THRICE(tap_code(KC_MS_UP));
            } else {
                THRICE(tap_code(KC_MS_DOWN));
            }
        }
        return;
    }

    switch(*current_mode_pointer) {
        case ROTARY_MODE_VOLUME:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case ROTARY_MODE_VERTICAL_MOVE:
            if (clockwise) {
                tap_code(KC_MS_UP);
            } else {
                tap_code(KC_MS_DOWN);
            }
            break;
        case ROTARY_MODE_HORIZONTAL_MOVE:
            if (clockwise) {
                tap_code(KC_MS_RIGHT);
            } else {
                tap_code(KC_MS_LEFT);
            }
            break;
        case ROTARY_MODE_VERTICAL_SCROLL:
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
            break;
        case ROTARY_MODE_HORIZONTAL_SCROLL:
            if (clockwise) {
                tap_code(KC_MS_WH_RIGHT);
            } else {
                tap_code(KC_MS_WH_LEFT);
            }
            break;
    }
}

#endif
