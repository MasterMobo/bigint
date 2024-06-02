#include <iostream>

#include "bigint/BigInt.h"

BigInt BigInt::operator-(const BigInt& other) {
    // FIXME: The most braindead code possible
    if (this->sign == -1) {
        if (other.sign == 1) {
            BigInt res = sumAbs(*this, other);
            res.sign = -1;
            return res;
        }

        return -other - (-*this);
    }
    else {
        if (other.sign == -1) {
            return sumAbs(*this, other);
        }
    }

    // Only possible case left is if both are positive

    BigInt res = BigInt();
    res.sign = 1;


    std::vector<BaseType> bigger = this->digits;
    std::vector<BaseType> smaller = other.digits;

    if (*this < other) {
        res.sign = -1;

        bigger = other.digits;
        smaller = this->digits;
    }

    std::vector<BaseType> resDigits (bigger.size(), 0);

    char carry = 0;
    BaseType diff;

    for (int i = 0; i < smaller.size(); i++) {
        BaseType n1 = bigger[i];
        BaseType n2 = smaller[i];

        // TODO: watch out for overflow n2 + carry
        if (n1 >= n2 + carry) {
            diff = n1 - (n2 + carry);
            carry = 0;
        }
        else {
            diff = RADIX - (n2 + carry - n1);
            carry = 1;
        }

        resDigits[i] = diff;
    } 

    for (size_t i = smaller.size(); i < bigger.size(); i++) {
        BaseType n1 = bigger[i];

        if (n1 >= carry) {
            diff = n1 - carry;
            carry = 0;
        }
        else {
            diff = RADIX - (carry - n1);
            carry = 1;
        }

        resDigits[i] = diff;
    }

    // TODO: Need to remove trailing 0's
    res.digits = resDigits;
    return res;
}

BigInt BigInt::operator-() const {
    BigInt negated = *this;
    negated.sign = -negated.sign; 
    return negated;
}