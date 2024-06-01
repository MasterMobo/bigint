#include <string>

#include "bigint/BigInt.h"

std::string BigInt::toString() {
	std::string s;

	if (sign == -1) {
		s.append("-");
	}

	for (BigInt::BaseType digit: this->digits) {
		s.append(std::to_string(digit));
		s.append(" ");
	}

	return s;
}
