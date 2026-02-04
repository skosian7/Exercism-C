 #include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    if (limit < 2) return 0;

    //write all the numbers between 2 and limit
    uint32_t i, j, primes_count = 0;
    for(i = 0; i <= limit; i++)
    {
        primes[i] = i;
    }

    //look for primes, mark not primes
    for(i=2; i <= limit; i++)
    {
        if(primes[i] != 0) //if the number is not marked
        {
            primes_count ++;
            for(j = i*i; j <= limit; j += i) //I am marking all the multiples
            {
                primes[j] = 0;
            }
        }
    }

    uint32_t my_primes[primes_count];
    
    for(i = 0, j = 2; i < primes_count; j++)
    {
        if(primes[j] != 0)
        {
            my_primes[i] = primes[j];
            i++;
        }
    }
    
    
    for(i = 0; i < primes_count; i++)
    {
        primes[i] = my_primes[i];
    }
    
    for (i = primes_count; i < max_primes; i++)
    {
        primes[i] = 0;
    }

    if(primes_count > max_primes)return (uint32_t)max_primes;
    return primes_count;

}