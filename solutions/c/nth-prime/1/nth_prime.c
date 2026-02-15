
#include "nth_prime.h"

uint32_t nth(uint32_t n)
{
    if(n <= 0) return 0;
    if(n == 1) return 2;

    uint32_t count = 0, temp = 2;
    uint32_t nth_prime = temp;
    uint8_t prime_flag = 1;
    
    while(count != n)
    {
        //set the flag if the number is prime
        if(temp <= 3)
        {
            prime_flag = 1;
        }else if((temp%2 == 0) || (temp%3 == 0)){
            prime_flag = 0;
        }else{
            for(uint32_t i = 5; i*i <= temp; i += 6)
            {
                if( (temp%i == 0) || (temp%(i+2) == 0) )
                {
                    prime_flag = 100;
                    break;
                }                 
            }
            
            if(prime_flag != 100) prime_flag = 1;
        }
        
        //check the flag and count prime 
        if(prime_flag == 1) 
        {
            nth_prime = temp;
            count ++;
        }
        temp++;
    }

    return nth_prime;
}