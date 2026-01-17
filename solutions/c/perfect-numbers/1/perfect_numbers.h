#ifndef PERFECT_NUMBERS_H
#define PERFECT_NUMBERS_H

#include <stdlib.h>

typedef enum {
   PERFECT_NUMBER = 1,
   ABUNDANT_NUMBER = 2,
   DEFICIENT_NUMBER = 3,
   ERROR = -1
} kind;

void find_factors(int number, int *factors);
int sum_factors(int *factors);
kind classify_number(int number);

#endif
