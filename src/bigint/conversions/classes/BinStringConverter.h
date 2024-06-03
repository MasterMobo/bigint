#pragma once

#ifndef BIN_STRING_CONVERTER_H
#define BIN_STRING_CONVERTER_H

#include "./StringEncoder.h"
#include "./StringDecoder.h"
#include "../../utils/utils.h"

#include <bitset>
#include <vector>

class BinStringConverter: public StringEncoder, public StringDecoder {
    public:        
        BigInt fromString(std::string s) override {
            // TODO: Remove leading zeros and check for signs
            const int len = s.size();
            const int baseTypeSize = BigInt::BITS_PER_DIGIT;
            const int wholeParts = len / baseTypeSize;
            const int leftOver = len % baseTypeSize;

            std::vector<BigInt::BaseType> digits (wholeParts + (leftOver? 1 : 0), 0);
            BigInt::BaseType currentDigit;

            if (leftOver != 0) {
                std::string sub = s.substr(0, leftOver);
                sub = padLeadingZeros(sub, BigInt::BITS_PER_DIGIT);

                digits[digits.size() - 1] = std::stoul(sub, 0, 2);;
            }

            for (int i = 0; i < wholeParts; i++) {
                std::string sub = s.substr(i * baseTypeSize + leftOver, baseTypeSize);
                int ind = digits.size() - i - 1 - (leftOver? 1 : 0);

                digits[ind] = std::stoul(sub, 0, 2);
            }

            return BigInt(digits);
        };

        std::string toString(const BigInt& bigInt) override {
            std::vector<BigInt::BaseType> digits = bigInt.getDigits();
            std::string s;

            for (int i = digits.size() - 1; i >= 0; i--) {
                std::string chunk = std::bitset<BigInt::BITS_PER_DIGIT>(digits[i]).to_string(); 
                s.append(chunk);
            }

            s = pruneLeadingZeros(s);
            
            // FIXME: This is broken when used for dec converter
            // if (bigInt.getSign() == -1) {
            //     s.insert(0, "-");
            // }

            return s;
        };
};

#endif