#include "armstrong_numbers.h"

uint64_t n_to_power(int n, int power)
{
    if(power == 1) return n;
    if(n == 1 || n == 0) return n;
       
    uint64_t result = n;
    for(int i = 1; i < power; i++)
    {
        result *= n;
    }
    
    return result;
}

uint8_t how_many_digits(int n)
{
    uint8_t digits_n = 0;
    if(n == 0) return 1;

    while(n%10 != 0)
    {
        n /= 10;
        digits_n ++;
    }
    return digits_n;
}

uint8_t* n_to_digits(int n, uint8_t len)
{
    uint8_t* digits = malloc(sizeof(uint8_t)*len);
    if(digits == NULL)return NULL;
    int temp = n;
    for(int i = 0; i < len; i++)
    {
        digits[i] = temp%10;
        temp /= 10;
    }
    return digits;
}

bool is_armstrong_number(int candidate)
{
    //decompose candidate to digits with helper functions
    uint8_t len = how_many_digits(candidate);
    uint8_t* digits = n_to_digits(candidate, len);
    if(digits == NULL) return false;

    //raise digits to power and sum the powers
    uint64_t summ = 0;
    for(int i = 0; i < len; i++)
    {
        summ += n_to_power(digits[i], len);
    }
    
    //compare with candidate
    free(digits);
    return summ == (uint64_t)candidate;
}