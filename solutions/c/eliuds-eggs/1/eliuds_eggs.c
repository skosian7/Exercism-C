#include "eliuds_eggs.h"
unsigned int egg_count(unsigned int number_d)
{
    int eggs_n = 0;
    
    while(number_d != 0)
    {
        if(number_d % 2 == 1) eggs_n++;
        number_d /= 2;
    }
    

    return eggs_n;
}
