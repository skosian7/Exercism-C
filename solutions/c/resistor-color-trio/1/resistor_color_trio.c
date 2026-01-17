#include "resistor_color_trio.h"

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

uint16_t colour_code_duo(resistor_band_t* colours)
{
    uint8_t code1 = colour_code_unum(colours[0]) * 10;
    uint8_t code2 = colour_code_unum(colours[1]);

    uint16_t code = code1 + code2;
    
    return code;
}

int modifier(resistor_band_t colour)
{
    int mod = 0;
    if(colour == BLACK || colour == WHITE || colour == ORANGE || colour == BLUE) return 1;
    if(colour == BROWN || colour == YELLOW || colour == VIOLET) return 10;
    if(colour == RED || colour == GREEN || colour == GREY) return 100;

    return mod;
}

unit_t unit_code(resistor_band_t colour)
{
    unit_t unit = OHMS;

    switch (colour)
    {
    case BLACK:
    case BROWN:
    case RED:
        break;
    case ORANGE:
    case YELLOW:
    case GREEN:
        unit = KILOOHMS;
        break;
    case BLUE:
    case VIOLET:
    case GREY:
        unit = MEGAOHMS;
        break;
    case WHITE:
        unit = GIGAOHMS;
        break;    
    default:
        break;
    }

    return unit;
}

resistor_value_t make_black_value(resistor_band_t* colours)
{
    resistor_value_t my_black_resistor;
    uint8_t first_band = colour_code_unum(colours[0]);
    switch (colours[2])
    {
    case BLACK:
        my_black_resistor.value = first_band * 10;
        my_black_resistor.unit = OHMS;
        break; 
    case BROWN:
        my_black_resistor.value = first_band * 100;
        my_black_resistor.unit = OHMS;
        break;
    case RED:
        my_black_resistor.value = first_band;
        my_black_resistor.unit = KILOOHMS;
        break;
    case ORANGE:
        my_black_resistor.value = first_band * 10;
        my_black_resistor.unit = KILOOHMS; 
        break;
    case YELLOW:
        my_black_resistor.value = first_band * 100;
        my_black_resistor.unit = KILOOHMS;
        break;
    case GREEN:
        my_black_resistor.value = first_band;
        my_black_resistor.unit = MEGAOHMS;
        break;
    case BLUE:
        my_black_resistor.value = first_band * 10;
        my_black_resistor.unit = MEGAOHMS;
        break;
    case VIOLET:
        my_black_resistor.value = first_band * 100;
        my_black_resistor.unit = MEGAOHMS;
        break;
    case GREY:
        my_black_resistor.value = first_band;
        my_black_resistor.unit = GIGAOHMS;
        break;
    case WHITE:
        my_black_resistor.value = first_band * 10;
        my_black_resistor.unit = MEGAOHMS;
        break;
       
    default:
        break;
    }
    return my_black_resistor;
}

 resistor_value_t color_code(resistor_band_t* colours)
{
    resistor_value_t my_resistor;
    if(colours[1] != BLACK)
    {
        my_resistor.value = colour_code_duo(colours) * modifier(colours[2]);
        my_resistor.unit = unit_code(colours[2]);
    }else{
        my_resistor = make_black_value(colours);
    }

    return my_resistor;
}