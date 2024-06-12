#include "bigint/BigInt.h"
#include "bigint/utils.h"
#include "bigint/conversion/BinStringConverter.h"
#include "bigint/conversion/DecStringConverter.h"


#include <string>
#include <iostream>
#include <climits>
#include <bitset>

BigInt BigInt::fromBinString(std::string s) {
	BinStringConverter converter;
    return converter.fromString(s);
}

BigInt BigInt::fromDecString(std::string s) {
	DecStringConverter converter;
	return converter.fromString(s);
}