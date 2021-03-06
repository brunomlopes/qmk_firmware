#include QMK_KEYBOARD_H
enum layers {
 _VISUAL_STUDIO,
 _CHROME_DEBUGGER,
 _NUMPAD,
 _MOUSE,
 _OSX_WINDOW_MANAGER,
 _WINDOW_MANAGER,
 _MEDIA,
 _LIGHTS,
 // FKEYS are used to switch directly to a virtual desktop
 _FKEYS,
 _FIDDLE,
 _POWER,
 _ARROWS,
 _LAYER_PICKER
};

enum custom_keycodes {
  VS_SHOW_HIERARCHY = SAFE_RANGE,
  ALT_TAB
};

extern rgblight_config_t rgblight_config;

#define ALT_TAB_LAYER _OSX_WINDOW_MANAGER

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
  [_VISUAL_STUDIO] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)           , STEP_OVER         , STEP_IN           , RUN_TO_LINE       ,
    MO(_MEDIA)                   , VS_SHOW_HIERARCHY , STEP_OUT          , KC_NO             ,
    MO(_OSX_WINDOW_MANAGER)      , VS_NAVIGATE_TO    , KC_NO             , RUN               ,
    LM(_WINDOW_MANAGER,MOD_LGUI) , ATTACH_TO         , RUN_WITHOUT_DEBUG , TOGGLE_BREAKPOINT
  ),

  [_CHROME_DEBUGGER] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , STEP_OVER           , STEP_IN                 , RUN_TO_LINE              ,
    MO(_MEDIA)                    , CHROME_PICK_ELEMENT , STEP_OUT                , KC_NO                    ,
    MO(_OSX_WINDOW_MANAGER)       , CHROME_DEVTOOLS     , KC_NO                   , CHROME_RUN               ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , CHROME_REFRESH      , CHROME_ONOFF_BREAKPOINT , CHROME_TOGGLE_BREAKPOINT
  ),

  [_NUMPAD] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , KC_P7 , KC_P8   , KC_P9   ,
    MO(_MEDIA)                    , KC_P4 , KC_P5   , KC_P6   ,
    MO(_OSX_WINDOW_MANAGER)       , KC_P1 , KC_P2   , KC_P3   ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , KC_P0 , KC_PDOT , KC_PENT
  ),

  [_OSX_WINDOW_MANAGER] = LAYOUT_ortho_4x4(
    ALT_TAB  , OSX_VIRTUAL_DESKTOP_LEFT , OSX_EXPOSE          , OSX_VIRTUAL_DESKTOP_RIGHT ,
    OSX_LOCK , OSX_WINDOW_LEFT          , OSX_WINDOW_UP       , OSX_WINDOW_RIGHT          ,
    _______  , OSX_PREVIOUS_DISPLAY     , OSX_WINDOW_DOWN     , OSX_NEXT_DISPLAY          ,
    _______  , OSX_VIRTUAL_DESKTOP_LEFT , OSX_WINDOW_MAXIMIZE , OSX_VIRTUAL_DESKTOP_RIGHT
  ),

  [_MOUSE] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , KC_WH_L , KC_MS_U    , KC_WH_U ,
    MO(_MEDIA)                    , KC_MS_L , KC_MS_BTN1 , KC_MS_R ,
    MO(_OSX_WINDOW_MANAGER)       , KC_WH_R , KC_MS_D    , KC_WH_D ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , KC_ACL0 , KC_ACL1    , KC_ACL2
  ),

  [_WINDOW_MANAGER] = LAYOUT_ortho_4x4(
    KC_TAB      , LCTL(KC_LEFT) , KC_F14    , LCTL(KC_RGHT)  ,
    _______     , (KC_LEFT)     , KC_UP     , (KC_RGHT)      ,
    OSL(_FKEYS) , LSFT(KC_LEFT) , KC_DOWN   , LSFT(KC_RIGHT) ,
    _______     , KC_MS_WH_LEFT , KC_ESCAPE , KC_MS_WH_RIGHT
  ),

  [_MEDIA] = LAYOUT_ortho_4x4(
    _______ , KC_NO               , KC_NO               , KC_AUDIO_VOL_UP     ,
    _______ , KC_MEDIA_PREV_TRACK , KC_MEDIA_PLAY_PAUSE , KC_MEDIA_NEXT_TRACK ,
    _______ , KC_NO               , KC_MEDIA_STOP       , KC_AUDIO_VOL_DOWN   ,
    _______ , KC_NO               , KC_NO               , KC_AUDIO_MUTE
  ),

  [_LIGHTS] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , RGB_HUI , RGB_VAI , RGB_TOG ,
    MO(_MEDIA)                    , RGB_HUD , RGB_VAD , KC_NO   ,
    MO(_OSX_WINDOW_MANAGER)       , RGB_SAI , KC_NO   , KC_NO   ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , RGB_SAD , KC_NO   , KC_NO
  ),

  [_FKEYS] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER) , KC_NO  , KC_NO  , KC_NO  ,
    KC_F13             , KC_F14 , KC_F15 , KC_F16 ,
    KC_F17             , KC_F18 , KC_F19 , KC_F20 ,
    KC_F21             , KC_F22 , KC_F23 , KC_F24
  ),

  [_FIDDLE] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , KC_NO , KC_NO , KC_NO ,
    MO(_MEDIA)                    , KC_NO , KC_NO , KC_NO ,
    MO(_OSX_WINDOW_MANAGER)       , KC_NO , KC_NO , KC_NO ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , KC_NO , KC_NO , KC_NO
  ),

  [_POWER] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , KC_NO , KC_NO , KC_NO   ,
    MO(_MEDIA)                    , KC_NO , KC_NO , KC_NO   ,
    LGUI(KC_L)                    , KC_NO , KC_NO , KC_SLEP ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , KC_NO , KC_NO , KC_NO
  ),

  [_ARROWS] = LAYOUT_ortho_4x4(
    OSL(_LAYER_PICKER)            , KC_HOME , KC_UP   , KC_PGUP ,
    MO(_MEDIA)                    , KC_LEFT , KC_DOWN , KC_RGHT ,
    _______                       , KC_END  , KC_NO   , KC_PGDN ,
    LM(_WINDOW_MANAGER, MOD_LGUI) , KC_INS  , KC_NO   , KC_DEL
  ),

  [_LAYER_PICKER] = LAYOUT_ortho_4x4(
    KC_NO   , DF(_VISUAL_STUDIO) , DF(_CHROME_DEBUGGER) , DF(_NUMPAD) ,
    _______ , DF(_ARROWS)        , DF(_FKEYS)           , OSL(_FKEYS) ,
    RESET   , DF(_MOUSE)         , DF(_LIGHTS)          , DF(_FIDDLE) ,
    _______ , KC_NO              , KC_NO                , OSL(_POWER)
  ),

};


