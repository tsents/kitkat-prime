#pragma once


/*
 * Finds primes based on the primer.h prime checking, and some simple huristics.
 *
 * primeCount [IN] the number of primes to find
 * primes     [OUT] the array to fill with primes. assumed to be of length >= primeCount.
 */
void findPrimes(unsigned int primeCount, unsigned long long *primes);


/*
* Checks the compisitness of "runner" based on the first "check" primes.
*
* This is a helper function for findPrimes to help filter primes based on small integers [the first (check) primes]
* Returns true if the runner is composite. and false if it might be a prime.
*/
bool checkComposite(unsigned long long runner, unsigned long long *primes, unsigned int check);
