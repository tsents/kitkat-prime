#include "primer.h"

bool checkPrime(unsigned long long num) {
    if (num < SMALL_NUMBER) {
        return simplePrime(num);
    }
    return primeMillerRabin(num, DEFAULT_ACCARACY);
}

bool simplePrime(unsigned long long num) {
    //    std::cout << "Simple check " << num << std::endl;
    for (unsigned long long i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool primeMillerRabin(unsigned long long num, int accaracy) {
    if ((num & 1) == 0) {
        // num is even
        return false;
    }
    unsigned long long base2Power = factor2Power(num - 1);
    unsigned long long remainder = num >> base2Power; // should be odd

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(2, num - 2);

    for (int k = 0; k < accaracy; k++) {
        unsigned long long base = distrib(gen);
        if (witnessMillerRabin(num, base2Power, remainder, base) == false) {
            //           std::cout << "witness " << base << std::endl;
            return false;
        }
    }
    return true;
}

bool witnessMillerRabin(unsigned long long& num, unsigned long long& base2Power, unsigned long long& remainder,
                        unsigned long long& base) {
    unsigned long long test = safeBasedPow(base, remainder, num);
    if (test == 1 || test == num - 1) {
        return true;
    }
    for (unsigned long long s = 0; s < base2Power; s++) {
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

unsigned long long safeBasedPow(unsigned long long& base, unsigned long long& pow, unsigned long long& mod) {
    unsigned long long result = 1;
    for (unsigned long long i = 0; i < pow; i++) {
        result = (result * base) % mod;
    }
    return result;
}

unsigned long long factor2Power(unsigned long long num) {
    unsigned long long power = 0;
    while ((num & 1) == 0) {
        num = num >> 1;
        power++;
    }
    return power;
}
