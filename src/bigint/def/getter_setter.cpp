#include <vector>
#include <string>

#include "bigint/BigInt.h"

std::vector<BigInt::BaseType> BigInt::getDigits()
{
	return digits;
}
