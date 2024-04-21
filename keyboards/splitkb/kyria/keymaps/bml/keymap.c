/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

enum layers {
  _BASE,
  _LOWER,
  _LOWER_MAC,
  _LOWERFN,
  _LEFTFN,
  _NAV,
  _SYMBOL,
  _SYMBOL_MAC,
  _MACRO,
  _NUMPAD,
  _NUMPADALT,
  _META
};


enum custom_keycodes {
    KC_BML_ATILDE = SAFE_RANGE,
    KC_BML_OTILDE,
    KC_BML_GRAVE,
    KC_BML_ACUTE,
    KC_BML_HAT,
    KC_BML_TILDE,

    KC_BML_FLAYER_FA,

    KC_BML_LAYERC_TAB,
    KC_BML_LAYERA_TAB,

    KC_BML_TOGGLE_SPUNDERSCORE,
    KC_BML_TOGGLE_SPSHIFT,

    KC_BML_DOUBLE_CTRL,
    KC_BML_SHOW_OS
};

#define KC_BML_TREMA RALT(KC_LBRC)

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    MT(MOD_LALT, KC_ESC) , KC_Q , KC_W , KC_E    , KC_R               , KC_T                 ,                                                                         KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_RBRC               ,
    MT(MOD_LCTL, KC_TAB) , KC_A , KC_S , KC_D    , LT(_LOWERFN, KC_F) , LT(_NUMPADALT, KC_G) ,                                                                         KC_H    , KC_J    , KC_K    , KC_L   , KC_ENT  , MT(MOD_LCTL, KC_BSPC) ,
    KC_LSFT              , KC_Z , KC_X , KC_C    , KC_V               , KC_B                 , MO(_META)  , _______            ,      _______          , MO(_MACRO)   , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT               ,
                                         _______ , _______            , KC_LGUI              , MO(_LOWER) , LT(_MACRO, KC_ENT) ,      LT(_NAV, KC_SPC) , MO(_SYMBOL) , KC_LALT , _______ , _______
  ),

  [_LOWER] = LAYOUT(
    KC_BSPC , KC_1    , KC_2    , KC_3          , KC_4    , KC_5    ,                                                KC_6    , KC_7    , KC_8       , KC_9      , KC_0       , KC_F12  ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH       , KC_DLR  , KC_PERC ,                                                KC_CIRC , KC_AMPR , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______ ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2)) , KC_LCBR , KC_LBRC , _______ , _______ ,      _______ , _______   , KC_NUBS , KC_RPRN , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , _______ ,
                                  _______       , _______ , KC_LCTL , _______ , KC_SPC  ,      _______ , MO(_META) , _______ , _______ , _______
  ),

  [_LOWER_MAC] = LAYOUT(
    _______ , _______ , _______ , _______ , _______   , _______ ,                                              _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______   , _______ ,                                              _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , S(KC_EQL) , KC_EQL  , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                  _______ , _______   , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______
  ),

  [_LOWERFN] = LAYOUT(
    KC_DEL  , KC_F1            , KC_F2   , KC_F3   , KC_F4   , KC_F5    ,                                              KC_F6  , KC_F7   , KC_F8   , KC_F9 , KC_F10 , KC_F11 ,
    KC_BSPC , KC_BML_FLAYER_FA , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,                                              KC_1   , KC_2    , KC_3    , KC_4  , KC_5   , KC_F12 ,
    KC_TAB  , XXXXXXX          , XXXXXXX , XXXXXXX , XXXXXXX , A(KC_F4) , _______ , _______ ,      _______ , _______ , KC_6   , KC_7    , KC_8    , KC_9  , KC_0   , KC_DOT ,
                                           _______ , XXXXXXX , _______  , _______ , _______ ,      KC_BSPC , KC_DEL  , KC_TAB , _______ , _______
  ),

  [_NUMPADALT] = LAYOUT(
    XXXXXXX , KC_BSPC , KC_7 , KC_8    , KC_9    , XXXXXXX ,                                              KC_BSPC , KC_7    , KC_8    , KC_9 , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_TAB  , KC_4 , KC_5    , KC_6    , XXXXXXX ,                                              KC_TAB  , KC_4    , KC_5    , KC_6 , XXXXXXX , KC_BSPC ,
    XXXXXXX , KC_0    , KC_1 , KC_2    , KC_3    , KC_DOT  , _______ , _______ ,      _______ , _______ , KC_0    , KC_1    , KC_2    , KC_3 , KC_DOT  , XXXXXXX ,
                               _______ , _______ , KC_DOT  , KC_COMM , KC_BSPC ,      XXXXXXX , KC_DOT  , KC_COMM , _______ , _______
  ),

  [_NAV] = LAYOUT(
    _______ , KC_INS  , KC_PAUS , KC_APP  , A(KC_F4)        , KC_BTN5 ,                                                 KC_PGUP , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    _______ , XXXXXXX , XXXXXXX , KC_PSCR , A(ALGR(KC_TAB)) , KC_BTN4 ,                                                 KC_PGDN , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , KC_BSPC    ,
    _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V)         , XXXXXXX , _______ , _______ ,      _______ , _______    , XXXXXXX , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , _______    ,
                                  _______ , _______         , _______ , _______ , _______ ,      _______ , MO(_MACRO) , _______ , _______    , _______
  ),

  [_SYMBOL] = LAYOUT(
    // |      TAB       |   F17   |    F18     | ALGR(E) | BML_LAYERA_TAB |    F20                          |                           | ALGR(8) | ALGR(9) | BML_ACUTE | BML_GRAVE |            {            |      XXXXXXX       |
    // | BML_LAYERC_TAB | ALGR(2) |  XXXXXXX   |    :    |      S(,)      |   S(.)                          |                           | ALGR(7) | ALGR(0) |   ASTR    |     (     |            '            |         \          |
    // |      LSFT      | XXXXXXX | BML_ATILDE |    ;    |   BML_OTILDE   | BML_TREMA |  _______  | _______ |    |  _______   | _______ |    \    |  S(\)   |  BML_HAT  | BML_TILDE | BML_TOGGLE_SPUNDERSCORE | BML_TOGGLE_SPSHIFT |
    //                                         | _______ |    _______     |  _______  | MO(_META) | _______ |    | MO(_MACRO) | _______ | _______ | _______ |  _______  |

    KC_TAB            , KC_F17        , KC_F18        , A(ALGR(KC_E)) , KC_BML_LAYERA_TAB , KC_F20       ,                                                   A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE , KC_LBRC                    , XXXXXXX               ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN       , S(KC_COMM)        , S(KC_DOT)    ,                                                   A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN      , KC_QUOT                    , KC_BSLS               ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN       , KC_BML_OTILDE     , KC_BML_TREMA , _______   , _______ ,      _______    , _______ , KC_NUBS       , S(KC_NUBS)    , KC_BML_HAT   , KC_BML_TILDE , KC_BML_TOGGLE_SPUNDERSCORE , KC_BML_TOGGLE_SPSHIFT ,
                                                        _______       , _______           , _______      , MO(_META) , _______ ,      MO(_MACRO) , _______ , _______       , _______       , _______
  ),

  [_SYMBOL_MAC] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                              _______    , _______    , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                              A(S(KC_8)) , A(S(KC_9)) , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______    , _______    , _______ , _______ , _______ , _______ ,
                                  _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______    , _______    , _______
  ),

  [_MACRO] = LAYOUT(
    A(KC_F4)           , KC_F13  , KC_F14  , KC_F15  , KC_F16            , KC_F19          ,                                              KC_AUDIO_VOL_UP   , KC_MPRV , KC_MPLY , KC_MNXT , _______ , _______ ,
    KC_BML_LAYERC_TAB  , KC_F17  , KC_F18  , KC_WH_U , KC_BML_LAYERA_TAB , KC_F20          ,                                              KC_AUDIO_VOL_DOWN , _______ , _______ , _______ , _______ , _______ ,
    KC_BML_DOUBLE_CTRL , XXXXXXX , KC_PSCR , KC_WH_D , XXXXXXX           , KC_AUDIO_MUTE   , _______ , _______ ,      _______ , _______ , KC_AUDIO_MUTE     , _______ , _______ , _______ , _______ , _______ ,
                                             _______ , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , _______ , _______ ,      _______ , _______ , _______           , _______ , _______
  ),

  [_META] = LAYOUT(
    QK_BOOTLOADER  , _______ , _______ , _______ , _______ , _______ ,                                              _______ , _______ , _______ , _______ , _______  , QK_REBOOT ,
    KC_BML_SHOW_OS , _______ , _______ , _______ , _______ , _______ ,                                              RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD  , _______   ,
    _______        , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , RGB_SAD , RGB_HUD , RGB_VAD , RGB_RMOD , _______   ,
                                         _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______
  ),

};

