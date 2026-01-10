#include "resistor_color.h"

static const resistor_band_t colours_list[] = {BLACK, BROWN, RED, ORANGE, YELLOW,GREEN, BLUE, VIOLET, GREY, WHITE};

 uint8_t color_code(resistor_band_t colour)
{
    uint8_t value = 21;

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

const resistor_band_t* colors()
{ 
    return colours_list;
}
