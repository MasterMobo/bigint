#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::vector<BigInt::BaseType> v1;
    v1.push_back(1);
    v1.push_back(ULLONG_MAX - 1);
    BigInt n1 = BigInt(v1, ULLONG_MAX);

    std::vector<BigInt::BaseType> v2;
    v2.push_back(1);
    BigInt n2 = BigInt(v2, ULLONG_MAX);

    BigInt n3 = n1 + n2;
    n3.display();
}