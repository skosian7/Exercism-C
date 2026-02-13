 #include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    size_t stored = 0;
    

    if (n < 2) return 0;

    /* extract factors of 2 */
    while ((n & 1ULL) == 0ULL) {
        
        if (stored < MAXFACTORS) {
            factors[stored++] = 2;
        }
        n >>= 1;
    }

    
    /* trial division by odd numbers, using `i <= n / i` to avoid overflow */
    for (uint64_t i = 3; i <= n / i; i += 2) {
        while (n % i == 0) {
            
            if (stored < MAXFACTORS) {
                factors[stored++] = i;
            }
            n /= i;
        }
    }
    
    /* if remaining n is > 1 it's a prime factor */
    if (n > 1) {
        
        if (stored < MAXFACTORS) {
            factors[stored++] = n;
        }
    }
    
    return stored;     
}