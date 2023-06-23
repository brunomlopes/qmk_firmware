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
#ifndef QMK_KEYBOARD_H
#define QMK_KEYBOARD_H "kimiko.h"
#endif

#include QMK_KEYBOARD_H
#include "rotary.h"
#include "layers.h"
#include "transport.h"
#include <transactions.h>

enum custom_keycodes {
    ROTARY_MODE_LEFT = SAFE_RANGE,
    ROTARY_MODE_RIGHT,
    KC_BML_ATILDE,
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

int left_rotary_current_mode = ROTARY_MODE_VERTICAL_SCROLL;
int right_rotary_current_mode = ROTARY_MODE_VOLUME;
bool is_caps_word_on_mode = false;
bool is_bml_spunderscore_active = false;
bool is_bml_spshift_active = false;

#define _T KC_TRANSPARENT

#define KC_BML_TREMA RALT(KC_LBRC)

/* VS Keycodes */
#define RUN         KC_F5
#define RUN_WITHOUT_DEBUG  LCTL(KC_F5)
#define STEP_OVER   KC_F10
#define STEP_IN     KC_F11
#define STEP_OUT    LSFT(KC_F11)
#define RUN_TO_LINE LCTL(KC_F10)
#define ATTACH_TO   LALT(LCTL(KC_P))
#define TOGGLE_BREAKPOINT KC_F9
#define VS_NAVIGATE_TO KC_F12

/* Chrome Keycodes */
#define CHROME_REFRESH     KC_F5
#define CHROME_RUN         KC_F8
#define CHROME_DEVTOOLS    KC_F12
#define CHROME_TOGGLE_BREAKPOINT LCTL(KC_B)
#define CHROME_ONOFF_BREAKPOINT LSFT(LCTL(KC_B))
#define CHROME_PICK_ELEMENT LCTL(LSFT(KC_C))

/*
- thumb keys have lalt on both sides, to allow for easier access to alt+(left side key) instead of twisting fingers on left.
- altgr is on symbol layer
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    // |     MUTE     | 1 |  2   |  3  |         4         |        5                              |                      |      6      |         7         |  8  |  9  |  0  |  MO(_HRMOD)   |
    // | LALT| KC_ESC | Q |  W   |  E  |         R         |        T                              |                      |      Y      |         U         |  I  |  O  |  P  | LALT| KC_RBRC |
    // | LCTL| KC_TAB | A |  S   |  D  | LT(_LOWERFN,KC_F) | LT(_LEFTFN,KC_G)                      |                      |      H      | LT(_LOWERFN,KC_J) |  K  |  L  | ENT | LCTL| KC_BSPC |
    // |     LSFT     | Z |  X   |  C  |         V         |        B         |      MS_BTN1       |    |      MUTE       |      N      |         M         |  ,  |  .  |  /  | OSM(MOD_RSFT) |
    //                    | LCTL | ALT |        GUI        |    MO(_LOWER)    | LT(_SYMBOL,KC_ENT) |    | LT(_NAV,KC_SPC) | MO(_SYMBOL) |       RCTL        | GUI | ALT |

    KC_MUTE              , KC_1 , KC_2    , KC_3    , KC_4              , KC_5             ,                                             KC_6        , KC_7              , KC_8    , KC_9    , KC_0    , KC_BML_DOUBLE_CTRL    ,
    MT(MOD_LALT, KC_ESC) , KC_Q , KC_W    , KC_E    , KC_R              , KC_T             ,                                             KC_Y        , KC_U              , KC_I    , KC_O    , KC_P    , MT(MOD_LALT, KC_RBRC) ,
    MT(MOD_LCTL, KC_TAB) , KC_A , KC_S    , KC_D    , LT(_LOWERFN,KC_F) , LT(_LEFTFN,KC_G) ,                                             KC_H        , LT(_LOWERFN,KC_J) , KC_K    , KC_L    , KC_ENT  , MT(MOD_LCTL, KC_BSPC) ,
    KC_LSFT              , KC_Z , KC_X    , KC_C    , KC_V              , KC_B             , KC_MS_BTN1         ,      KC_MUTE         , KC_N        , KC_M              , KC_COMM , KC_DOT  , KC_SLSH , OSM(MOD_RSFT)         ,
                                  KC_LCTL , KC_LALT , KC_LGUI           , MO(_LOWER)       , LT(_SYMBOL,KC_ENT) ,      LT(_NAV,KC_SPC) , MO(_SYMBOL) , KC_RCTL           , KC_RGUI , KC_LALT
  ),

  [_HRMOD] = LAYOUT(
    // | _T |     _T     |     _T     |     _T     |     _T     | _T      |         | _T |     _T     |     _T     |     _T     |      _T      | _T |
    // | _T |     _T     |     _T     |     _T     |     _T     | _T      |         | _T |     _T     |     _T     |     _T     |      _T      | _T |
    // | _T | LGUI| KC_A | LALT| KC_S | LSFT| KC_D | LCTL| KC_F | _T      |         | _T | RCTL| KC_J | RSFT| KC_K | LALT| KC_L | RGUI| KC_ENT | _T |
    // | _T |     _T     |     _T     |     _T     |     _T     | _T | _T |    | _T | _T |     _T     |     _T     |     _T     |      _T      | _T |
    //                   |     _T     |     _T     |     _T     | _T | _T |    | _T | _T |     _T     |     _T     |     _T     |

    _T , _T                 , _T                 , _T                 , _T                 , _T ,                _T , _T                 , _T                 , _T                 , _T                   , _T ,
    _T , _T                 , _T                 , _T                 , _T                 , _T ,                _T , _T                 , _T                 , _T                 , _T                   , _T ,
    _T , MT(MOD_LGUI, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LSFT, KC_D) , MT(MOD_LCTL, KC_F) , _T ,                _T , MT(MOD_RCTL, KC_J) , MT(MOD_RSFT, KC_K) , MT(MOD_LALT, KC_L) , MT(MOD_RGUI, KC_ENT) , _T ,
    _T , _T                 , _T                 , _T                 , _T                 , _T , _T ,      _T , _T , _T                 , _T                 , _T                 , _T                   , _T ,
                              _T                 , _T                 , _T                 , _T , _T ,      _T , _T , _T                 , _T                 , _T
  ),

  [_GAMING] = LAYOUT(
    // | 5 | ESC  |  1   |  2  |  3   |  4                |               |      6      |       7        |  8  |  9  | 0 |  -   |
    // | T | TAB  |  Q   |  W  |  E   |  R                |               |      Y      |       U        |  I  |  O  | P |  }   |
    // | G | LSFT |  A   |  S  |  D   |  F                |               |      H      |       J        |  K  |  L  | \ | BSPC |
    // | B |  `   |  Z   |  X  |  C   |  V  | TG(_GAMING) |    |   MUTE   |      N      |       M        |  ,  |  .  | / | RSFT |
    //            | LCTL | ALT | LCTL | SPC |     ENT     |    | MO(_NAV) | MO(_SYMBOL) | TT(_METALAYER) | GUI | ALT |

    KC_5 , KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4   ,                               KC_6        , KC_7           , KC_8    , KC_9    , KC_0    , KC_MINS ,
    KC_T , KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R   ,                               KC_Y        , KC_U           , KC_I    , KC_O    , KC_P    , KC_RBRC ,
    KC_G , KC_LSFT , KC_A    , KC_S    , KC_D    , KC_F   ,                               KC_H        , KC_J           , KC_K    , KC_L    , KC_BSLS , KC_BSPC ,
    KC_B , KC_GRV  , KC_Z    , KC_X    , KC_C    , KC_V   , TG(_GAMING) ,      KC_MUTE  , KC_N        , KC_M           , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                     KC_LCTL , KC_LALT , KC_LCTL , KC_SPC , KC_ENT      ,      MO(_NAV) , MO(_SYMBOL) , TT(_METALAYER) , KC_RGUI , KC_RALT
  ),

  [_LOWER] = LAYOUT(
    // | DEL  | F1 |   F2    |       F3       |     F4      |   F5              |                     |     F6      |      F7      |   F8    |   F9    | F10  |    F11     |
    // | BSPC | 1  |    2    |       3        |      4      |    5              |                     |      6      |      7       |    8    |    9    |  0   |    F12     |
    // |  ~   | !  |    @    |       #        |      $      |    %              |                     |    CIRC     |      &       |  ASTR   |    (    |  )   |  _______   |
    // |  `   | _  |    -    |    ALGR(2)     |    LCBR     |    {    | _______ |    |    _______     |      \      |      )       |  S(\)   |  S(.)   | S(/) | MO(_HRMOD) |
    //             | _______ | TG(_NUMPADALT) | TG(_NUMPAD) | _______ |   SPC   |    | TT(_METALAYER) | TT(_NUMPAD) | TT(_LOWERFN) | _______ | _______ |

    KC_DEL  , KC_F1   , KC_F2   , KC_F3          , KC_F4       , KC_F5   ,                                 KC_F6       , KC_F7        , KC_F8      , KC_F9     , KC_F10     , KC_F11     ,
    KC_BSPC , KC_1    , KC_2    , KC_3           , KC_4        , KC_5    ,                                 KC_6        , KC_7         , KC_8       , KC_9      , KC_0       , KC_F12     ,
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH        , KC_DLR      , KC_PERC ,                                 KC_CIRC     , KC_AMPR      , KC_ASTR    , KC_LPRN   , KC_RPRN    , _______    ,
    KC_GRV  , KC_UNDS , KC_MINS , A(ALGR(KC_2))  , KC_LCBR     , KC_LBRC , _______ ,      _______        , KC_NUBS     , KC_RPRN      , S(KC_NUBS) , S(KC_DOT) , S(KC_SLSH) , MO(_HRMOD) ,
                        _______ , TG(_NUMPADALT) , TG(_NUMPAD) , _______ , KC_SPC  ,      TT(_METALAYER) , TT(_NUMPAD) , TT(_LOWERFN) , _______    , _______
  ),

  [_LOWERFN] = LAYOUT(
    // | XXXXXXX |    XXXXXXX    | XXXXXXX | XXXXXXX |   XXXXXXX    | XXXXXXX           |              | XXXXXXX |   XXXXXXX    | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    // |   DEL   |      F1       |   F2    |   F3    |      F4      |   F5              |              |   F6    |      F7      |   F8    |   F9    |   F10   |   F11   |
    // |  BSPC   | BML_FLAYER_FA | XXXXXXX | XXXXXXX |   XXXXXXX    | XXXXXXX           |              |    6    |      7       |    8    |    9    |    0    |   F12   |
    // | XXXXXXX |    XXXXXXX    | XXXXXXX | XXXXXXX |   XXXXXXX    | XXXXXXX | _______ |    | _______ | XXXXXXX |   XXXXXXX    | XXXXXXX | XXXXXXX | XXXXXXX | _______ |
    //                           | _______ | _______ | TG(_LOWERFN) | _______ | _______ |    | _______ | _______ | TT(_LOWERFN) | _______ | _______ |

    XXXXXXX , XXXXXXX          , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX ,                          XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_DEL  , KC_F1            , KC_F2   , KC_F3   , KC_F4        , KC_F5   ,                          KC_F6   , KC_F7        , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    KC_BSPC , KC_BML_FLAYER_FA , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX ,                          KC_6    , KC_7         , KC_8    , KC_9    , KC_0    , KC_F12  ,
    XXXXXXX , XXXXXXX          , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX , _______ ,      _______ , XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
                                 _______ , _______ , TG(_LOWERFN) , _______ , _______ ,      _______ , _______ , TT(_LOWERFN) , _______ , _______
  ),

  [_LEFTFN] = LAYOUT(
    // | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |   XXXXXXX    | XXXXXXX           |              | XXXXXXX |   XXXXXXX    | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    // |   DEL   |   F1    |   F2    |   F3    |      F4      | XXXXXXX           |              |   F6    |      F7      |   F8    |   F9    |   F10   |   F11   |
    // |  BSPC   |   F5    |   F6    |   F7    |      F8      | XXXXXXX           |              |    6    |      7       |    8    |    9    |    0    |   F12   |
    // | XXXXXXX |   F9    |   F10   |   F11   |     F12      | XXXXXXX | _______ |    | _______ | XXXXXXX |   XXXXXXX    | XXXXXXX | XXXXXXX | XXXXXXX | _______ |
    //                     | _______ | _______ | TG(_LOWERFN) | _______ | _______ |    | _______ | _______ | TT(_LOWERFN) | _______ | _______ |

    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX ,                          XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4        , XXXXXXX ,                          KC_F6   , KC_F7        , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    KC_BSPC , KC_F5   , KC_F6   , KC_F7   , KC_F8        , XXXXXXX ,                          KC_6    , KC_7         , KC_8    , KC_9    , KC_0    , KC_F12  ,
    XXXXXXX , KC_F9   , KC_F10  , KC_F11  , KC_F12       , XXXXXXX , _______ ,      _______ , XXXXXXX , XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
                        _______ , _______ , TG(_LOWERFN) , _______ , _______ ,      _______ , _______ , TT(_LOWERFN) , _______ , _______
  ),

  [_NAV] = LAYOUT(
    // |   ESC   | XXXXXXX | XXXXXXX | XXXXXXX |   A(F4)   | XXXXXXX           |              |   APP   |  PSCR   |  C(^)   | XXXXXXX | XXXXXXX |  PAUS   |
    // | _______ |   INS   |  PSCR   | XXXXXXX | ALGR(TAB) |  BTN5             |              |  PGUP   |  HOME   |    ^    |   END   | C(DEL)  | C(BSPC) |
    // | _______ | XXXXXXX | XXXXXXX | XXXXXXX |  XXXXXXX  |  BTN4             |              |  PGDN   |   <-    |    v    |   ->    |   DEL   |  BSPC   |
    // | _______ |  C(Z)   |  C(X)   |  C(C)   |   C(V)    | XXXXXXX | _______ |    | _______ | XXXXXXX |  C(<-)  |  C(v)   |  C(->)  | XXXXXXX | _______ |
    //                     | _______ | _______ |  _______  | _______ | _______ |    | _______ |   ENT   | _______ | _______ | _______ |

    KC_ESC  , XXXXXXX , XXXXXXX , XXXXXXX , A(KC_F4)        , XXXXXXX ,                          KC_APP  , KC_PSCR    , C(KC_UP)   , XXXXXXX    , XXXXXXX   , KC_PAUS    ,
    _______ , KC_INS  , KC_PSCR , XXXXXXX , A(ALGR(KC_TAB)) , KC_BTN5 ,                          KC_PGUP , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX         , KC_BTN4 ,                          KC_PGDN , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , KC_BSPC    ,
    _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V)         , XXXXXXX , _______ ,      _______ , XXXXXXX , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , _______    ,
                        _______ , _______ , _______         , _______ , _______ ,      _______ , KC_ENT  , _______    , _______    , _______
  ),

  [_SYMBOL] = LAYOUT(
    // |     A(F4)      |   F13   |    F14     |   F15   |      F16       |     F19               |                     | XXXXXXX |  MPRV   |   MPLY    |     MNXT      |         XXXXXXX         |         =          |
    // |      TAB       |   F17   |    F18     | ALGR(E) | BML_LAYERA_TAB |     F20               |                     | ALGR(8) | ALGR(9) | BML_ACUTE |   BML_GRAVE   |            {            |      XXXXXXX       |
    // | BML_LAYERC_TAB | ALGR(2) |  XXXXXXX   |    :    |      S(,)      |    S(.)               |                     | ALGR(7) | ALGR(0) |   ASTR    |       (       |            '            |         \          |
    // |      LSFT      | XXXXXXX | BML_ATILDE |    ;    |   BML_OTILDE   |  BML_TREMA  | XXXXXXX |    |    XXXXXXX     |    \    |  S(\)   |  BML_HAT  |   BML_TILDE   | BML_TOGGLE_SPUNDERSCORE | BML_TOGGLE_SPSHIFT |
    //                            |  _______   | _______ |    _______     | TT(_NUMPAD) | XXXXXXX |    | TT(_METALAYER) | XXXXXXX | _______ |  _______  | OSM(MOD_RALT) |

    A(KC_F4)          , KC_F13        , KC_F14        , KC_F15        , KC_F16            , KC_F19       ,                                 XXXXXXX       , KC_MPRV       , KC_MPLY      , KC_MNXT       , XXXXXXX                    , KC_EQL                ,
    KC_TAB            , KC_F17        , KC_F18        , A(ALGR(KC_E)) , KC_BML_LAYERA_TAB , KC_F20       ,                                 A(ALGR(KC_8)) , A(ALGR(KC_9)) , KC_BML_ACUTE , KC_BML_GRAVE  , KC_LBRC                    , XXXXXXX               ,
    KC_BML_LAYERC_TAB , A(ALGR(KC_2)) , XXXXXXX       , KC_COLN       , S(KC_COMM)        , S(KC_DOT)    ,                                 A(ALGR(KC_7)) , A(ALGR(KC_0)) , KC_ASTR      , KC_LPRN       , KC_QUOT                    , KC_BSLS               ,
    KC_LSFT           , XXXXXXX       , KC_BML_ATILDE , KC_SCLN       , KC_BML_OTILDE     , KC_BML_TREMA , XXXXXXX ,      XXXXXXX        , KC_NUBS       , S(KC_NUBS)    , KC_BML_HAT   , KC_BML_TILDE  , KC_BML_TOGGLE_SPUNDERSCORE , KC_BML_TOGGLE_SPSHIFT ,
                                        _______       , _______       , _______           , TT(_NUMPAD)  , XXXXXXX ,      TT(_METALAYER) , XXXXXXX       , _______       , _______      , OSM(MOD_RALT)
  ),

  [_NUMPAD] = LAYOUT(
    // |  BSPC   | ^  |   #7    |   #8    |     #9      |     #/                |              |  TG(_NUMPAD)   |    XXXXXXX     | BML_TOGGLE_SPUNDERSCORE | RGB_TOG |  CAPS   |  NLCK   |
    // |   <-    | -> |   #4    |   #5    |     #6      |     #*                |              |  TG(_GAMING)   |    XXXXXXX     |         XXXXXXX         | XXXXXXX | XXXXXXX | XXXXXXX |
    // |   DEL   | v  |   #1    |   #2    |     #3      |     #-                |              |   TG(_HRMOD)   |    XXXXXXX     |         XXXXXXX         |   INS   |   DEL   |  BSPC   |
    // | XXXXXXX | ,  |   #0    |  PDOT   |     #⮠      |     #+      |  RESET  |    | XXXXXXX | TG(_NUMPADALT) | TT(_NUMPADALT) |         XXXXXXX         | XXXXXXX | XXXXXXX | XXXXXXX |
    //                | _______ | _______ | TG(_NUMPAD) | TT(_NUMPAD) | _______ |    | _______ |    _______     |    _______     |         _______         | _______ |

    KC_BSPC , KC_UP   , KC_P7   , KC_P8   , KC_P9       , KC_PSLS     ,                          TG(_NUMPAD)    , XXXXXXX        , KC_BML_TOGGLE_SPUNDERSCORE , RGB_TOG , KC_CAPS , KC_NLCK ,
    KC_LEFT , KC_RGHT , KC_P4   , KC_P5   , KC_P6       , KC_PAST     ,                          TG(_GAMING)    , XXXXXXX        , XXXXXXX                    , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_DEL  , KC_DOWN , KC_P1   , KC_P2   , KC_P3       , KC_PMNS     ,                          TG(_HRMOD)     , XXXXXXX        , XXXXXXX                    , KC_INS  , KC_DEL  , KC_BSPC ,
    XXXXXXX , KC_COMM , KC_P0   , KC_PDOT , KC_PENT     , KC_PPLS     , RESET   ,      XXXXXXX , TG(_NUMPADALT) , TT(_NUMPADALT) , XXXXXXX                    , XXXXXXX , XXXXXXX , XXXXXXX ,
                        _______ , _______ , TG(_NUMPAD) , TT(_NUMPAD) , _______ ,      _______ , _______        , _______        , _______                    , _______
  ),

  [_NUMPADALT] = LAYOUT(
    // | BSPC | <- |    ^    |       v        |   ->    |   #/              |              |    XXXXXXX     | XXXXXXX |  C(^)   | XXXXXXX | XXXXXXX | XXXXXXX |
    // | DEL  | #1 |   #2    |       #3       |   #4    |   #*              |              |      PGUP      |  HOME   |    ^    |   END   | C(DEL)  | C(BSPC) |
    // |  #0  | #5 |   #6    |       #7       |   #8    |   #-              |              |      PGDN      |   <-    |    v    |   ->    |   DEL   |  BSPC   |
    // |  ,   | #9 |   #0    |      PDOT      |   #⮠    |   #+    | XXXXXXX |    | XXXXXXX | TG(_NUMPADALT) |  C(<-)  |  C(v)   |  C(->)  | XXXXXXX | XXXXXXX |
    //             | _______ | TG(_NUMPADALT) | _______ | _______ | _______ |    | _______ |    _______     | _______ | _______ | _______ |

    KC_BSPC , KC_LEFT , KC_UP   , KC_DOWN        , KC_RGHT , KC_PSLS ,                          XXXXXXX        , XXXXXXX    , C(KC_UP)   , XXXXXXX    , XXXXXXX   , XXXXXXX    ,
    KC_DEL  , KC_P1   , KC_P2   , KC_P3          , KC_P4   , KC_PAST ,                          KC_PGUP        , KC_HOME    , KC_UP      , KC_END     , C(KC_DEL) , C(KC_BSPC) ,
    KC_P0   , KC_P5   , KC_P6   , KC_P7          , KC_P8   , KC_PMNS ,                          KC_PGDN        , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_DEL    , KC_BSPC    ,
    KC_COMM , KC_P9   , KC_P0   , KC_PDOT        , KC_PENT , KC_PPLS , XXXXXXX ,      XXXXXXX , TG(_NUMPADALT) , C(KC_LEFT) , C(KC_DOWN) , C(KC_RGHT) , XXXXXXX   , XXXXXXX    ,
                        _______ , TG(_NUMPADALT) , _______ , _______ , _______ ,      _______ , _______        , _______    , _______    , _______
  ),

  [_METALAYER] = LAYOUT(
    // | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |    XXXXXXX               |              |  TG(_NUMPAD)   |    XXXXXXX     | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    // | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |    XXXXXXX               |              |  TG(_GAMING)   |    XXXXXXX     | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    // | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |    XXXXXXX               |              |   TG(_HRMOD)   |    XXXXXXX     | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    // | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |    XXXXXXX     |  RESET  |    | XXXXXXX | TG(_NUMPADALT) | TT(_NUMPADALT) | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
    //                     | _______ | _______ | _______ | TT(_METALAYER) | _______ |    | _______ |    _______     |    _______     | _______ | _______ |

    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX        ,                          TG(_NUMPAD)    , XXXXXXX        , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX        ,                          TG(_GAMING)    , XXXXXXX        , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX        ,                          TG(_HRMOD)     , XXXXXXX        , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX        , RESET   ,      XXXXXXX , TG(_NUMPADALT) , TT(_NUMPADALT) , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                        _______ , _______ , _______ , TT(_METALAYER) , _______ ,      _______ , _______        , _______        , _______ , _______
  ),



};


// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF


// this currently only supports control and alt. implementation can be slighly improved
uint8_t unpress_mod_on_layer_change = 0;
uint8_t mod_state;

#define TAP_HEX_CODE4(a,b,c,d) register_code(KC_LALT);tap_code(a);tap_code(b);tap_code(c);tap_code(d);unregister_code(KC_LALT);
#define TAP_HEX_CODE2(a,b) register_code(KC_LALT);tap_code(a);tap_code(b);unregister_code(KC_LALT);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    

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

#ifdef RGBLIGHT_ENABLE
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
        rgblight_sethsv_at(HSV_WHITE, 9);
        rgblight_sethsv_range(HSV_WHITE, 13, 16);
        break;
    case _METALAYER:
        rgblight_sethsv_noeeprom(HSV_TURQUOISE);
        break;
    case _LOWERFN:
        rgblight_sethsv_noeeprom(HSV_PURPLE);
    case _LOWER:
    case _NAV:
    case _SYMBOL:
    default:
        rgblight_sethsv_noeeprom(HSV_WHITE);
        break;
    }
}




layer_state_t default_layer_state_set_user(layer_state_t state){
    bml_set_layer_indicator(state);
    return state;
}
#else
void bml_set_layer_indicator(layer_state_t state){
}
#endif

void keyboard_post_init_user(void){
    #ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    rgblight_sethsv_noeeprom_white();
    #endif
    transaction_register_rpc(USER_SYNC_ROTARY, user_sync_a_slave_handler);
    bml_set_layer_indicator(default_layer_state);
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

void housekeeping_task_user(void) {
    if(is_keyboard_master()){
        static uint32_t last_sync = 0;
        if(timer_elapsed32(last_sync)>500){
            master_to_slave_t m2s = {left_rotary_current_mode,right_rotary_current_mode,is_caps_word_on(),is_bml_spunderscore_active,is_bml_spshift_active};
            if(transaction_rpc_send(USER_SYNC_ROTARY, sizeof(master_to_slave_t), &m2s)){
                last_sync=timer_read32();
            }
        }
    }
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
        case LT(_LEFTFN,KC_G):
            return TAPPING_TERM + 350;
        default:
            return TAPPING_TERM;
    }
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_SLSH:
        case S(KC_SLSH):
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
