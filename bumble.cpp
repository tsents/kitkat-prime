#include "bumble.h"
#include "primer.h"


void findPrimes(unsigned int primeCount, unsigned long long *primes) {
    unsigned int foundPrimes = 0;
    for (unsigned long long runner = 2; foundPrimes < primeCount; runner++) {        
        if (checkPrime(runner) == true) {
            primes[foundPrimes] = runner;
            foundPrimes++;
        }
    }
} 
