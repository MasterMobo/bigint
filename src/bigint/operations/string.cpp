#include <string>
#include <iostream>
#include <climits>

#include "bigint/BigInt.h"

std::string BigInt::toString() {
	std::string s;

	if (sign == -1) {
		s.append("-");
	}

	for (int i = digits.size() - 1; i >= 0; i--) {
		s.append(std::to_string(digits[i]));
		s.append(" ");
	}

	return s;
}

BigInt BigInt::fromBinString(std::string s) {
	const int len = s.length();
	const int baseTypeSize = BITS_PER_DIGIT;
	const int wholeParts = len / baseTypeSize;
	const int leftOver = len % baseTypeSize;

	std::vector<BaseType> digits (wholeParts + (leftOver ? 1 : 0), 0);
	BaseType currentDigit;

	if (leftOver != 0) {
		std::string sub = s.substr(0, leftOver );

		// Pad 0's to beginning to make length 32  
		unsigned int number_of_zeros = baseTypeSize - sub.length();
		sub.insert(0, number_of_zeros, '0');

		BaseType val = std::stoul(sub, 0, 2);

		digits[digits.size() - 1] = val;
	}

	for (int i = 0; i < wholeParts; i++) {
		std::string sub = s.substr(i * baseTypeSize + leftOver, baseTypeSize);

		int ind = digits.size() - i - 1 - (leftOver? 1 : 0);

		BaseType val = std::stoul(sub, 0, 2);

		digits[ind] = val;
	}

	return BigInt(digits);
}

std::string BigInt::toBinString() {
	std::string s;
	return s;
}