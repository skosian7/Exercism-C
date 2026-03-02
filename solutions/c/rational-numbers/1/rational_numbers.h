 
#ifndef EXERCISM_C_RATIONAL_NUMBERS_H
#define EXERCISM_C_RATIONAL_NUMBERS_H

#include <stdio.h>

typedef  struct {
    int numerator;
    int denominator;
}rational_t;


int gcd(int a, int b);
int power(int number, int power);
int root(int number, int root);

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t reduce(rational_t r);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r);
rational_t exp_rational(rational_t r, int exp);
float exp_real(int number, rational_t exp);
#endif //EXERCISM_C_RATIONAL_NUMBERS_H