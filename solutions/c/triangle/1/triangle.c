#include "triangle.h"

int is_triangle(triangle_t sides)
{
    if(sides.a == 0 || sides.b == 0 || sides.c == 0) return 0;
    if(sides.a +  sides.b >= sides.c &&
        sides.b + sides.c >= sides.a &&
        sides.a + sides.c >= sides.b) return 1;
    return 0;
}

int is_equilateral (triangle_t sides)
{
    if(!is_triangle(sides))return 0;
    if(sides.a == sides.b && sides.b == sides.c)return 1;
    return 0;
}

int is_isosceles (triangle_t sides)
{
    if(!is_triangle(sides))return 0;
    if(is_equilateral(sides))return 1;
    if(sides.a == sides.b || sides.b == sides.c || sides.c == sides.a)return 1;
    return 0;
}

int is_scalene (triangle_t sides)
{
    if(!is_triangle(sides))return 0;
    if(is_equilateral(sides) || is_isosceles(sides))return 0;
    return 1;
}
