#include "bigint/BigInt.h"

#include <iostream>
#include <vector>
#include <climits>
#include <string>


int main() {

    BigInt n1 = BigInt::fromDecString("2384927348912739812361298361293182301231239812312312312309452345923450923450923485230945823453245");
    // n1.makeNegative();
    // std::cout << n1.toRawString() << std::endl;
    // std::cout << n1.toBinString() << std::endl;
    std::cout << n1.toDecString() << std::endl;


    BigInt n2 = BigInt::fromDecString("12312371286318273612305435349057289364237894623874623487236428374612039128310293812312324234");
    // n2.makeNegative();
    // std::cout << n2.toRawString() << std::endl;
    std::cout << n2.toDecString() << std::endl;


    BigInt n3 = n1 + n2;
    std::cout << n3.toDecString() << std::endl;

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
