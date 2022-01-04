/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
    _ADJUST_PLUS
};


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


#define _T KC_TRANSPARENT

#define KC_BML_TREMA RALT(KC_LBRC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    MT(MOD_LALT, KC_ESC) , KC_Q , KC_W , KC_E , KC_R    , KC_T       ,                     KC_Y       , KC_U    , KC_I    , KC_O   , KC_P    , MT(MOD_LALT, KC_RBRC) ,
    MT(MOD_LCTL, KC_TAB) , KC_A , KC_S , KC_D , KC_F    , KC_G       ,                     KC_H       , KC_J    , KC_K    , KC_L   , KC_ENT  , MT(MOD_LCTL, KC_BSPC) ,
    KC_LSFT              , KC_Z , KC_X , KC_C , KC_V    , KC_B       ,                     KC_N       , KC_M    , KC_COMM , KC_DOT , KC_SLSH , OSM(MOD_RSFT)         ,
                                                KC_LCTL , MO(_LOWER) , LT(_NAV,KC_SPACE) , MO(_RAISE) , KC_LALT
  ),

  [_LOWER] = LAYOUT_reviung41(
    KC_BSPC , KC_1    , KC_2    , KC_3          , KC_4    , KC_5    ,          KC_6    , KC_7    , KC_8       , KC_9      , KC_0       , KC_F12  ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH       , KC_DLR  , KC_PERC ,          KC_CIRC , KC_AMPR , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______ ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2)) , KC_LCBR , KC_LBRC ,          KC_NUBS , KC_RPRN , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , _______ ,
                                                  _______ , _______ , KC_ENT , _______ , _______
  ),

  [_RAISE] = LAYOUT_reviung41(
    KC_TAB            , XXXXXXX       , XXXXXXX       , A(ALGR(KC_E)) , KC_BML_LAYERA_TAB , XXXXXXX      ,            A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE , KC_LBRC , XXXXXXX ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN       , S(KC_COMM)        , S(KC_DOT)    ,            A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN      , KC_QUOT , KC_BSLS ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN       , KC_BML_OTILDE     , KC_BML_TREMA ,            KC_NUBS       , S(KC_NUBS)    , KC_BML_HAT   , KC_BML_TILDE , KC_SLSH , KC_RSFT ,
                                                                        _______           , _______      , KC_SPACE , _______       , _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RESET   , KC_INS  , KC_PSCR , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_DEL ,
    _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS ,           KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6  ,
    _______ , KC_ESC  , KC_RGUI , KC_RALT , KC_CAPS , KC_QUOT ,           KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
                                            _______ , _______ , _______ , _______ , _______
  ),

  [_NAV] = LAYOUT_reviung41(
    KC_DEL  , KC_F13  , KC_F14  , KC_F15            , KC_F16            , KC_F19   ,           KC_PGUP , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    _______ , KC_F17  , KC_F18  , KC_BML_LAYERC_TAB , KC_BML_LAYERA_TAB , KC_F20   ,           KC_PGDN , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , KC_BSPC    ,
    _______ , C(KC_Z) , C(KC_X) , C(KC_C)           , C(KC_V)           , A(KC_F4) ,           XXXXXXX , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , _______    ,
                                                      _______           , _______  , _______ , _______ , _______
  ),

  [_ADJUST_PLUS] = LAYOUT_reviung41(
    RGB_VAI , RGB_SAI , RGB_HUI , RGB_MOD  , XXXXXXX , RGB_TOG ,           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    RGB_VAD , RGB_SAD , RGB_HUD , RGB_RMOD , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,           RESET   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                             _______ , _______ , XXXXXXX , _______ , _______
  ),
};


// this currently only supports control and alt. implementation can be slighly improved
uint8_t unpress_mod_on_layer_change = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
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


layer_state_t layer_state_set_user(layer_state_t state){
    if (unpress_mod_on_layer_change & MOD_BIT(KC_LCTRL)){
        unregister_code(KC_LCTRL);
        unpress_mod_on_layer_change ^= MOD_BIT(KC_LCTRL);
    }
    if (unpress_mod_on_layer_change & MOD_BIT(KC_LALT)){
        unregister_code(KC_LALT);
        unpress_mod_on_layer_change ^= MOD_BIT(KC_LALT);
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV,KC_SPC):
            return TAPPING_TERM + 350;
        default:
            return TAPPING_TERM;
    }
}
