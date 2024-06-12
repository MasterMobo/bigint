#include "bigint/BigInt.h"
#include "bigint/conversion/BinStringConverter.h"
#include "bigint/conversion/DecStringConverter.h"
#include "bigint/conversion/RawStringConverter.h"

#include "bigint/utils.h"

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
