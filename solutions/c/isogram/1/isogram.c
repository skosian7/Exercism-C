 #include "isogram.h"

bool is_isogram(const char phrase[])
{
    if(phrase == NULL) return false;
    if(strlen(phrase)== 0) return true;

    int len = (int)strlen(phrase); 
    char temp;

    for(int i = 1; i < len; i++)
    {
        temp = phrase[i];
        if((temp >=65 && temp <= 90) || (temp >=97 && temp <= 122))
        {
            for(int j = 0; j < i; j++)
            {
                if((phrase[j] == temp) || (phrase[j] == (temp - 32)) || (phrase[j] == (temp + 32))) return false;
            }
        }
        
    }

    return true;

}