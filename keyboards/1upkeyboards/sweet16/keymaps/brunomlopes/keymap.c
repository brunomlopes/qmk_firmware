#include QMK_KEYBOARD_H

enum layers {
 _VISUAL_STUDIO,
 _WINDOW_MANAGER
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
      KC_NO , STEP_OVER  , STEP_IN   , RUN_TO_LINE,
      KC_NO , KC_NO      , STEP_OUT  , KC_NO,
      RUN   , KC_NO      , KC_NO     , KC_NO,
      MO(1) , ATTACH_TO  , KC_NO     , TOGGLE_BREAKPOINT
    ),
    [_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      KC_NO  , KC_NO        , (KC_UP)   , KC_NO,
      KC_NO  , (KC_LEFT)    , KC_ESCAPE , (KC_RGHT),
      KC_NO  , LCTL(KC_LEFT), (KC_DOWN) , LCTL(KC_RGHT),
      _______, KC_NO        , KC_NO     , KC_NO
    )
};

bool bml_inWindowManagerLayer = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    // since I'm using _WINDOW_MANAGER as a "window manager layer"
    // we need to toggle KH_LGUI as long as we're in that particular layer
    if(biton32(state) == _WINDOW_MANAGER){
        bml_inWindowManagerLayer = true;
        register_code(KC_LGUI);
    }else{
        if(bml_inWindowManagerLayer){
            bml_inWindowManagerLayer = false;
            unregister_code(KC_LGUI);
        }
    }
    return state;
}
