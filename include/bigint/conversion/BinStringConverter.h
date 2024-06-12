#pragma once

#ifndef BIN_STRING_CONVERTER_H
#define BIN_STRING_CONVERTER_H

#include "bigint/utils.h"
#include "bigint/conversion/StringEncoder.h"
#include "bigint/conversion/StringDecoder.h"

#include <bitset>
#include <vector>
#include <stdexcept>

class BinStringConverter: public StringEncoder, public StringDecoder {
    // private:
    //     bool validPrefixChar(char c) {
    //         switch (c)
    //         {
    //         case '-':
    //             return true;
    //             break;
    //         case '0':
    //             return true;
    //         default:
    //             return false;
    //             break;
    //         }
    //     }

    public:        
        BigInt fromString(std::string s) override {
            // BigInt res;
            // int start = 0;

            // while (start < s.size()) {
            //     if (!validPrefixChar(s[start])) {
            //         if (s[start] == '1') {
            //             break;
            //         }
            //         throw std::invalid_argument("Can not convert string: " + s);
            //     }

            //     if (s[start] == '-') {
            //         // Can not have duplicate '-'
            //         if (res.getSign() == -1) {
            //             throw std::invalid_argument("Duplicate negative sign found in string: " + s);
            //         }

            //         res.makeNegative();
            //     }
            //     start++;
            // }

            std::string stripped = s;

            const int len = stripped.size();
            const int bitsPerDigit = BigInt::BITS_PER_DIGIT;
            const int wholeParts = len / bitsPerDigit;
            const int leftOver = len % bitsPerDigit;

            std::vector<BigInt::BaseType> digits (wholeParts + (leftOver? 1 : 0), 0);
            BigInt::BaseType currentDigit;

            if (leftOver != 0) {
                std::string sub = stripped.substr(0, leftOver);
                sub = padLeadingZeros(sub, bitsPerDigit);

                digits[digits.size() - 1] = std::stoul(sub, 0, 2);;
            }

            for (int i = 0; i < wholeParts; i++) {
                std::string sub = stripped.substr(i * bitsPerDigit + leftOver, bitsPerDigit);
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