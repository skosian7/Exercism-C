#ifndef ARMSTRONG_NUMBERS_H
#define ARMSTRONG_NUMBERS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

bool is_armstrong_number(int candidate);
uint64_t n_to_power(int n, int power);
uint8_t how_many_digits(int n);
uint8_t* n_to_digits(int n, uint8_t len);

#endif
