#include "rna_transcription.h"

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

char transcribed(char dna)
{
    char rna;
    switch (dna)
    {
    case 65:
        rna = 'U';
        break;
    case 67:
        rna = 'G';
        break;
    case 71:
        rna = 'C';
        break;
    case 84:
        rna = 'A';
        break;
    default:
        break;
    }
    
    return rna;
}

char *to_rna(const char *dna)
{
    int len = length(dna);
    char *rna = (char *)malloc((len) * sizeof(char));

    if(len == 0) return rna;

    for(int i = 0; i<len; i++)
    {
        rna[i] = transcribed(dna[i]);
    }

    return rna;
}