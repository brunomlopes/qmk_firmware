#include QMK_KEYBOARD_H

enum layers {
 _VISUAL_STUDIO,
 _WINDOW_MANAGER,
 _OSX_WINDOW_MANAGER,
};

#define RUN         KC_F5
#define STEP_OVER   KC_F10
#define STEP_IN     KC_F11
#define STEP_OUT    LSFT(KC_F11)
#define RUN_TO_LINE LCTL(KC_F10)
#define ATTACH_TO   LCA_T(KC_P)
#define TOGGLE_BREAKPOINT KC_F9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_VISUAL_STUDIO]=LAYOUT_ortho_4x4(
      KC_NO                         , STEP_OVER  , STEP_IN   , RUN_TO_LINE,
      KC_NO                         , KC_NO      , STEP_OUT  , KC_NO,
      MO(_OSX_WINDOW_MANAGER)       , KC_NO      , KC_NO     , RUN,
      LM(_WINDOW_MANAGER, MOD_LGUI) , ATTACH_TO  , KC_NO     , TOGGLE_BREAKPOINT
    ),
    [_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      KC_NO  , LCTL(KC_LEFT) , (KC_UP)   , LCTL(KC_RGHT),
      KC_NO  , (KC_LEFT)     , KC_ESCAPE , (KC_RGHT),
      KC_NO  , _______       , (KC_DOWN) , _______,
      _______, KC_NO         , KC_NO     , KC_NO
    ),
    [_OSX_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      _______, KC_MS_WH_RIGHT , KC_MS_BTN4 , KC_MS_WH_LEFT,
      _______, _______        , _______    , _______,
      _______, _______        , _______    , _______,
      _______, _______        , _______    , _______
    )
};

