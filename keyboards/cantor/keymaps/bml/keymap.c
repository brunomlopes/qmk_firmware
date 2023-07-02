// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _LOWERFN,
  _LEFTFN,
  _NAV,
  _SYMBOL,
  _NUMPAD,
  _NUMPADALT,
  _METALAYER
};

enum blender_keycode {
    KC_BML_OTILDE = SAFE_RANGE,  
    KC_BML_ATILDE, 
    KC_BML_TILDE,
    KC_BML_ACUTE,
    KC_BML_HAT,
    KC_BML_TOGGLE_SPSHIFT,
    KC_BML_TOGGLE_SPUNDERSCORE,
    KC_BML_FLAYER_FA,
    KC_BML_GRAVE,
    KC_BML_TREMA,
    KC_BML_LAYERC_TAB,
    KC_BML_LAYERA_TAB,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // | LALT| KC_ESC | Q | W |    E     |     R      |  T  |    |  Y  |      U      |  I  | O |  P  |       }       |
    // | LCTL| KC_TAB | A | S |    D     |     F      |  G  |    |  H  |      J      |  K  | L | ENT | LCTL| KC_BSPC |
    // |     LSFT     | Z | X |    C     |     V      |  B  |    |  N  |      M      |  ,  | . |  /  |     RSFT      |
    //                        | MOD_LGUI | MO(_LOWER) | ENT |    | SPC | MO(_SYMBOL) | ALT |                          
  [_BASE] = LAYOUT_split_3x6_3(
    MT(MOD_LALT, KC_ESC) , KC_Q , KC_W , KC_E     , KC_R              , KC_T   ,      KC_Y   , KC_U        , KC_I    , KC_O   , KC_P    , KC_RBRC               ,
    MT(MOD_LCTL, KC_TAB) , KC_A , KC_S , KC_D     , LT(_LOWERFN,KC_F) , KC_G   ,      KC_H   , KC_J        , KC_K    , KC_L   , KC_ENT  , MT(MOD_LCTL, KC_BSPC) ,
    KC_LSFT              , KC_Z , KC_X , KC_C     , KC_V              , KC_B   ,      KC_N   , KC_M        , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT               ,
                                         MOD_LGUI , MO(_LOWER)        , KC_ENT ,      KC_SPC , MO(_SYMBOL) , KC_RALT                                            
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    KC_BSPC , KC_1    , KC_2    , KC_3          , KC_4    , KC_5    ,      KC_6         , KC_7    , KC_8       , KC_9      , KC_0       , KC_F12     ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH       , KC_DLR  , KC_PERC ,      KC_CIRC      , KC_AMPR , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______    ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2)) , KC_LCBR , KC_LBRC ,      KC_NUBS      , KC_RPRN , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , _______    ,
                                  TG(_NUMPAD)   , _______ , KC_SPC  ,      TT(_LOWERFN) , _______ , _______                                          
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
//    A(KC_F4)          , KC_F13        , KC_F14        , KC_F15        , KC_F16            , KC_F19       ,                                 XXXXXXX       , KC_MPRV       , KC_MPLY      , KC_MNXT       , XXXXXXX                    , KC_EQL                ,
    KC_TAB            , KC_F17        , KC_F18        , A(ALGR(KC_E))         , KC_BML_LAYERA_TAB , KC_F20       ,      A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE , KC_LBRC      , XXXXXXX                    ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN               , S(KC_COMM)        , S(KC_DOT)    ,      A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN      , KC_QUOT      , KC_BSLS                    ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN               , KC_BML_OTILDE     , KC_BML_TREMA ,                      KC_NUBS       , S(KC_NUBS)   , KC_BML_HAT   , KC_BML_TILDE , KC_BML_TOGGLE_SPUNDERSCORE ,
                                                        KC_BML_TOGGLE_SPSHIFT , _______           , _______      ,      _______       , _______       , _______      , _______      
  ),
};
