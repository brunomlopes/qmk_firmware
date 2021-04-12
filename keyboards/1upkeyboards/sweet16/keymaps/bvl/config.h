#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 10

// I've wired 4 leds under the board, using them for layer status
#undef RGBLED_NUM
#define RGBLED_NUM 4

#define RGBLIGHT_LIMIT_VAL 100
#define RGBLIGHT_SLEEP

// I don't care about rgb animations, we're using the leds directly ourselves
#undef RGBLIGHT_ANIMATIONS
