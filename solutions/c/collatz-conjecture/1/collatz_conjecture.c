#include "collatz_conjecture.h"

int even(int current_number)
{
    return current_number%2==0;
}

int steps(int start)
{
    if(start<=0)return ERROR_VALUE;
    int steps = 0, current_number = start, is_even = 0;

    while(current_number!=1)
    {
        is_even = even(current_number);

        if(is_even)
        {
            current_number/=2;
        }
        else
        {
            current_number*=3;
            current_number++;
        }

        steps++;
    }

    return steps;
}