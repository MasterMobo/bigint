#include <vector>
#include <iostream>

#include "bigint/BigInt.h"

void BigInt::addDigits(BigInt::BaseType n1, BigInt::BaseType n2, BigInt::BaseType& sum, int& carry, BigInt::BaseType radix) {
	sum = n1 + n2 + carry;
	carry = 0;

	if (sum >= radix || sum < n1) {
		// sum < n1 (or equivalently, sum < n2) when overflow for unsigned int
		carry = 1;
	}

	sum %= radix;
}

BigInt BigInt::operator+(const BigInt& other)
{	
	if (this->radix != other.radix) {
		throw std::invalid_argument("Radix don't match");
	}


	std::vector<BigInt::BaseType> longer = this->digits;
	std::vector<BigInt::BaseType> shorter = other.digits;

	if (this->digits.size() < other.digits.size()) {
		longer = other.digits;
		shorter = this->digits;
	}

	size_t longerS = longer.size();
	size_t shorterS = shorter.size();

	std::vector<BigInt::BaseType> res (longerS, 0);

	int carry = 0;
	BigInt::BaseType sum;

	for (size_t i = 0; i < shorterS; i++) {
		size_t shorti = shorterS - i - 1;
		size_t longi = longerS - i - 1;

		addDigits(longer[longi], shorter[shorti], sum, carry, radix);

		res[longi] = sum;
	}

	for (size_t i = shorterS; i < longerS; i++) {
		size_t longi = longerS - i - 1;

		addDigits(longer[longi], 0, sum, carry, radix);

		res[longi] = sum;
	}

	// Add remaining carry
	if (carry != 0) {
		res.insert(res.begin(), carry);
	}

	return BigInt(res, this->radix);
}

BigInt BigInt::operator+=(const BigInt& other) {
	*this = *this + other;
	return *this;
}

// Prefix increment
BigInt& BigInt::operator++() {
	// TODO: this is just stupid

	std::vector<BigInt::BaseType> v;

	v.push_back(1);
	BigInt one = BigInt(v, radix);

	*this = *this + one;

	return *this;
};

// Postfix increment
BigInt BigInt::operator++(int n) {
	// TODO: this is just stupid
	BigInt prev = *this;

	std::vector<BigInt::BaseType> v;

	if (n != 0) {
		v.push_back(n);
	} else {
		v.push_back(1);
	}
	BigInt other = BigInt(v, radix);

	*this = *this + other;

	return prev;
};
