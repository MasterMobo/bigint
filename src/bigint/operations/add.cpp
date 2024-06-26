#include "bigint/BigInt.h"

#include <vector>
#include <iostream>


BigInt BigInt::sumAbs(const BigInt& n1, const BigInt& n2) {
	/*
		Adds the absolute value of two BigInt.
		Returns: The sum of the absolute value of two BigInt
	*/
	std::vector<BaseType> longer = n1.digits;
	std::vector<BaseType> shorter = n2.digits;

	if (n1.digits.size() < n2.digits.size()) {
		longer = n2.digits;
		shorter = n1.digits;
	}

	std::vector<BaseType> res (longer.size(), 0);

	int carry = 0;
	BaseType sum;

	for (size_t i = 0; i < shorter.size(); i++) {
		addDigits(longer[i], shorter[i], sum, carry);
		res[i] = sum;
	}

	for (size_t i = shorter.size(); i < longer.size(); i++) {
		addDigits(longer[i], 0, sum, carry);
		res[i] = sum;
	}

	// Add remaining carry
	if (carry != 0) {
		res.push_back(carry);
	}

	return BigInt(res);
}


void BigInt::addDigits(BaseType n1, BaseType n2, BaseType& sum, int& carry) {
	sum = n1 + n2 + carry;
	carry = 0;

	if (sum >= RADIX) {
		carry = 1;
	}

	sum %= RADIX;
}

BigInt BigInt::operator+(const BigInt& other) {	
	if (this->sign == -1) {
		if (other.sign == -1) {
			BigInt res = sumAbs(*this, other);
			res.sign = -1;
			return res;
		}
	
		BigInt temp = other;
		return temp - (- *this);
	}
	else {
		if (other.sign == -1) {
			return *this - (-other);
        }
	}

	return sumAbs(*this, other);
}

BigInt BigInt::operator+=(const BigInt& other) {
	*this = *this + other;
	return *this;
}

// Prefix increment
BigInt& BigInt::operator++() {
	*this = *this + BigInt("1");
	return *this;
};

// Postfix increment
BigInt BigInt::operator++(int n) {
	BigInt prev = *this;

	BigInt other;
	if (n != 0) {
		other = BigInt(std::to_string(n));
	} else {
		other = BigInt("1");
	}

	*this = *this + other;

	return prev;
};
