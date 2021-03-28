#pragma once

enum bml_ug_colours {
    BML_UG_WHITE,
    BML_UG_RED,
    BML_UG_CORAL,
    BML_UG_ORANGE,
    BML_UG_GOLDENROD,
    BML_UG_GOLD,
    BML_UG_YELLOW,
    BML_UG_CHARTREUSE,
    BML_UG_GREEN,
    BML_UG_SPRINGGREEN,
    BML_UG_TURQUOISE,
    BML_UG_TEAL,
    BML_UG_CYAN,
    BML_UG_AZURE,
    BML_UG_BLUE,
    BML_UG_PURPLE,
    BML_UG_MAGENTA,
    BML_UG_PINK,
};

void bml_ug_set(enum bml_ug_colours colour, LED_TYPE *led);
