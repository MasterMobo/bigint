#include <vector>
#include <string>

#include "bigint/BigInt.h"

std::vector<BigInt::BaseType> BigInt::fromString(std::string s) {
	std::vector<BigInt::BaseType> res;

	for (int i = 0; i < s.length(); i++) {
		res.push_back(s[i] - '0');
	}

	return res;
}