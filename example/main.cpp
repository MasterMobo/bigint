#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::vector<BigInt::BaseType> v1;
    v1.push_back(1);
    v1.push_back(2);
    BigInt n1 = BigInt(v1, 10);

    std::vector<BigInt::BaseType> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(2);
    BigInt n2 = BigInt(v2, 10);

    std::cout << (n1 == n2) << std::endl;
    std::cout << (n1 != n2) << std::endl;
    std::cout << (n1 > n2) << std::endl;
    std::cout << (n1 >= n2) << std::endl;
    std::cout << (n1 < n2) << std::endl;
    std::cout << (n1 <= n2) << std::endl;

    return 0;
}
