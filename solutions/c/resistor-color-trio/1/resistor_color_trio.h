#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef enum{
    OHMS,
    KILOOHMS,
    MEGAOHMS,
    GIGAOHMS
}unit_t;

typedef struct{
    uint16_t value;
    unit_t unit;
}resistor_value_t;

uint8_t colour_code_unum(resistor_band_t colour);
uint16_t colour_code_duo(resistor_band_t* colours);
resistor_value_t color_code(resistor_band_t* colours);
unit_t unit_code(resistor_band_t colour);
int modifier(resistor_band_t colour);
resistor_value_t make_black_value(resistor_band_t* colours);

#endif
