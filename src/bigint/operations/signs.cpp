#include "bigint/BigInt.h"

void BigInt::makePositive() {
    sign = 1;
}

void BigInt::makeNegative() {
    sign = -1;
}