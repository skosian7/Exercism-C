#include "pangram.h"

short int* alphabet_0()
{
    short int* al_0 = malloc(sizeof(short int)*26);
    for(int i = 0; i < 26; i++)
    {
        al_0[i] = 0;
    }

    return al_0;
}

bool sum_26(short int* alphabet)
{   
    short int summ = 0;
    for(int i = 0; i < 26; i++)
    {
        summ += alphabet[i];
    }

    return summ == 26;
}

bool is_pangram(const char *sentence)
{
    if(sentence == NULL) return false;
    if(sentence[0] == '\0') return false;
    
    
    int j = 0, i = 0;
    short int *my_alphabet = alphabet_0();
    while(sentence[i] != '\0')
    {
        char temp = sentence[i];
        if(temp >= 65 && temp <=90)
        {
            j = temp - 65;
            my_alphabet[j] = 1;
        }else if(temp >= 97 && temp <= 122)
        {
            j = temp-97;
            my_alphabet[j] = 1;
        }
        i++;
    }
    
    bool is_pangram = sum_26(my_alphabet);
    free(my_alphabet);
    return is_pangram;
} 