#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

// this currently only supports control and alt. implementation can be slighly improved
uint8_t unpress_mod_on_layer_change = 0;
uint8_t mod_state;

bool is_caps_word_on_mode = false;
bool is_bml_spunderscore_active = false;
bool is_bml_spshift_active = false;

#define TAP_HEX_CODE4(a,b,c,d) register_code(KC_LALT);tap_code(a);tap_code(b);tap_code(c);tap_code(d);unregister_code(KC_LALT);
#define TAP_HEX_CODE2(a,b) register_code(KC_LALT);tap_code(a);tap_code(b);unregister_code(KC_LALT);

layer_state_t layer_state_add_paired(layer_state_t state, uint8_t original_layer, uint8_t paired_layer){
    if(IS_LAYER_ON_STATE(state, original_layer)){
        state = state | ((layer_state_t)1 << paired_layer);
    }else{
        state = state &  ~((layer_state_t)1 << paired_layer);
    }
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state){

    if (unpress_mod_on_layer_change & MOD_BIT(KC_LCTL)){
        unregister_code(KC_LCTL);
        unpress_mod_on_layer_change ^= MOD_BIT(KC_LCTL);
    }
    if (unpress_mod_on_layer_change & MOD_BIT(KC_LALT)){
        unregister_code(KC_LALT);
        unpress_mod_on_layer_change ^= MOD_BIT(KC_LALT);
    }
    // if by any chance we switch to the numpad layer and numlock is off, turn it on
    if(IS_LAYER_ON_STATE(state, _NUMPAD)){
        led_t led_usb_state = host_keyboard_led_state();
        if(!led_usb_state.num_lock){
            tap_code(KC_NUM);
        }
    }

    os_variant_t detected_os = detected_host_os();

    if(detected_os == OS_MACOS||detected_os == OS_IOS){
        state = layer_state_add_paired(state, _LOWER, _LOWER_MAC);
        state = layer_state_add_paired(state, _SYMBOL, _SYMBOL_MAC);
    }

    return state;
}

