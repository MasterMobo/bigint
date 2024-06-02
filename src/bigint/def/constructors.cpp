#include <vector>
#include <string>

#include "bigint/BigInt.h"


BigInt::BigInt() {}

BigInt::BigInt(std::vector<BaseType> digits) : digits(digits) {}

BigInt::BigInt(std::string s) {
    *this = BigInt::fromDecString(s);
}