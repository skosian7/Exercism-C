#include "difference_of_squares.h"
unsigned int sum_of_squares(unsigned int number)
{
    unsigned int i, j, k;
    for (i=0, j=1, k=0; i<number; i++)
    {
        k+=j*j;
        j++;
    }
    return k;
}
unsigned int square_of_sum(unsigned int number)
{
    unsigned int i, j, k;
    for (i=0, j=1, k=0; i<number; i++)
    {
        k+=j;
        j++;
    }
    return k*k;
    
}
unsigned int difference_of_squares(unsigned int number)
{
    unsigned int k;
    k = square_of_sum(number) - sum_of_squares(number);
    return k;
}
