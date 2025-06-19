#pragma once

#include <iostream>
#include <random>


const int DEFAULT_ACCARACY = 10; // 4 ^ -10 accaracy.


/**
 * Check if the number is prime according to MillerRabin test.
 * This is a probalistic test, thus we need to choose acceracy.
 * Its accaracy is 4^-k, where k is the number of iterations.
 */
bool primeMillerRabin(unsigned long long num, int accaracy);


/**
 * Factor the given num into 2^s * d
 */
unsigned long long factor2Power(unsigned long long num);


/**
 * Calculates (base ^ pow) % (mod), but instead of in one go, takes modulo at
 * each iteration of _ * base. this allows us to avoid overflows more easly.
 */
unsigned long long safeBasedPow(unsigned long long &base, unsigned long long &pow, unsigned long long &mod);


/**
 * Checks if the number (base) is a witness of the conpositability of (num).
 * It is also passed base2Power and remainder. which are the decomposition of num
 * into base 2 powers. this is done to avoid recalculating
 */
bool witnessMillerRabin(unsigned long long &num, unsigned long long &base2Power, unsigned long long &remainder, unsigned long long &base);

