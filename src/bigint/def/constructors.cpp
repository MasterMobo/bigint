#include <vector>
#include <string>
#include <climits>

#include "bigint/BigInt.h"


BigInt::BigInt(){
	radix = ULLONG_MAX;
}

BigInt::BigInt(BigInt::BaseType radix): radix(radix) {
	
}

BigInt::BigInt(std::vector<BigInt::BaseType> digits, BigInt::BaseType radix) : digits(digits), radix(radix)
{
}

BigInt::BigInt(std::string s, BigInt::BaseType radix) : radix(radix){
	this->digits = fromString(s);
}
