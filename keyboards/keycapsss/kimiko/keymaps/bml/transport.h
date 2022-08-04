#pragma once

typedef struct _master_to_slave_t {
    int m2s_rotary_left;
    int m2s_rotary_right;
    bool is_caps_word_on;
    bool is_spunderscore_on;
} master_to_slave_t;

extern void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);
