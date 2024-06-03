#include "bigint/BigInt.h"
#include "../utils/utils.h"

#include "./classes/BinStringConverter.h"

#include <string>
#include <iostream>
#include <climits>
#include <bitset>

BigInt BigInt::fromBinString(std::string s) {
	BinStringConverter converter = BinStringConverter();
    return converter.fromString(s);
    // return s;
}

BigInt BigInt::fromDecString(std::string s) {
	// TODO: Remove leading zeros and check for signs

	return fromBinString(decToBin(s));
}