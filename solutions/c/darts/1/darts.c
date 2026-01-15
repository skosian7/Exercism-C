#include "darts.h"

uint8_t score(coordinate_t position)
{
    float radius = sqrt(pow(position.x,2) + pow(position.y,2));
    
    if(radius>10.0)return 0;

    if(radius>5.0)return 1;

    if(radius>1.0)return 5;
    
    return 10;
}
