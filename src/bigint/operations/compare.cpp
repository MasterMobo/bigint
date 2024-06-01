#include <vector>
#include <iostream>

#include "bigint/BigInt.h"

signed char BigInt::compareAbs(const BigInt& n1, const BigInt& n2) {
    /*
    Compare absolute value of two BigInt.
    Returns:
        -1 if n1 < n2
        0 if n1 == n2
        1 if n1 > n2
    */

    if (n1.digits.size() > n2.digits.size()) return 1;
    if (n1.digits.size() < n2.digits.size()) return -1;

    for (size_t i = 0; i < n1.digits.size(); i++) {
        if (n1.digits[i] < n2.digits[i]) {
            return -1;
        } else if (n1.digits[i] > n2.digits[i]) {
            return 1;
        };
    }

    return 0;
}

bool BigInt::operator==(const BigInt& other) {
    if (this->sign != other.sign) return false;

    return compareAbs(*this, other) == 0;
}

bool BigInt::operator!=(const BigInt& other) {
    return !(*this == other);
}

bool BigInt::operator>(const BigInt& other) {
    if (this->sign != other.sign)
        return this->sign > other.sign;

    signed char absComparison = compareAbs(*this, other);

    // If both are negative, this > other when |this| < |other|
    if (this->sign == -1) {
        return absComparison == -1;
    }

    return absComparison == 1;
}


bool BigInt::operator>=(const BigInt& other) {
    if (this->sign != other.sign)
        return this->sign > other.sign;

    signed char absComparison = compareAbs(*this, other);

    // If both are negative, this >= other when |this| <= |other|
    if (this->sign == -1) {
        return absComparison <= 0;
    }

    return absComparison >= 0;
}

bool BigInt::operator<(const BigInt& other) {
    return !(*this >= other);
}

bool BigInt::operator<=(const BigInt& other) {
    return !(*this > other);
}
