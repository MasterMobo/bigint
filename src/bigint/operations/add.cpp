#include <vector>
#include <iostream>

#include "bigint/BigInt.h"

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

	size_t longer_s = longer.size();
	size_t shorter_s = shorter.size();

	std::vector<BigInt::BaseType> res (longer_s, 0);

	int carry = 0;
	BigInt::BaseType sum;

	for (size_t i = 0; i < shorter_s; i++) {
		size_t shorti = shorter_s - i - 1;
		size_t longi = longer_s - i - 1;

		addDigits(longer[longi], shorter[shorti], sum, carry, radix);

		res[longi] = sum;
	}

	for (size_t i = shorter_s; i < longer_s; i++) {
		size_t longi = longer_s - i - 1;

		addDigits(longer[longi], 0, sum, carry, radix);

		res[longi] = sum;
	}

	// Add remaining carry
	if (carry != 0) {
		res.insert(res.begin(), carry);
	}

	return BigInt(res, this->radix);
}

void BigInt::addDigits(BigInt::BaseType n1, BigInt::BaseType n2, BigInt::BaseType& sum, int& carry, BigInt::BaseType radix) {
	sum = n1 + n2 + carry;
	carry = 0;

	if (sum >= radix || sum < n1) {
		// sum < n1 (or equivalently, sum < n2) when overflow for unsigned int
		carry = 1;
	}

	sum %= radix;
}
