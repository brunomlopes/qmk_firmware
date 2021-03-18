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

#define QMK_KEYBOARD_H "sofle.h"

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

enum layers {
 _BASE,
 _COLEMAK,
 _LOWER,
 _NAV,
 _SYMBOL,
 _NUMPAD
};

#define SPC_FN3 LT(_NAV,KC_SPC)

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */


[_BASE] = LAYOUT(
 KC_GRV                 , KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6,  KC_7, KC_8,    KC_9 ,   KC_0,    KC_MINS,
 KC_ESC                 , KC_Q, KC_W, KC_E, KC_R, KC_T,                             KC_Y,  KC_U, KC_I,    KC_O ,   KC_P,    KC_RBRC,
 MT(MOD_LSFT,KC_TAB)    , KC_A, KC_S, KC_D, KC_F, KC_G,                             KC_H,  KC_J, KC_K,    KC_L ,   KC_BSLS, KC_BSPC,
 KC_LSFT                , KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MS_BTN1,        KC_MUTE, KC_N,  KC_M, KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER,KC_BSPC), LT(_SYMBOL,KC_ENT),    SPC_FN3,  MO(_SYMBOL), KC_RCTL, KC_RGUI ,KC_RALT),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
    KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
    KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX, KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                    KC_LGUI,KC_LALT,KC_LCTRL, KC_TRNS, KC_ENT,      KC_SPC,  KC_TRNS, KC_RCTRL, KC_RALT, KC_RGUI
),

[_LOWER] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_F12,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN, KC_PIPE,
    KC_TRNS, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,      KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN,  KC_COLN,  KC_BSLS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, TT(_NUMPAD),  KC_TRNS,  KC_TRNS, KC_TRNS
),


[_NAV] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                       KC_TRNS,KC_TRNS,    C(KC_UP),   KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_INS,  KC_PSCR, KC_PAUS, A(ALGR(KC_TAB)), KC_NO,                         KC_PGUP,KC_HOME,    KC_UP,      KC_END,     KC_NO,   KC_NO,
    KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,           KC_CAPS,                       KC_PGDN,KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_DEL,  KC_BSPC,
    KC_TRNS, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),         KC_INS, KC_TRNS,       KC_TRNS,KC_NO,  C(KC_LEFT), C(KC_DOWN), C(KC_RGHT), KC_NO,   KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,    KC_TRNS
),


[_SYMBOL] = LAYOUT(
    KC_GRV,  KC_F13,        KC_F14,  KC_F15,        KC_F16,        KC_NO,                          KC_NO,         KC_MPRV,       KC_MPLY, KC_MNXT,  KC_MINS, KC_EQL,
    KC_TAB,  KC_F17,        KC_F18,  A(ALGR(KC_E)), KC_ASTR,       KC_ASTR,                        KC_LPRN,       KC_LPRN,       KC_NO,   KC_NO,    KC_LBRC, KC_RBRC,
    KC_NO,   A(ALGR(KC_2)), KC_AT,   KC_COLN,       A(ALGR(KC_7)), A(ALGR(KC_8)),                  A(ALGR(KC_9)), A(ALGR(KC_0)), KC_ASTR, KC_LPRN,  KC_QUOT, KC_BSLS,
    KC_LSFT, KC_NUBS,       KC_NO,   KC_SCLN,       KC_NO,         KC_NUBS,       KC_NO,    KC_NO, S(KC_NUBS),    KC_LPRN,       KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
                            KC_TRNS, KC_TRNS,       KC_TRNS,       TT(_NUMPAD),   KC_NO,    KC_NO, KC_NO,         KC_TRNS,       KC_TRNS, KC_TRNS
),

[_NUMPAD] = LAYOUT(
    KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PSLS,                      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PAST,                      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
    KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PMNS,                      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_BSPC,
    KC_NO,   KC_NO,   KC_P0,   KC_PDOT, KC_PENT, KC_PPLS, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, TT(_NUMPAD), KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};
