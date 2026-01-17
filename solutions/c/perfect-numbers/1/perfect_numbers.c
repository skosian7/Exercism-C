#include "perfect_numbers.h"

void find_factors(int number, int *factors)
{
    for(int i = 1, j = 0; i < number-1; i++)
    {
        if(number%i == 0)
        {
            factors[j] = i;
            j++;
        }
    }
}

int sum_factors(int *factors)
{
    int i = 0, summ = 0;
    while(factors[i] != 0)
    {
        summ += factors[i];
        i++;
    }

    return summ;
    
}

kind classify_number(int number)
{
    if(number <= 0) return ERROR;
    
    int *factors = malloc(number *(sizeof(int)));
    if(factors == NULL) return ERROR;
    for( int i = 0; i < number; i++)
    {
        factors[i] = 0;
    }
    
    find_factors(number, factors);
    int summ = sum_factors(factors);
    free(factors);
    
    if(number > summ)return DEFICIENT_NUMBER;
    else if(number == summ) return PERFECT_NUMBER;
    else if (number < summ) return ABUNDANT_NUMBER;

    return ERROR;
}