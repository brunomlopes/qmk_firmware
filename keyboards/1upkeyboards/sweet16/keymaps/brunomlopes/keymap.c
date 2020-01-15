#include QMK_KEYBOARD_H

enum layers {
 _VISUAL_STUDIO,
 _CHROME_DEBUGGER,
 _OSX_WINDOW_MANAGER,
 _WINDOW_MANAGER,
 _MEDIA,
 _MOUSE,
 _LAYER_PICKER
};

enum custom_keycodes {
  VS_SHOW_HIERARCHY = SAFE_RANGE,
};

/* OS X Keycodes */
#define OSX_LOCK LGUI(LCTL(KC_Q))
#define OSX_VIRTUAL_DESKTOP_LEFT KC_MS_WH_RIGHT
#define OSX_VIRTUAL_DESKTOP_RIGHT KC_MS_WH_LEFT
#define OSX_EXPOSE KC_MS_BTN4
#define OSX_PREVIOUS_DISPLAY LCTL(LALT(LGUI(KC_LEFT)))
#define OSX_NEXT_DISPLAY LCTL(LALT(LGUI(KC_RIGHT)))
#define OSX_WINDOW_UP LCTL(LALT(KC_UP))
#define OSX_WINDOW_DOWN LCTL(LALT(KC_DOWN))
#define OSX_WINDOW_LEFT LCTL(LALT(KC_LEFT))
#define OSX_WINDOW_RIGHT LCTL(LALT(KC_RIGHT))
#define OSX_WINDOW_MAXIMIZE LCTL(LALT(KC_ENT))

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_VISUAL_STUDIO]=LAYOUT_ortho_4x4(
      OSL(_LAYER_PICKER)            , STEP_OVER         , STEP_IN           , RUN_TO_LINE,
      MO(_MEDIA)                    , VS_SHOW_HIERARCHY , STEP_OUT          , KC_NO,
      MO(_OSX_WINDOW_MANAGER)       , VS_NAVIGATE_TO    , KC_NO             , RUN,
      LM(_WINDOW_MANAGER, MOD_LGUI) , ATTACH_TO         , RUN_WITHOUT_DEBUG , TOGGLE_BREAKPOINT
    ),

    [_CHROME_DEBUGGER]=LAYOUT_ortho_4x4(
      OSL(_LAYER_PICKER)            , STEP_OVER           , STEP_IN                 , RUN_TO_LINE,
      MO(_MEDIA)                    , CHROME_PICK_ELEMENT , STEP_OUT                , KC_NO,
      MO(_OSX_WINDOW_MANAGER)       , CHROME_DEVTOOLS     , KC_NO                   , CHROME_RUN,
      LM(_WINDOW_MANAGER, MOD_LGUI) , CHROME_REFRESH      , CHROME_ONOFF_BREAKPOINT , CHROME_TOGGLE_BREAKPOINT
    ),

    [_OSX_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      _______  , OSX_VIRTUAL_DESKTOP_LEFT , OSX_EXPOSE          , OSX_VIRTUAL_DESKTOP_RIGHT,
      OSX_LOCK , OSX_WINDOW_LEFT          , OSX_WINDOW_UP       , OSX_WINDOW_RIGHT ,
      _______  , OSX_PREVIOUS_DISPLAY     , OSX_WINDOW_DOWN     , OSX_NEXT_DISPLAY,
      _______  , OSX_VIRTUAL_DESKTOP_LEFT , OSX_WINDOW_MAXIMIZE , OSX_VIRTUAL_DESKTOP_RIGHT
    ),
    
    [_MOUSE]=LAYOUT_ortho_4x4(
      OSL(_LAYER_PICKER)            , KC_WH_L               , KC_MS_U               , KC_WH_U,
      MO(_MEDIA)                    , KC_MS_L               , KC_MS_BTN1            , KC_MS_R,
      MO(_OSX_WINDOW_MANAGER)       , KC_WH_R               , KC_MS_D               , KC_WH_D,
      LM(_WINDOW_MANAGER, MOD_LGUI) , KC_ACL0               , KC_ACL1               , KC_ACL2
    ),

    [_WINDOW_MANAGER]=LAYOUT_ortho_4x4(
      _______, LCTL(KC_LEFT) , KC_F14    , LCTL(KC_RGHT),
      _______, (KC_LEFT)     , KC_UP     , (KC_RGHT),
      _______, LSFT(KC_LEFT) , KC_DOWN   , LSFT(KC_RIGHT),
      _______, KC_MS_WH_RIGHT, KC_ESCAPE , KC_MS_WH_LEFT
    ),

    [_MEDIA]=LAYOUT_ortho_4x4(
      _______, KC_NO               , KC_NO                 , KC_AUDIO_VOL_UP,
      _______, KC_MEDIA_PREV_TRACK , KC_MEDIA_PLAY_PAUSE   , KC_MEDIA_NEXT_TRACK,
      _______, KC_NO               , KC_MEDIA_STOP         , KC_AUDIO_VOL_DOWN,
      _______, KC_NO               , KC_NO                 , KC_AUDIO_MUTE
    ),


    [_LAYER_PICKER]=LAYOUT_ortho_4x4(
      _______, DF(_VISUAL_STUDIO) , DF(_CHROME_DEBUGGER)  , KC_NO,
      _______, KC_NO              , KC_NO                 , KC_NO,
      _______, KC_NO              , KC_NO                 , KC_NO,
      _______, DF(_MOUSE)         , KC_NO                 , KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VS_SHOW_HIERARCHY:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_LCTL("e"));
        SEND_STRING("h");
      } else {
        // when keycode QMKBEST is released
      }
      break;

  }
  return true;
};
