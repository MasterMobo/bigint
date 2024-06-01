#include <iostream>

#include "bigint/BigInt.h"

BigInt BigInt::operator-(const BigInt& other) {
    if (this->radix != other.radix) {
		throw std::invalid_argument("Radix don't match");
	}

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

    BigInt res = BigInt(radix);
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

    for (size_t i = 0; i < smaller.size(); i++) {
        size_t smalli = smaller.size() - i - 1;
        size_t bigi = bigger.size() - i - 1;

        BaseType n1 = bigger[bigi];
        BaseType n2 = smaller[smalli];

        // TODO: watch out for overflow n2 + carry

        if (n1 >= n2 + carry) {
            diff = n1 - (n2 + carry);
            carry = 0;
        }
        else {
            diff = radix - (n2 + carry - n1);
            carry = 1;
        }

        resDigits[bigi] = diff;
    } 

    for (size_t i = smaller.size(); i < bigger.size(); i++) {
        size_t bigi = bigger.size() - i - 1;

        BaseType n1 = bigger[bigi];
        // TODO: watch out for overflow n2 + carry

        if (n1 >= carry) {
            diff = n1 - carry;
            carry = 0;
        }
        else {
            diff = radix - (carry - n1);
            carry = 1;
        }

        resDigits[bigi] = diff;
    } 

    // TODO: Need to remove leading 0's
    res.digits = resDigits;
    return res;
}

BigInt BigInt::operator-() const {
    BigInt negated = *this;
    negated.sign = -negated.sign; 
    return negated;
}