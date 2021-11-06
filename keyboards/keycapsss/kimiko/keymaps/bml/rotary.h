#pragma once

enum rotary_modes {
    ROTARY_MODE_VOLUME,
    ROTARY_MODE_VERTICAL_MOVE,
    ROTARY_MODE_HORIZONTAL_MOVE,
    ROTARY_MODE_VERTICAL_SCROLL,
    ROTARY_MODE_HORIZONTAL_SCROLL,
};

extern int right_rotary_current_mode;
extern int left_rotary_current_mode;
