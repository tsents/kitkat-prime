#include "bumble.h"
#include "primer.h"

/*
 * This is the max number of primes to check for the findPrimes filtering.
 * In testing it showed 10% improve in speed
 */
const unsigned int FIND_FILTER = 50; 

void findPrimes(unsigned int primeCount, unsigned long long *primes) {
    unsigned int foundPrimes = 0;
    if (primeCount > 0) {
        foundPrimes++;
        primes[0] = 2;
    }
    for (unsigned long long runner = 3; foundPrimes < primeCount; runner += 2) {        
        if (checkComposite(runner, primes, std::min(foundPrimes, FIND_FILTER)) == true) {
            continue;
        }
        if (checkPrime(runner) == true) {
            primes[foundPrimes] = runner;
            foundPrimes++;
        }
    }
} 

bool checkComposite(unsigned long long runner, unsigned long long *primes, unsigned int check) {
    for (unsigned int i = 0; i < check; i++) {
        if (runner % primes[i] == 0) {
            return true;
        }
    }
    return false;
}
