#include "reverse_string.h"


char *reverse(const char *value)
{
    //how long is the string
    int len = 0, i = 0, j = 0;
    while(value[i] != '\0')
    {
        len++;
        i++;
    }
    
    char *rev_string = malloc(sizeof(char) * (len));
    rev_string[len] = '\0';

    for(i = len-1; i >=0; i--)
    {
        rev_string[j] = value[i];
        j++;
    }

    return rev_string;
}