#include <vector>
#include <iostream>

#include "bigint/BigInt.h"

bool BigInt::operator==(const BigInt& other) {
    if (this->digits.size() != other.digits.size()) return false;

    for (size_t i = 0; i < this->digits.size(); i++) {
        if (this->digits[i] != other.digits[i]) {
            return false;
        } 
    }

    return true;
}

bool BigInt::operator!=(const BigInt& other) {
    return !(*this == other);
}

bool BigInt::operator>(const BigInt& other) {
    if (this->digits.size() > other.digits.size()) return true;
    if (this->digits.size() < other.digits.size()) return false;

    for (size_t i = 0; i < this->digits.size(); i++) {
        if (this->digits[i] < other.digits[i]) {
            return false;
        } else if (this->digits[i] > other.digits[i]) {
            return true;
        };
    }

    return false;
}

bool BigInt::operator>=(const BigInt& other) {
    if (this->digits.size() > other.digits.size()) return true;
    if (this->digits.size() < other.digits.size()) return false;

    for (size_t i = 0; i < this->digits.size(); i++) {
        if (this->digits[i] < other.digits[i]) {
            return false;
        } else if (this->digits[i] > other.digits[i]) {
            return true;
        };
    }

    return true;
}

bool BigInt::operator<(const BigInt& other) {
    return !(*this >= other);
}

bool BigInt::operator<=(const BigInt& other) {
    return !(*this > other);
}
