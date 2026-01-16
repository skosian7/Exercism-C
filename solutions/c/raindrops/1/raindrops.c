#include "raindrops.h"

void convert(char result[], int drops)
{
    int count = 0;

    if(drops%3 == 0)
    {
        strcat(result,raindrops[0]);
        count ++;
    } 
    if(drops%5 == 0)
    {
        strcat(result, raindrops[1]);
        count++;
    } 
    if(drops%7 == 0)
    {
        strcat(result, raindrops[2]);
        count++;
    } 

    if (count != 0) return;

    int i = 0, tempI = drops;
    char tempC;
    char tempA[64];
    while(tempI%10 != 0)
    {
        tempC = tempI%10 + '0';
        tempA[i] = tempC;
        i++;
        tempI /= 10;
    }
    
    //reverse result[]
    int len = i;
    i--;
    for(int j = 0; j < len; j++, i--)
    {
        result[j] = tempA[i];
    }


}
