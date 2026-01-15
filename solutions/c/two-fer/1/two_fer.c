#include "two_fer.h"

void two_fer(char *buffer, const char *name)
{
    if(name == NULL)
    {
        char no_name[] = "One for you, one for me.";
        for(int i = 0; i < 24; i++)
        {
            buffer[i] = no_name[i];
        } 
        buffer[24] = '\0';
    }else
    { 
        int i, j;
        int null_terminator_index = 21 + strlen(name);
        
        //first part
        char first_part[] = "One for ";
        for(i = 0; i < 8; i++)
        {
            buffer[i] = first_part[i];
        }

        //name
        int len = strlen(name);
        for(i = 8, j = 0; j <= len; i++, j++)
        {
            buffer[i] = name[j];
        }

        //second part
        char second_part[] = ", one for me.";
        for(i = len + 8, j = 0; i < null_terminator_index; i++, j++)
        {
            buffer[i] = second_part[j];
        }
        buffer[null_terminator_index] = '\0';
    }

}
