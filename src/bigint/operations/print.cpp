#include <iostream>

#include "bigint/BigInt.h"

void BigInt::display() {
	for (BigInt::BaseType digit: this->digits) {
		std::cout << digit << " ";
	}

	std::cout << std::endl;
}
