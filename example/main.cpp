#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>
#include <string>


int main() {
    BigInt n1 = BigInt("845096809452863463230957232187610417423524983403475235823059723059723095723235");
    // n1.makeNegative();
    // std::cout << n1.toRawString() << std::endl;
    // std::cout << n1.toBinString() << std::endl;
    // std::cout << n1.toDecString() << std::endl;


    BigInt n2 = BigInt("2342384092834092375023940295840395683490673498572986429384723095230957230957235982365298352398742398");
    // n2.makeNegative();
    // std::cout << n2.toRawString() << std::endl;
    // std::cout << n2.toDecString() << std::endl;

    BigInt n3 = n1 - n2;
    std::cout << n3.toDecString() << std::endl;
    std::cout << std::endl;
    std::cout << n3.toBinString() << std::endl;
    std::cout << std::endl;
    std::cout << n3.toRawString() << std::endl;

    // std::cout << n1.toRawString() << std::endl;
    // std::cout << (++n1).toRawString() << std::endl;
    // std::cout << n1++.toRawString() << std::endl;
    // std::cout << n1.toRawString() << std::endl;
    
    // std::cout << (n1 == n2) << std::endl;
    // std::cout << (n1 != n2) << std::endl;
    // std::cout << (n1 > n2) << std::endl;
    // std::cout << (n1 >= n2) << std::endl;
    // std::cout << (n1 < n2) << std::endl;
    // std::cout << (n1 <= n2) << std::endl;

    return 0;
}
