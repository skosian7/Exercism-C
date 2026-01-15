#include "hamming.h"

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

int compute(const char *lhs, const char *rhs)
{
    int length_l = length(lhs);
    int length_r = length(rhs);

    if(length_l != length_r) return -1;
    if(length_l == 0) return 0;

    int hamming_distance = 0;
    for(int i = 0; i < length_l; i++)
    {
        if(lhs[i] != rhs[i]) hamming_distance++;
    }
    
    return hamming_distance;
}
