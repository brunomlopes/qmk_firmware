// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

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

    KC_BML_DOUBLE_CTRL
};

#define KC_BML_TREMA RALT(KC_LBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // | LALT| KC_ESC | Q | W |    E     |     R      |  T  |    |  Y  |      U      |  I  | O |  P  |       }       |
    // | LCTL| KC_TAB | A | S |    D     |     F      |  G  |    |  H  |      J      |  K  | L | ENT | LCTL| KC_BSPC |
    // |     LSFT     | Z | X |    C     |     V      |  B  |    |  N  |      M      |  ,  | . |  /  |     RSFT      |
    //                        | MOD_LGUI | MO(_LOWER) | ENT |    | SPC | MO(_SYMBOL) | ALT |                          
  [_BASE] = LAYOUT_split_3x6_3(
    MT(MOD_LALT, KC_ESC) , KC_Q , KC_W , KC_E    , KC_R              , KC_T   ,      KC_Y             , KC_U        , KC_I    , KC_O   , KC_P    , KC_RBRC               ,
    MT(MOD_LCTL, KC_TAB) , KC_A , KC_S , KC_D    , LT(_LOWERFN,KC_F) , KC_G   ,      KC_H             , KC_J        , KC_K    , KC_L   , KC_ENT  , MT(MOD_LCTL, KC_BSPC) ,
    KC_LSFT              , KC_Z , KC_X , KC_C    , KC_V              , KC_B   ,      KC_N             , KC_M        , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT               ,
                                         KC_LGUI , MO(_LOWER)        , KC_ENT ,      LT(_NAV, KC_SPC) , MO(_SYMBOL) , KC_RALT                                            
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    KC_BSPC , KC_1    , KC_2    , KC_3          , KC_4    , KC_5    ,      KC_6     , KC_7      , KC_8       , KC_9      , KC_0       , KC_F12  ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH       , KC_DLR  , KC_PERC ,      KC_CIRC  , KC_AMPR   , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______ ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2)) , KC_LCBR , KC_LBRC ,      KC_NUBS  , KC_RPRN   , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , _______ ,
                                  _______       , _______ , KC_SPC  ,      _______  , MO(_META) , _______                                       
  ),

  [_LOWER_MAC] = LAYOUT_split_3x6_3(
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______ , _______ , _______ , KC_EQL  ,      _______ , _______ , _______ , _______ , _______ , _______   ,
                                  _______ , _______ , _______ ,      _______ , _______ , _______                                 
  ),

  [_LOWERFN] = LAYOUT_split_3x6_3(
    KC_DEL  , KC_F1            , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,      KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    KC_BSPC , KC_BML_FLAYER_FA , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12  ,
    XXXXXXX , XXXXXXX          , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                           XXXXXXX , _______ , _______ ,      _______ , _______ , _______                               
  ),

  [_NAV] = LAYOUT_split_3x6_3(
    _______ , KC_INS  , KC_PAUS , KC_APP  , A(KC_F4)        , KC_BTN5 ,      KC_PGUP , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    _______ , XXXXXXX , XXXXXXX , KC_PSCR , A(ALGR(KC_TAB)) , KC_BTN4 ,      KC_PGDN , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , KC_BSPC    ,
    _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V)         , XXXXXXX ,      XXXXXXX , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , _______    ,
                                  _______ , _______         , _______ ,      _______ , _______    , _______                                          
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
    // |      TAB       |   F17   |    F18     | ALGR(E) | BML_LAYERA_TAB |    F20    |    | ALGR(8) | ALGR(9) | BML_ACUTE | BML_GRAVE |            {            |      XXXXXXX       |
    // | BML_LAYERC_TAB | ALGR(2) |  XXXXXXX   |    :    |      S(,)      |   S(.)    |    | ALGR(7) | ALGR(0) |   ASTR    |     (     |            '            |         \          |
    // |      LSFT      | XXXXXXX | BML_ATILDE |    ;    |   BML_OTILDE   | BML_TREMA |    |    \    |  S(\)   |  BML_HAT  | BML_TILDE | BML_TOGGLE_SPUNDERSCORE | BML_TOGGLE_SPSHIFT |
    //                                         | _______ |   MO(_META)    |  _______  |    | _______ | _______ |  _______  |                                                           

    KC_TAB            , KC_F17        , KC_F18        , A(ALGR(KC_E)) , KC_BML_LAYERA_TAB , KC_F20       ,      A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE , KC_LBRC                    , XXXXXXX               ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN       , S(KC_COMM)        , S(KC_DOT)    ,      A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN      , KC_QUOT                    , KC_BSLS               ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN       , KC_BML_OTILDE     , KC_BML_TREMA ,      KC_NUBS       , S(KC_NUBS)    , KC_BML_HAT   , KC_BML_TILDE , KC_BML_TOGGLE_SPUNDERSCORE , KC_BML_TOGGLE_SPSHIFT ,
                                                        _______       , MO(_META)         , _______      ,      _______       , _______       , _______                                                                          
  ),

  [_SYMBOL_MAC] = LAYOUT_split_3x6_3(
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
                                  _______ , _______ , _______ ,      _______ , _______ , _______                                 
  ),

  [_META] = LAYOUT_split_3x6_3(
    QK_BOOTLOADER , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , QK_REBOOT ,
    _______       , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______       , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
                                        _______ , _______ , _______ ,      _______ , _______ , _______                                 
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

layer_state_t layer_state_set_user(layer_state_t state){
    os_variant_t detected_os = detected_host_os();

    if(detected_os == OS_MACOS){
        if(IS_LAYER_ON_STATE(state, _LOWER)){
            layer_on(_LOWER_MAC);
        }else{
            layer_off(_LOWER_MAC);
        }
    }

    return state;
}

// {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods(); 
    //os_variant_t detected_os = detected_host_os();

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
