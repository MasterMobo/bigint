#include "bigint/BigInt.h"
#include "../utils/utils.h"

#include "./classes/BinStringConverter.h"
#include "./classes/DecStringConverter.h"
#include "./classes/RawStringConverter.h"

#include <string>
#include <climits>
#include <bitset>

std::string BigInt::toBinString() {
	BinStringConverter converter;
	return converter.toString(*this);
}

std::string BigInt::toDecString() {
	DecStringConverter converter;
	return converter.toString(*this);
};

std::string BigInt::toRawString() {
	RawStringConverter converter;
	return converter.toString(*this);
}
