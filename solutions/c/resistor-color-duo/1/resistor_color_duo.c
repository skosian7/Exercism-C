#include "resistor_color_duo.h"

uint8_t colour_code_unum(resistor_band_t colour)
{
    uint8_t value = 0;

    switch (colour)
    {
    case BLACK:
        value = 0;
        break;
    case BROWN:
        value = 1;
        break;
    case RED:
        value = 2;
        break;
    case ORANGE:
        value = 3;
        break;
    case YELLOW:
        value = 4;
        break;
    case GREEN:
        value = 5;
        break;
    case BLUE:
        value = 6;
        break;
    case VIOLET:
        value = 7;
        break;
    case GREY:
        value = 8;
        break;
    case WHITE:
        value = 9;
        break;
    
    default:
        break;
    }

    return value;
}

uint16_t color_code(resistor_band_t* colours)
{
    uint8_t code1 = colour_code_unum(colours[0]) * 10;
    uint8_t code2 = colour_code_unum(colours[1]);

    uint16_t code = code1 + code2;
    
    return code;
}