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

// This define helps vscode parse the file and provide intelisense
#define QMK_KEYBOARD_H "sofle.h"

#include QMK_KEYBOARD_H
#include "rotary.h"
#include "layers.h"
#include "underglow.h"

enum custom_keycodes {
    ROTARY_MODE_LEFT = SAFE_RANGE,
    ROTARY_MODE_RIGHT,
    KC_BML_ATILDE,
    KC_BML_OTILDE,
    KC_BML_GRAVE,
    KC_BML_ACUTE,
    KC_BML_HAT,
    KC_BML_TILDE,

    KC_BML_LAYERC_TAB,
    KC_BML_LAYERA_TAB,

    REPEAT
};

int left_rotary_current_mode = ROTARY_MODE_VERTICAL_SCROLL;
int right_rotary_current_mode = ROTARY_MODE_VOLUME;

#define _T KC_TRANSPARENT

#define KC_BML_TREMA RALT(KC_LBRC)

/*
- thumb keys have lalt on both sides, to allow for easier access to alt+(left side key) instead of twisting fingers on left.
- altgr is on symbol layer
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    REPEAT              , KC_1 , KC_2    , KC_3    , KC_4    , KC_5       ,                                             KC_6        , KC_7    , KC_8    , KC_9    , KC_0    , XXXXXXX       ,
    KC_ESC              , KC_Q , KC_W    , KC_E    , KC_R    , KC_T       ,                                             KC_Y        , KC_U    , KC_I    , KC_O    , KC_P    , KC_RBRC       ,
    MT(MOD_LSFT,KC_TAB) , KC_A , KC_S    , KC_D    , KC_F    , KC_G       ,                                             KC_H        , KC_J    , KC_K    , KC_L    , KC_BSLS , KC_BSPC       ,
    KC_LSFT             , KC_Z , KC_X    , KC_C    , KC_V    , KC_B       , KC_MS_BTN1         ,      KC_MUTE         , KC_N        , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , OSM(MOD_RSFT) ,
                                 KC_LCTL , KC_LALT , KC_LGUI , MO(_LOWER) , LT(_SYMBOL,KC_ENT) ,      LT(_NAV,KC_SPC) , MO(_SYMBOL) , KC_RCTL , KC_RGUI , KC_LALT
  ),

  [_HRMOD] = LAYOUT(
    _T , _T                 , _T                 , _T                 , _T                 , _T ,                _T , _T                 , _T                 , _T                 , _T                    , _T ,
    _T , _T                 , _T                 , _T                 , _T                 , _T ,                _T , _T                 , _T                 , _T                 , _T                    , _T ,
    _T , MT(MOD_LGUI, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LSFT, KC_D) , MT(MOD_LCTL, KC_F) , _T ,                _T , MT(MOD_RCTL, KC_J) , MT(MOD_RSFT, KC_K) , MT(MOD_LALT, KC_L) , MT(MOD_RGUI, KC_BSLS) , _T ,
    _T , _T                 , _T                 , _T                 , _T                 , _T , _T ,      _T , _T , _T                 , _T                 , _T                 , _T                    , _T ,
                              _T                 , _T                 , _T                 , _T , _T ,      _T , _T , _T                 , _T                 , _T
  ),

  [_COLEMAK] = LAYOUT(
    KC_GRV  , KC_1 , KC_2    , KC_3    , KC_4    , KC_5    ,                          KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_GRV  ,
    KC_ESC  , KC_Q , KC_W    , KC_F    , KC_P    , KC_G    ,                          KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSPC ,
    KC_TAB  , KC_A , KC_R    , KC_S    , KC_T    , KC_D    ,                          KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT ,
    KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B    , KC_MUTE ,      XXXXXXX , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                     KC_LGUI , KC_LALT , KC_LCTL , _______ , KC_ENT  ,      KC_SPC  , _______ , KC_RCTL , KC_RALT , KC_RGUI
  ),

  [_GAMING] = LAYOUT(
    KC_GRV              , KC_1 , KC_2    , KC_3    , KC_4    , KC_5   ,                               KC_6        , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS ,
    KC_ESC              , KC_Q , KC_W    , KC_E    , KC_R    , KC_T   ,                               KC_Y        , KC_U    , KC_I    , KC_O    , KC_P    , KC_RBRC ,
    MT(MOD_LSFT,KC_TAB) , KC_A , KC_S    , KC_D    , KC_F    , KC_G   ,                               KC_H        , KC_J    , KC_K    , KC_L    , KC_BSLS , KC_BSPC ,
    KC_LSFT             , KC_Z , KC_X    , KC_C    , KC_V    , KC_B   , TG(_GAMING) ,      KC_MUTE  , KC_N        , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                                 KC_LCTL , KC_LALT , KC_LCTL , KC_SPC , KC_ENT      ,      MO(_NAV) , MO(_SYMBOL) , KC_RCTL , KC_RGUI , KC_RALT
  ),

  [_LOWER] = LAYOUT(
    KC_DEL  , KC_F1   , KC_F2   , KC_F3         , KC_F4   , KC_F5   ,                          KC_F6       , KC_F7   , KC_F8      , KC_F9     , KC_F10     , KC_F11  ,
    KC_GRV  , KC_1    , KC_2    , KC_3          , KC_4    , KC_5    ,                          KC_6        , KC_7    , KC_8       , KC_9      , KC_0       , KC_F12  ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH       , KC_DLR  , KC_PERC ,                          KC_CIRC     , KC_AMPR , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______ ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2)) , KC_LCBR , KC_LBRC , _______ ,      _______ , KC_NUBS     , KC_RPRN , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , _______ ,
                        _______ , _______       , _______ , _______ , KC_SPC  ,      _______ , TT(_NUMPAD) , _______ , _______    , _______
  ),

  [_NAV] = LAYOUT(
    REPEAT  , XXXXXXX , XXXXXXX , XXXXXXX , A(KC_F4)        , XXXXXXX ,                          KC_APP  , XXXXXXX    , C(KC_UP)   , XXXXXXX    , XXXXXXX   , A(KC_F4)   ,
    _______ , KC_INS  , KC_PSCR , KC_PAUS , A(ALGR(KC_TAB)) , XXXXXXX ,                          KC_PGUP , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    _______ , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX         , XXXXXXX ,                          KC_PGDN , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , _______    ,
    _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V)         , XXXXXXX , _______ ,      _______ , XXXXXXX , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , _______    ,
                        _______ , _______ , _______         , _______ , _______ ,      _______ , KC_ENT  , _______    , _______    , _______
  ),

  [_SYMBOL] = LAYOUT(
    A(KC_F4)          , KC_F13        , KC_F14        , KC_F15        , KC_F16            , XXXXXXX      ,                          XXXXXXX       , KC_MPRV       , KC_MPLY      , KC_MNXT       , XXXXXXX , KC_EQL  ,
    KC_TAB            , KC_F17        , KC_F18        , A(ALGR(KC_E)) , KC_BML_LAYERA_TAB , KC_ASTR      ,                          A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE  , KC_LBRC , XXXXXXX ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN       , S(KC_COMM)        , S(KC_DOT)    ,                          A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN       , KC_QUOT , XXXXXXX ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN       , KC_BML_OTILDE     , KC_BML_TREMA , XXXXXXX ,      XXXXXXX , KC_NUBS       , S(KC_NUBS)    , KC_BML_HAT   , KC_BML_TILDE  , KC_SLSH , KC_RSFT ,
                                        _______       , _______       , _______           , TT(_NUMPAD)  , XXXXXXX ,      XXXXXXX , XXXXXXX       , _______       , _______      , OSM(MOD_RALT)
  ),

  [_NUMPAD] = LAYOUT(
    KC_BSPC , KC_UP   , KC_P7   , KC_P8   , KC_P9   , KC_PSLS     ,                          TG(_NUMPAD) , ROTARY_MODE_LEFT , ROTARY_MODE_RIGHT , RGB_TOG , KC_CAPS , KC_NLCK ,
    KC_LEFT , KC_RGHT , KC_P4   , KC_P5   , KC_P6   , KC_PAST     ,                          TG(_GAMING) , XXXXXXX          , XXXXXXX           , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_DEL  , KC_DOWN , KC_P1   , KC_P2   , KC_P3   , KC_PMNS     ,                          TG(_HRMOD)  , XXXXXXX          , XXXXXXX           , KC_INS  , KC_DEL  , KC_BSPC ,
    XXXXXXX , KC_COMM , KC_P0   , KC_PDOT , KC_PENT , KC_PPLS     , RESET   ,      XXXXXXX , XXXXXXX     , XXXXXXX          , XXXXXXX           , XXXXXXX , XXXXXXX , XXXXXXX ,
                        _______ , _______ , _______ , TT(_NUMPAD) , _______ ,      _______ , _______     , _______          , _______           , _______
  ),
};

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t repeat_last_keycode = KC_NO;
uint8_t repeat_last_modifier = 0;
uint8_t repeat_count = 0;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t repeat_mod_state;
uint8_t repeat_oneshot_mod_state;
bool repeat_is_counting = false;

bool process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        repeat_last_modifier = repeat_oneshot_mod_state > repeat_mod_state ? repeat_oneshot_mod_state : repeat_mod_state;

        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    repeat_last_keycode = GET_TAP_KC(keycode);
                }
                break;
            case KC_1 ... KC_9:
                if(repeat_is_counting && record->event.pressed){
                    repeat_count *= 10;
                    repeat_count += keycode - (KC_1-1);
                    return false;
                }
                break;
            case KC_0:
                if(repeat_is_counting && record->event.pressed){
                    repeat_count *= 10;
                    return false;
                }
                break;
            default:
                if(record->event.pressed){
                    repeat_last_keycode = keycode;
                }
            break;
        }
    } else { // keycode == REPEAT

        if (record->event.pressed) {
            repeat_is_counting = true;
            repeat_count=0;
        } else {
            repeat_is_counting = false;
            if(repeat_count>0){
                register_mods(repeat_last_modifier);
                for (size_t i = 0; i < repeat_count; i++)
                {
                    tap_code16(repeat_last_keycode);
                }
                unregister_mods(repeat_last_modifier);
            } else {
                register_mods(repeat_last_modifier);
                tap_code16(repeat_last_keycode);
                unregister_mods(repeat_last_modifier);
            }
        }
    }
    return true;
}


// this currently only supports control and alt. implementation can be slighly improved
uint8_t unpress_mod_on_layer_change = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool keep_processing = true;
    keep_processing = process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    repeat_mod_state = get_mods();
    repeat_oneshot_mod_state = get_oneshot_mods();

    if(!keep_processing){
        return false;
    }

    switch (keycode) {
    case ROTARY_MODE_LEFT:
        if (!record->event.pressed) {
            switch(left_rotary_current_mode){
            case ROTARY_MODE_HORIZONTAL_SCROLL:
                left_rotary_current_mode = ROTARY_MODE_VOLUME;
                break;
            default:
                left_rotary_current_mode += 1;
            }
        }
        break;
    case ROTARY_MODE_RIGHT:
        if (!record->event.pressed) {
            switch(right_rotary_current_mode){
            case ROTARY_MODE_HORIZONTAL_SCROLL:
                right_rotary_current_mode = ROTARY_MODE_VOLUME;
                break;
            default:
                right_rotary_current_mode += 1;
            }
        }
        break;
    case KC_BML_ATILDE:
        if(record->event.pressed)
            SEND_STRING(SS_TAP(X_BSLASH) SS_TAP(X_A));
        break;
    case KC_BML_OTILDE:
        if(record->event.pressed)
            SEND_STRING(SS_TAP(X_BSLASH) SS_TAP(X_O));
        break;
    case KC_BML_GRAVE:
        if(record->event.pressed)
            SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_RBRC) SS_UP(X_LSFT) SS_TAP(X_SPC));
        break;
    case KC_BML_ACUTE:
        if(record->event.pressed)
            SEND_STRING(SS_TAP(X_RBRC) SS_TAP(X_SPC));
        break;
    case KC_BML_HAT:
        if(record->event.pressed)
            SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_BSLS) SS_UP(X_LSFT) SS_TAP(X_SPC));
        break;
    case KC_BML_TILDE:
        if(record->event.pressed)
            SEND_STRING(SS_TAP(X_BSLS) SS_TAP(X_SPC));
        break;
    case KC_BML_LAYERC_TAB:
        if(record->event.pressed){
            if(!(get_mods() & MOD_MASK_CTRL)){
                register_code(KC_LCTRL);
                unpress_mod_on_layer_change |= MOD_BIT(KC_LCTRL);
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
    }
    return true;

};

void bml_set_layer_indicator(layer_state_t state){
    int highest_layer = get_highest_layer(state);
    if (highest_layer == 0)
        highest_layer = get_highest_layer(default_layer_state);

    switch (highest_layer)
    {
    case _NUMPAD:
        rgblight_sethsv_noeeprom(HSV_BLUE);
        break;
    case _GAMING:
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    case _LOWER:
    case _NAV:
    case _SYMBOL:
    default:
        rgblight_sethsv_noeeprom(HSV_WHITE);
        break;
    }
}

void keyboard_post_init_user(void){
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    rgblight_sethsv_noeeprom_white();
    bml_set_layer_indicator(default_layer_state);
}

layer_state_t default_layer_state_set_user(layer_state_t state){
    bml_set_layer_indicator(state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state){
    if (unpress_mod_on_layer_change & MOD_BIT(KC_LCTRL)){
        unregister_code(KC_LCTRL);
        unpress_mod_on_layer_change ^= MOD_BIT(KC_LCTRL);
    }
    if (unpress_mod_on_layer_change & MOD_BIT(KC_LALT)){
        unregister_code(KC_LALT);
        unpress_mod_on_layer_change ^= MOD_BIT(KC_LALT);
    }
    // if by any chance we switch to the numpad layer and numlock is off, turn it on
    if(IS_LAYER_ON_STATE(state, _NUMPAD)){
        led_t led_usb_state = host_keyboard_led_state();
        if(!led_usb_state.num_lock){
            tap_code(KC_NLCK);
        }
    }
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


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV,KC_SPC):
            return TAPPING_TERM + 350;
        default:
            return TAPPING_TERM;
    }
}
