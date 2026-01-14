#include "space_age.h"

double orbital_period(planet_t planet)
{
    double orbital_prd = -1.0;
    switch (planet)
    {
    case MERCURY:
        orbital_prd = 0.2408467;
        break;
    case VENUS:
        orbital_prd = 0.61519726;
        break;
    case EARTH:
        orbital_prd = 1.0;
        break;
    case MARS:
        orbital_prd = 1.8808158;
        break;
    case JUPITER:
        orbital_prd = 11.862615;
        break;
    case SATURN:
        orbital_prd = 29.447498;
        break;
    case URANUS:
        orbital_prd = 84.016846;
        break;
    case NEPTUNE:
        orbital_prd = 164.79132;
        break;    
    default:
        break;
    }
    return orbital_prd;
}

float age(planet_t planet, int64_t seconds)
{
    if(planet<0 || planet>8)return -1.0;
    return seconds/(31557600.0*orbital_period(planet));
}