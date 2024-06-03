#include "bigint/BigInt.h"
#include "../utils/utils.h"

#include <string>
#include <climits>
#include <bitset>

std::string BigInt::toBinString() {
	std::string s;

	for (int i = digits.size() - 1; i >= 0; i--) {
		std::string chunk = std::bitset<BITS_PER_DIGIT>(digits[i]).to_string();
		s.append(chunk);
	}

	return pruneLeadingZeros(s);
}

std::string BigInt::toDecString() {
	std::string s (sign == -1 ? "-" : "");
	s.append(binToDec(toBinString())); 
	return s;
};

std::string BigInt::toRawString() {
	std::string s = sign == -1 ? "-" : "";

	for (int i = digits.size() - 1; i >= 0; i--) {
		s.append(std::to_string(digits[i]));
		s.append(" ");
	}

	return s;
}
