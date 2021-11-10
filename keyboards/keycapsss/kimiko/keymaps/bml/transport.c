// vscode shim for intelisense
#ifndef QMK_KEYBOARD_H
#define QMK_KEYBOARD_H "kimiko.h"
#endif

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#include QMK_KEYBOARD_H
#include "rotary.h"
#include "transport.h"

void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    right_rotary_current_mode = m2s->m2s_rotary_right;
    left_rotary_current_mode = m2s->m2s_rotary_left;
}
