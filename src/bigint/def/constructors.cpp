#include <vector>
#include <string>
#include <climits>

#include "bigint/BigInt.h"


BigInt::BigInt() {}

BigInt::BigInt(std::vector<BaseType> digits) : digits(digits) {}
