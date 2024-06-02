#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>
#include <string>

int main() {
    std::vector<BigInt::BaseType> v1;
    v1.push_back(7);
    BigInt n1 = BigInt(v1, 10);
    // n1.makeNegative();
    std::cout << n1.toString() << std::endl;


    std::vector<BigInt::BaseType> v2;
    v2.push_back(5);
    v2.push_back(1);
    BigInt n2 = BigInt(v2, 10);
    // n2.makeNegative();
    std::cout << n2.toString() << std::endl;


    BigInt n3 = n1 - n2;
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
