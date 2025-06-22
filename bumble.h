#pragma once


/*
 * Finds primes based on the primer.h prime checking, and some simple huristics.
 *
 * primeCount [IN] the number of primes to find
 * primes     [OUT] the array to fill with primes. assumed to be of length >= primeCount.
 */
void findPrimes(unsigned int primeCount, unsigned long long *primes);
