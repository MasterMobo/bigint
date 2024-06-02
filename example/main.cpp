#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>
#include <string>

std::string makeMax(int numDigits) {
    std::string s;
    for (int i = 0; i < numDigits; i++) {
        s.append("1");
    }
    return s;
}

std::string makeOneHead(int numDigits) {
    std::string s;
    s.append("1");
    for (int i = 1; i < numDigits; i++) {
        s.append("0");
    }
    return s;
}

int main() {
    BigInt n1 = BigInt::fromBinString(makeMax(2048));
    // std::vector<BigInt::BaseType> v1;
    // v1.push_back(4294967295);
    // BigInt n1 = BigInt(v1);
    // // n1.makeNegative();
    std::cout << n1.toString() << std::endl;


    BigInt n2 = BigInt::fromBinString("1");

    // std::vector<BigInt::BaseType> v2;
    // v2.push_back(1);
    // BigInt n2 = BigInt(v2);
    // // n2.makeNegative();
    std::cout << n2.toString() << std::endl;


    BigInt n3 = n1 + n2;
    std::cout << n3.toString() << std::endl;

    // std::cout << n1.toString() << std::endl;
    // std::cout << (++n1).toString() << std::endl;
    // std::cout << n1++.toString() << std::endl;
    // std::cout << n1.toString() << std::endl;
    
    // std::cout << (n1 == n2) << std::endl;
    // std::cout << (n1 != n2) << std::endl;
    // std::cout << (n1 > n2) << std::endl;
    // std::cout << (n1 >= n2) << std::endl;
    // std::cout << (n1 < n2) << std::endl;
    // std::cout << (n1 <= n2) << std::endl;

    return 0;
}