// we activate alt when we use the alt-tab,
// and want to de-activate it when leaving a layer
bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c


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
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
};

// BL: do't really like this macro, seems messy, depending on led_layer, etc
#define CHECK_LAYER_LED(layer, layer_num, led_ix, led_for_layer) if((layer == layer_num) && (led_ix == led_for_layer)) led_layer = true

void bml_set_layer_indicator(layer_state_t state){
    // BL: no clue why, but modifiers change the state, but default layer state doesn't
    // so we check the state for temporary layers, and if there are none, go to the default layer state
    int highest_layer = get_highest_layer(state);
    if (highest_layer == 0)
        highest_layer = get_highest_layer(default_layer_state);

    for (int led_ix = 0; led_ix < RGBLED_NUM ; led_ix++)
    {
        bool led_layer = false;
        CHECK_LAYER_LED(highest_layer, _LAYER_PICKER, led_ix, 0);
        CHECK_LAYER_LED(highest_layer, _VISUAL_STUDIO, led_ix, 1);
        CHECK_LAYER_LED(highest_layer, _CHROME_DEBUGGER, led_ix, 2);
        CHECK_LAYER_LED(highest_layer, _NUMPAD, led_ix, 3);
        CHECK_LAYER_LED(highest_layer, _FKEYS, led_ix, 4);
        CHECK_LAYER_LED(highest_layer, _ARROWS, led_ix, 6);
        CHECK_LAYER_LED(highest_layer, _MEDIA, led_ix, 7);
        CHECK_LAYER_LED(highest_layer, _MOUSE, led_ix, 9);
        CHECK_LAYER_LED(highest_layer, _LIGHTS, led_ix, 10);
        CHECK_LAYER_LED(highest_layer, _FIDDLE, led_ix, 11);
        CHECK_LAYER_LED(highest_layer, _POWER, led_ix, 12);
        CHECK_LAYER_LED(highest_layer, _WINDOW_MANAGER, led_ix, 15);

        if(led_layer)
            sethsv(219,65,100, (LED_TYPE *)&led[led_ix]);
        else
            sethsv(255,255,0, (LED_TYPE *)&led[led_ix]);
    }
    rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.
}

void keyboard_post_init_user(void) {
    // BL: I think there's a timer somewhere which runs and sets up the leds
    // this wait makes it so that our set layer indicator runs after that init
    wait_ms(100);
	//Enable the LED layers
	layer_state_set_user(layer_state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    bml_set_layer_indicator(state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    //int highest_default_layer = get_highest_layer(default_layer_state);
    int highest_layer = get_highest_layer(state);
    bml_set_layer_indicator(state);
    switch (highest_layer) {
    case _VISUAL_STUDIO:
        break;
    case _CHROME_DEBUGGER:
        break;
    case _MOUSE:
        break;
    case _LIGHTS:
        break;
    case ALT_TAB_LAYER:
        break;
    default:
        // if we're no longer in ALT_TAB_LAYER but alt_tab is active
        // leave alt tab mode
        if(is_alt_tab_active){
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
        }
    }
    return state;
}

void suspend_wakeup_init_user(void) {
    bml_set_layer_indicator(default_layer_state);
}
