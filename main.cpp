#include "bumble.h"
#include <iostream>

const unsigned int PRIME_COUNT = 10000;

int main() {
    unsigned long long *primesArray = new unsigned long long[PRIME_COUNT];
    findPrimes(PRIME_COUNT, primesArray);

    for (unsigned int i = 0; i < PRIME_COUNT; i++) {
        std::cout << primesArray[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}
