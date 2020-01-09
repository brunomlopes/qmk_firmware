#include QMK_KEYBOARD_H

enum layers {
 _VISUAL_STUDIO,
 _CHROME_DEBUGGER,
 _OSX_WINDOW_MANAGER,
 _WINDOW_MANAGER,
 _LAYER_PICKER
};

/* VS Keycodes */ 
#define RUN         KC_F5
#define RUN_WITHOUT_DEBUG  LCTL(KC_F5)
#define STEP_OVER   KC_F10
#define STEP_IN     KC_F11
#define STEP_OUT    LSFT(KC_F11)
#define RUN_TO_LINE LCTL(KC_F10)
#define ATTACH_TO   LCA_T(KC_P)
#define TOGGLE_BREAKPOINT KC_F9

/* Chrome Keycodes */ 
#define CHROME_REFRESH     KC_F5
#define CHROME_RUN         KC_F8
#define CHROME_TOGGLE_BREAKPOINT LCTL(KC_B)
#define CHROME_ONOFF_BREAKPOINT LSFT(LCTL(KC_B))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_VISUAL_STUDIO]=LAYOUT_ortho_4x4(
      OSL(_LAYER_PICKER)            , STEP_OVER  , STEP_IN           , RUN_TO_LINE,
      KC_NO                         , KC_NO      , STEP_OUT          , KC_NO,
      MO(_OSX_WINDOW_MANAGER)       , KC_NO      , KC_NO             , RUN,
      LM(_WINDOW_MANAGER, MOD_LGUI) , ATTACH_TO  , RUN_WITHOUT_DEBUG , TOGGLE_BREAKPOINT
    ),

    [_CHROME_DEBUGGER]=LAYOUT_ortho_4x4(
      OSL(_LAYER_PICKER)            , STEP_OVER       , STEP_IN   , RUN_TO_LINE,
      KC_NO                         , KC_NO           , STEP_OUT  , KC_NO,
      MO(_OSX_WINDOW_MANAGER)       , KC_NO           , KC_NO     , CHROME_RUN,
      LM(_WINDOW_MANAGER, MOD_LGUI) , CHROME_REFRESH  , CHROME_ONOFF_BREAKPOINT     , CHROME_TOGGLE_BREAKPOINT
    ),

    [_OSX_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      _______, KC_MS_WH_RIGHT , KC_MS_BTN4 , KC_MS_WH_LEFT,
      _______, _______        , _______    , _______,
      _______, _______        , _______    , _______,
      _______, KC_MS_WH_RIGHT , _______    , KC_MS_WH_LEFT
    ),
    [_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      _______, LCTL(KC_LEFT) , (KC_UP)   , LCTL(KC_RGHT),
      _______, (KC_LEFT)     , KC_ESCAPE , (KC_RGHT),
      _______, LSFT(KC_LEFT) , (KC_DOWN) , LSFT(KC_RIGHT),
      _______, KC_MS_WH_RIGHT, KC_F20    , KC_MS_WH_LEFT
    ),

    [_LAYER_PICKER]=LAYOUT_ortho_4x4(
      _______, DF(_VISUAL_STUDIO) , DF(_CHROME_DEBUGGER)  , KC_NO,
      _______, KC_NO              , KC_NO                 , KC_NO,
      _______, KC_NO              , KC_NO                 , KC_NO,
      _______, KC_NO              , KC_NO                 , KC_NO
    ),
};

