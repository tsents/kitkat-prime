#include "primer.h"


bool primeMillerRabin(long long num, int accaracy) {
    if ((num & 1) == 0) {
        // num is even
        return false;
    }
    long long base2Power = factor2Power(num - 1); 
    long long remainder = num >> base2Power; // should be odd

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(2, num - 2);

    for (int k = 0; k < accaracy; k++) {
        long long base = distrib(gen);
        if (witnessMillerRabin(num, base2Power, remainder, base) == false) {
            std::cout << "witness " << base << std::endl;
            return false;
        }
    }
    return true;
}


bool witnessMillerRabin(long long num, long long base2Power, long long remainder, long long base) {
    long long test = safeBasedPow(base, remainder, num);
    if (test == 1 || test == num - 1) {
        return true;
    }
    for (long long s = 0; s < base2Power; s++) {
        test = (test * test) % num;
        if (test == 1) {
            return false;
        }
        if (test == num - 1) {
            return true;
        }
    }
    return false;
}

long long safeBasedPow(long long base, long long pow, long long mod) {
    long long result = 1;
    for (long long i = 0; i < pow; i++) {
        result = (result * base) % mod;
    }
    return result;
}

long long factor2Power(long long num) {
    long long power = 0;
    while ((num & 1) == 0) {
        num = num >> 1;
        power++;
    }
    return power;
}