// {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    os_variant_t detected_os = detected_host_os();

    switch (keycode) {
    case KC_BML_FLAYER_FA:
        if(record->event.pressed)
            SEND_STRING(SS_TAP(X_F) SS_TAP(X_A));
        break;
    case KC_BML_DOUBLE_CTRL:
        if (record->event.pressed) {
            tap_code16(KC_LCTL);
            tap_code16(KC_LCTL);
        }
        break;
    case KC_BML_ATILDE:
        if (record->event.pressed) {
            if (mod_state && MOD_MASK_SHIFT) {
                TAP_HEX_CODE4(KC_KP_0,KC_KP_1,KC_KP_9,KC_KP_5);
            }else{
                TAP_HEX_CODE4(KC_KP_0,KC_KP_2,KC_KP_2,KC_KP_7);
            }
        }
        break;
    case KC_BML_OTILDE:
        if(record->event.pressed) {
            if (mod_state && MOD_MASK_SHIFT) {
                TAP_HEX_CODE4(KC_KP_0,KC_KP_2,KC_KP_1,KC_KP_3);
            }else{
                TAP_HEX_CODE4(KC_KP_0,KC_KP_2,KC_KP_4,KC_KP_5);
            }
        }
        break;
    case KC_BML_GRAVE:
        if(record->event.pressed) {
            TAP_HEX_CODE2(KC_KP_9,KC_KP_6);
        }
        break;
    case KC_BML_ACUTE:
        if(record->event.pressed){
            TAP_HEX_CODE4(KC_KP_0,KC_KP_1,KC_KP_8,KC_KP_0);
        }
        break;
    case KC_BML_HAT:
        if(record->event.pressed){
            TAP_HEX_CODE2(KC_KP_9,KC_KP_4);
        }
        break;
    case KC_BML_TILDE:
        if(record->event.pressed){
            // right, this does not work, with the shift
            if (mod_state && MOD_MASK_SHIFT) {
                TAP_HEX_CODE4(KC_KP_0,KC_KP_1,KC_KP_5,KC_KP_2);
            }else{
                TAP_HEX_CODE4(KC_KP_0,KC_KP_1,KC_KP_2,KC_KP_6);
            }
        }
        break;
    case KC_BML_LAYERC_TAB:
        if(record->event.pressed){
            if(!(get_mods() & MOD_MASK_CTRL)){
                register_code(KC_LCTL);
                unpress_mod_on_layer_change |= MOD_BIT(KC_LCTL);
            }
            tap_code(KC_TAB);
        }
        break;
    case KC_BML_LAYERA_TAB:
        if(record->event.pressed){
            if(!(get_mods() & MOD_MASK_ALT)){
                register_code(KC_LALT);
                unpress_mod_on_layer_change |= MOD_BIT(KC_LALT);
            }
            tap_code(KC_TAB);
        }
        break;
    case KC_BML_SHOW_OS:
        if(record->event.pressed){
            switch (detected_os)
            {
            case OS_UNSURE:
                SEND_STRING("OS detection: UNSURE\n");
                break;
            case OS_MACOS:
                SEND_STRING("OS detection: OSX\n");
                break;
            case OS_WINDOWS:
                SEND_STRING("OS detection: WINDOWS\n");
                break;
            case OS_LINUX:
                SEND_STRING("OS detection: LINUX\n");
                break;
            case OS_IOS:
                SEND_STRING("OS detection: IOS\n");
                break;
            default:
                SEND_STRING("OS detection: unknown:'");
                send_byte(detected_os);
                SEND_STRING("' \n");
                break;
            }
        }
    case LT(_NAV,KC_SPC):
        if(is_bml_spunderscore_active && record->tap.count && record->event.pressed){
            tap_code16(S(KC_SLSH));
            return false; // ignore the rest
        }
        if(is_bml_spshift_active && record->tap.count && record->event.pressed){
            set_oneshot_mods(MOD_BIT(KC_RSFT));
            return false; // ignore the rest
        }
        break;
    case KC_BML_TOGGLE_SPUNDERSCORE:
        if(record->event.pressed){
            is_bml_spunderscore_active = !is_bml_spunderscore_active;
        }
        break;
    case KC_BML_TOGGLE_SPSHIFT:
        if(record->event.pressed){
            is_bml_spshift_active = !is_bml_spshift_active;
        }
        break;
    }
    return true;
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV,KC_SPC):
        case LT(_LOWERFN,KC_F):
        case LT(_LOWERFN,KC_G):
        case LT(_LEFTFN,KC_G):
        case LT(_SYMBOL,KC_ENT):
            return TAPPING_TERM + 350;
        default:
            return TAPPING_TERM;
    }
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */
#ifndef OLED_ENABLE
#define OLED_ENABLE
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void suspend_power_down_user(void) {
    oled_off();
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev3.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _BASE:
                oled_write_P(PSTR("base\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("lower\n"), false);
                break;
            case _LOWER_MAC:
                oled_write_P(PSTR("lower mac\n"), false);
                break;
            case _LOWERFN:
                oled_write_P(PSTR("lower fn\n"), false);
                break;
            case _LEFTFN:
                oled_write_P(PSTR("left fn\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("nav\n"), false);
                break;
            case _SYMBOL:
                oled_write_P(PSTR("symbol\n"), false);
                break;
            case _SYMBOL_MAC:
                oled_write_P(PSTR("symbol mac\n"), false);
                break;
            case _MACRO:
                oled_write_P(PSTR("macro\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("numpad\n"), false);
                break;
            case _NUMPADALT:
                oled_write_P(PSTR("numpad alt\n"), false);
                break;
            case _META:
                oled_write_P(PSTR("meta\n"), false);
                break;
            default:
                oled_write_P(PSTR("undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
