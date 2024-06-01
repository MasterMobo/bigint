#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>
#include <string>

int main() {
    std::vector<BigInt::BaseType> v1;
    v1.push_back(9);
    v1.push_back(9);
    BigInt n1 = BigInt(v1, 10);
    n1.makeNegative();

    std::vector<BigInt::BaseType> v2;
    v2.push_back(5);
    BigInt n2 = BigInt(v2, 10);

    BigInt n3 = n1 + n2;

    std::cout << n1.toString() << std::endl;
    std::cout << n3.toString() << std::endl;
    // std::cout << (n1 == n2) << std::endl;
    // std::cout << (n1 != n2) << std::endl;
    // std::cout << (n1 > n2) << std::endl;
    // std::cout << (n1 >= n2) << std::endl;
    // std::cout << (n1 < n2) << std::endl;
    // std::cout << (n1 <= n2) << std::endl;

    return 0;
}
