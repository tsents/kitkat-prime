#include "primer.h"
#include <iostream>

int main() {
    std::cout << checkPrime(15485863) << std::endl; // very large prime
    std::cout << checkPrime(15485861) << std::endl;
    std::cout << checkPrime(3) << std::endl;
    std::cout << checkPrime(8209) << std::endl;
    return 0;
}
