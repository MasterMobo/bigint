#include <string>

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
