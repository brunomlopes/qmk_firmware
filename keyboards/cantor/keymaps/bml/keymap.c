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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    MT(MOD_LALT, KC_ESC) , KC_Q , KC_W , KC_E    , KC_R               , KC_T                 ,      KC_Y             , KC_U        , KC_I    , KC_O   , KC_P    , KC_RBRC               ,
    MT(MOD_LCTL, KC_TAB) , KC_A , KC_S , KC_D    , LT(_LOWERFN, KC_F) , LT(_NUMPADALT, KC_G) ,      KC_H             , KC_J        , KC_K    , KC_L   , KC_ENT  , MT(MOD_LCTL, KC_BSPC) ,
    KC_LSFT              , KC_Z , KC_X , KC_C    , KC_V               , KC_B                 ,      KC_N             , KC_M        , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT               ,
                                         KC_LGUI , MO(_LOWER)         , LT(_MACRO, KC_ENT)   ,      LT(_NAV, KC_SPC) , MO(_SYMBOL) , KC_LALT                                            
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    KC_BSPC , KC_1    , KC_2    , KC_3          , KC_4    , KC_5    ,      KC_6     , KC_7      , KC_8       , KC_9      , KC_0       , KC_F12  ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH       , KC_DLR  , KC_PERC ,      KC_CIRC  , KC_AMPR   , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______ ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2)) , KC_LCBR , KC_LBRC ,      KC_NUBS  , KC_RPRN   , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , _______ ,
                                  KC_LCTL       , _______ , KC_SPC  ,      _______  , MO(_META) , _______
  ),

  [_LOWER_MAC] = LAYOUT_split_3x6_3(
    _______ , _______ , _______ , _______ , _______   , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______ , _______ , _______   , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______ , _______ , _______ , _______ , S(KC_EQL) , KC_EQL  ,      _______ , _______ , _______ , _______ , _______ , _______   ,
                                  _______ , _______   , _______ ,      _______ , _______ , _______
  ),

  [_LOWERFN] = LAYOUT_split_3x6_3(
    KC_DEL  , KC_F1            , KC_F2   , KC_F3   , KC_F4   , KC_F5    ,      KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    KC_BSPC , KC_BML_FLAYER_FA , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,      KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_F12  ,
    KC_TAB  , XXXXXXX          , XXXXXXX , XXXXXXX , XXXXXXX , A(KC_F4) ,      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DOT  ,
                                           XXXXXXX , _______ , _______  ,      KC_BSPC , KC_DEL  , KC_TAB
  ),

  [_NUMPADALT] = LAYOUT_split_3x6_3(
    XXXXXXX , KC_BSPC , KC_7 , KC_8   , KC_9    , XXXXXXX ,      KC_BSPC , KC_7   , KC_8    , KC_9 , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_TAB  , KC_4 , KC_5   , KC_6    , XXXXXXX ,      KC_TAB  , KC_4   , KC_5    , KC_6 , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_0    , KC_1 , KC_2   , KC_3    , KC_DOT  ,      KC_0    , KC_1   , KC_2    , KC_3 , KC_DOT  , XXXXXXX ,
                               KC_DOT , KC_COMM , KC_BSPC ,      XXXXXXX , KC_DOT , KC_COMM                            
  ),


  [_NAV] = LAYOUT_split_3x6_3(
    _______ , KC_INS  , KC_PAUS , KC_APP  , A(KC_F4)        , KC_BTN5 ,      KC_PGUP , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    _______ , XXXXXXX , XXXXXXX , KC_PSCR , A(ALGR(KC_TAB)) , KC_BTN4 ,      KC_PGDN , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , KC_BSPC    ,
    _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V)         , XXXXXXX ,      XXXXXXX , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , _______    ,
                                  _______ , _______         , _______ ,      _______ , MO(_MACRO) , _______
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
    // |      TAB       |   F17   |    F18     | ALGR(E) | BML_LAYERA_TAB |    F20    |    | ALGR(8) | ALGR(9) | BML_ACUTE | BML_GRAVE |            {            |      XXXXXXX       |
    // | BML_LAYERC_TAB | ALGR(2) |  XXXXXXX   |    :    |      S(,)      |   S(.)    |    | ALGR(7) | ALGR(0) |   ASTR    |     (     |            '            |         \          |
    // |      LSFT      | XXXXXXX | BML_ATILDE |    ;    |   BML_OTILDE   | BML_TREMA |    |    \    |  S(\)   |  BML_HAT  | BML_TILDE | BML_TOGGLE_SPUNDERSCORE | BML_TOGGLE_SPSHIFT |
    //                                         | _______ |   MO(_META)    |  _______  |    | _______ | _______ |  _______  |

    KC_TAB            , KC_F17        , KC_F18        , A(ALGR(KC_E)) , KC_BML_LAYERA_TAB , KC_F20       ,      A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE , KC_LBRC                    , XXXXXXX               ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN       , S(KC_COMM)        , S(KC_DOT)    ,      A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN      , KC_QUOT                    , KC_BSLS               ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN       , KC_BML_OTILDE     , KC_BML_TREMA ,      KC_NUBS       , S(KC_NUBS)    , KC_BML_HAT   , KC_BML_TILDE , KC_BML_TOGGLE_SPUNDERSCORE , KC_BML_TOGGLE_SPSHIFT ,
                                                        _______       , MO(_META)         , _______      ,      MO(_MACRO)    , _______       , _______
  ),

  [_SYMBOL_MAC] = LAYOUT_split_3x6_3(
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______    , _______    , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,      A(S(KC_8)) , A(S(KC_9)) , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,      _______    , _______    , _______ , _______ , _______ , _______ ,
                                  _______ , _______ , _______ ,      _______    , _______    , _______
  ),

  [_MACRO] = LAYOUT_split_3x6_3(
    A(KC_F4)           , KC_F13  , KC_F14  , KC_F15            , KC_F16            , KC_F19        ,      KC_AUDIO_VOL_UP   , KC_MPRV , KC_MPLY , KC_MNXT , _______ , _______ ,
    KC_BML_LAYERC_TAB  , KC_F17  , KC_F18  , KC_WH_U           , KC_BML_LAYERA_TAB , KC_F20        ,      KC_AUDIO_VOL_DOWN , _______ , _______ , _______ , _______ , _______ ,
    KC_BML_DOUBLE_CTRL , XXXXXXX , XXXXXXX , KC_WH_D           , XXXXXXX           , KC_AUDIO_MUTE ,      KC_AUDIO_MUTE     , _______ , _______ , _______ , _______ , _______ ,
                                             KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP   , _______       ,      _______           , _______ , _______
  ),

  [_META] = LAYOUT_split_3x6_3(
    QK_BOOTLOADER  , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , QK_REBOOT ,
    KC_BML_SHOW_OS , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
    _______        , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______   ,
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
