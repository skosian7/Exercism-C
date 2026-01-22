 #include "luhn.h"

bool is_valid(const char *num)
{
    if(strlen(num) <= 1) return false;

    if(strlen(num) == 2)
    {
        int sum = num[0] + num[1];
        if(sum == 80)return false;
    }
    
    int i = 0;
    while(num[i]!= '\0')
    {
        if(num[i] != 32 && (num[i] < 48 || num[i] > 57))return false;
        i++;
    }
    return true;
}


bool luhn(const char *num)
{
    //check if the string is valid ()
    if(!is_valid(num))return false;
    //remove spaces and create an int arr
    int i = 0, j = 0;
    int my_num[strlen(num)];

    while(num[i] != '\0')
    {
        if(num[i] >= 48 && num[i] <= 57)
        {
            my_num[j] = (int)num[i] - 48;
            j++;
        }
        i++;
    }
    int last_index = j - 1;

     

    //check according to Luhn alg.
    // double every second digit
    int temp = 0;
    for(i = last_index - 1; i >= 0; i-=2)
    {
        temp = my_num[i] * 2;
        if(temp > 9)temp -= 9;
        my_num[i] = temp;
    }

    //sum the digits
    int summ = 0;
    for(i = 0; i <= last_index; i++)
    {
        summ += my_num[i];
    }
    
    return summ%10 == 0;
}
