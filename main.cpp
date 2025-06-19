#include "primer.h"
#include <iostream>

int main() {
    std::cout << primeMillerRabin(15485863, 10) << std::endl; //very large prime
    std::cout << primeMillerRabin(15485861, 10) << std::endl;
    return 0;
}
