#include "bigint/BigInt.h"
#include "bigint/utils.h"

#include <iostream>
#include <vector>

void BigInt::subtractDigits(BaseType n1, BaseType n2, BaseType& diff, int& carry) {
    if (n1 >= n2 + carry) {
        diff = n1 - (n2 + carry);
        carry = 0;
    }
    else {
        diff = RADIX - (n2 + carry - n1);
        carry = 1;
    }
};

BigInt BigInt::subtractAbs(const BigInt& n1, const BigInt& n2) {
    /*
        Subtract the absolute value of the bigger number from the smaller one.
    */
    BigInt res = BigInt();
    res.sign = 1;

    std::vector<BaseType> bigger = n1.digits;
    std::vector<BaseType> smaller = n2.digits;

    if (n1 < n2) {
        res.sign = -1;

        bigger = n2.digits;
        smaller = n1.digits;
    }

    std::vector<BaseType> resDigits (bigger.size(), 0);

    int carry = 0;
    BaseType diff;

    for (int i = 0; i < smaller.size(); i++) {
        subtractDigits(bigger[i], smaller[i], diff, carry);
        resDigits[i] = diff;
    } 

    for (size_t i = smaller.size(); i < bigger.size(); i++) {
        subtractDigits(bigger[i], 0, diff, carry);
        resDigits[i] = diff;
    }

    res.digits = pruneTrailingZeros(resDigits);
    return res;
};


BigInt BigInt::operator-(const BigInt& other) {
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
    return subtractAbs(*this, other);
}

// Invert sign
BigInt BigInt::operator-() const {
    BigInt negated = *this;
    negated.sign = -negated.sign; 
    return negated;
}

BigInt BigInt::operator-=(const BigInt& other) {
	*this = *this - other;
	return *this;
}

// Prefix decrement
BigInt& BigInt::operator--() {
    *this = *this - BigInt("1");
	return *this;
} 

// Postfix decrement
BigInt BigInt::operator--(int n) {
	BigInt prev = *this;

	BigInt other;
	if (n != 0) {
		other = BigInt(std::to_string(n));
	} else {
		other = BigInt("1");
	}

	*this = *this - other;

	return prev;
}	