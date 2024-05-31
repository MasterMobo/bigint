#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "bigint/BigInt.h"

BigInt BigInt::operator+(BigInt & other)
{	
	if (this->radix != other.radix) {
		throw std::invalid_argument("Radix don't match");
	}

	std::vector<BigInt::BaseType> res;

	std::vector<BigInt::BaseType>::reverse_iterator thisRit = this->digits.rbegin();
	std::vector<BigInt::BaseType>::reverse_iterator otherRit = other.digits.rbegin();

	std::vector<BigInt::BaseType>::reverse_iterator thisEnd = this->digits.rend();
	std::vector<BigInt::BaseType>::reverse_iterator otherEnd = other.digits.rend();

	BigInt::BaseType thisVal = 0;
	BigInt::BaseType otherVal = 0;
		
	BigInt::BaseType carry = 0;
	BigInt::BaseType sum;

	while (thisRit != thisEnd || otherRit != otherEnd){
		sum = carry;

		if (thisRit != thisEnd) {
			thisVal = *thisRit;
			sum += thisVal;
			thisRit++;	
		}

		if (otherRit != otherEnd) {
			otherVal = *otherRit;
			sum += otherVal;
			otherRit++;
		}

		if (sum >= radix) {
			carry = 1;
			sum %= radix;
		} 
		else if (sum < thisVal ||  sum < otherVal) {
			// Overflow for unsigned int
			// Overflow should already be the remainder, so no need to take mod here
			carry = 1;
		}
		else {
			carry = 0;
		}

		res.push_back(sum);
	}

	// Add remaining carry
	if (carry != 0) {
		res.push_back(carry);
	}

	std::reverse(res.begin(), res.end());

	return BigInt(res, this->radix);
}