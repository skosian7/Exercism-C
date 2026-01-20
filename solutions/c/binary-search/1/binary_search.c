#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    
    if(length == 0) return NULL;
    if(length == 1)
    {
        if(value == arr[0]) return &arr[0];
        else return NULL;
    }

    int head = 0;
    int last_index = (int)(length-1);
    int tail = last_index;
    int j;
    
     
    
    while(head <= tail)
    {
        
        j = head + (tail - head)/2;
         
        if(arr[j] == value)
        {
            return &arr[j];
        }
        else if(arr[j] < value)
        {
            head = j + 1;
        }else if(arr[j] > value)
        {
            tail = j - 1;
        }
    
    }

     

    return NULL;
}
