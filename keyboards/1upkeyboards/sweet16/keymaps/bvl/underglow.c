#include "sweet16.h"
#include "underglow.h"

void bml_ug_set(enum bml_ug_colours colour, LED_TYPE* led)
{
    switch (colour)
    {
    case BML_UG_WHITE:
        sethsv(HSV_WHITE, led);
        break;
    case BML_UG_RED:
        sethsv(HSV_RED, led);
        break;
    case BML_UG_CORAL:
        sethsv(HSV_CORAL, led);
        break;
    case BML_UG_ORANGE:
        sethsv(HSV_ORANGE, led);
        break;
    case BML_UG_GOLDENROD:
        sethsv(HSV_GOLDENROD, led);
        break;
    case BML_UG_GOLD:
        sethsv(HSV_GOLD, led);
        break;
    case BML_UG_YELLOW:
        sethsv(HSV_YELLOW, led);
        break;
    case BML_UG_CHARTREUSE:
        sethsv(HSV_CHARTREUSE, led);
        break;
    case BML_UG_GREEN:
        sethsv(HSV_GREEN, led);
        break;
    case BML_UG_SPRINGGREEN:
        sethsv(HSV_SPRINGGREEN, led);
        break;
    case BML_UG_TURQUOISE:
        sethsv(HSV_TURQUOISE, led);
        break;
    case BML_UG_TEAL:
        sethsv(HSV_TEAL, led);
        break;
    case BML_UG_CYAN:
        sethsv(HSV_CYAN, led);
        break;
    case BML_UG_AZURE:
        sethsv(HSV_AZURE, led);
        break;
    case BML_UG_BLUE:
        sethsv(HSV_BLUE, led);
        break;
    case BML_UG_PURPLE:
        sethsv(HSV_PURPLE, led);
        break;
    case BML_UG_MAGENTA:
        sethsv(HSV_MAGENTA, led);
        break;
    case BML_UG_PINK:
        sethsv(HSV_PINK, led);
        break;
    default:
        break;
    }
};
