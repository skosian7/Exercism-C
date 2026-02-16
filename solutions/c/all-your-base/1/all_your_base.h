#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#define DIGITS_ARRAY_SIZE 64

#include <stdio.h>
#include <stdint.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length);

//helper function
int16_t my_power(int16_t input_base, size_t i);

#endif
