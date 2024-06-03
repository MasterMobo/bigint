#pragma once

#ifndef RAW_CONVERTER_H
#define RAW_CONVERTER_H

#include "bigint/BigInt.h"
#include "./StringEncoder.h"
#include <string>
#include <vector>

class RawStringConverter: public StringEncoder {
    public:
        std::string toString(const BigInt& bigInt) override {
            std::string s = bigInt.getSign() == -1 ? "-" : "";

            std::vector<BigInt::BaseType> digits = bigInt.getDigits();

            for (int i = digits.size() - 1; i >= 0; i--) {
                s.append(std::to_string(digits[i]));
                s.append(" ");
            }

	        return s;
        }
};

#endif