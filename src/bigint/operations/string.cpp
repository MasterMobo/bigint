#include "bigint/BigInt.h"
#include "../utils/utils.h"

#include <string>
#include <iostream>
#include <climits>
#include <bitset>

std::string BigInt::toRawString() {
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
	// TODO: Remove leading zeros and check for signs
	const int len = s.size();
	const int baseTypeSize = BITS_PER_DIGIT;
	const int wholeParts = len / baseTypeSize;
	const int leftOver = len % baseTypeSize;

	std::vector<BaseType> digits (wholeParts + (leftOver ? 1 : 0), 0);
	BaseType currentDigit;

	if (leftOver != 0) {
		std::string sub = s.substr(0, leftOver);

		// Pad 0's to beginning to make length 32  
		sub = padLeadingZeros(sub, 32);

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
	for (int i = digits.size() - 1; i >= 0; i--) {
		std::string chunk = std::bitset<BITS_PER_DIGIT>(digits[i]).to_string(); // Assuming int is 8 bits
		chunk = padLeadingZeros(chunk, 32);

		s.append(chunk);
	}
	return pruneLeadingZeros(s);
}

BigInt BigInt::fromDecString(std::string s) {
	// TODO: Remove leading zeros and check for signs

	return fromBinString(decToBin(s));
}

std::string BigInt::toDecString() {
	std::string s (sign == -1 ? "-" : "");
	s.append(binToDec(toBinString())); 
	return s;
};
