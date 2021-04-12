#define QMK_KEYBOARD_H  "sweet16.h"

#include QMK_KEYBOARD_H
#include "underglow.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x4(
        KC_7, KC_8,   KC_9,   KC_ASTR,
        KC_4, KC_5,   KC_6,   KC_SLSH,
        KC_1, KC_2,   KC_3,   KC_MINS,
        KC_0, KC_ENT, KC_DOT, MO(1)
    ),

    [1] = LAYOUT_ortho_4x4(
        RESET, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [2] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [3] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [4] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [5] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [6] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [7] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [8] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
    [9] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

};



// BL: do't really like this macro, seems messy, depending on led_layer, etc
#define CHECK_LAYER_LED(layer, layer_num, led_ix, led_for_layer, new_colour) \
    if((layer == layer_num) && (led_ix == led_for_layer)) led_colour = new_colour

// Layer 9 is set up to jump to other layer choice

void bml_set_layer_indicator(layer_state_t state){
    // BL: no clue why, but modifiers change the state, but default layer state doesn't
    // so we check the state for temporary layers, and if there are none, go to the default layer state
    int highest_layer = get_highest_layer(state);
    if (highest_layer == 0)
        highest_layer = get_highest_layer(default_layer_state);

    for (int led_ix = 0; led_ix < RGBLED_NUM ; led_ix++)
    {
        enum bml_ug_colours led_colour = highest_layer == 9 ? BML_UG_TEAL : BML_UG_WHITE;

        CHECK_LAYER_LED(highest_layer, 0, led_ix, 0, BML_UG_RED);
        CHECK_LAYER_LED(highest_layer, 1, led_ix, 1, BML_UG_RED);
        CHECK_LAYER_LED(highest_layer, 2, led_ix, 2, BML_UG_RED);
        CHECK_LAYER_LED(highest_layer, 3, led_ix, 3, BML_UG_RED);
        CHECK_LAYER_LED(highest_layer, 4, led_ix, 0, BML_UG_GREEN);
        CHECK_LAYER_LED(highest_layer, 5, led_ix, 1, BML_UG_GREEN);
        CHECK_LAYER_LED(highest_layer, 6, led_ix, 2, BML_UG_GREEN);
        CHECK_LAYER_LED(highest_layer, 7, led_ix, 3, BML_UG_GREEN);

        LED_TYPE* current_led = (LED_TYPE *)&led[led_ix];

        bml_ug_set(led_colour, current_led);

    }
    rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
	layer_state_set_user(layer_state);
    // I do not care about the epprom,just turn lights on
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    // BL: I think there's a timer somewhere which runs and sets up the leds
    // this wait makes it so that our set layer indicator runs after that init
    wait_ms(100);
    bml_set_layer_indicator(layer_state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    bml_set_layer_indicator(state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    bml_set_layer_indicator(state);
    return state;
}

void suspend_wakeup_init_user(void) {
    bml_set_layer_indicator(default_layer_state);
}
