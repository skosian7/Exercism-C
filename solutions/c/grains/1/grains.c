#include "grains.h"
uint64_t square(uint8_t index)
{
    uint64_t s;
    if(index<=0 || index>64) return 0;
    
    if(index == 1)
    {
        s = 1;
        return s;
    }

    if(index == 2)
    {
        s = 2;
        return s;
    }

    s = 2;
    for(int i=1;i<index-1;i++)
    {
        s*=2;
    }
    return s;
    
}

uint64_t total(void)
{
    uint64_t total = 0;
    int i;

    for(i=1; i<65; i++)
    {
        total += square(i);
    }

    return total;
}