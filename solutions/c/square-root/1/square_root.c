#include "square_root.h"

int square_root(int a)
{
    int answer = 0, temp = 0;
    for(int i = 0; i <= a; i++)
    {
        temp = i*i;
        if(temp == a) return i;
    }
    return answer;
}
