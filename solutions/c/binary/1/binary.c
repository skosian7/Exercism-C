#include "binary.h"

int length(const char *dna)
{
    int length = 0;
    char i = dna[length];
    
    while(i!='\0')
    {
        length++;
        i = dna[length];
    }

    return length;
}

int power_of_2(int power)
{
    if(power == 0) return 1;
    if(power == 1) return 2;

    int i, result = 2;
    for(i = 1; i < power; i++)
    {
        result *= 2;
    }

    return result;
}

int valid(char c)
{
    if(c == '1' || c == '0')return 1;
    return 0;
}


int convert(const char *input)
{
    int tail = length(input) - 1;  
    int temp, converted = 0;    

    for(int i = tail, j = 0; i >= 0; i--, j++)
    {
        if(!valid(input[i])) return INVALID;
        temp = input[i] - '0';
        converted += temp * power_of_2(j);
        
    }

    return converted;
}