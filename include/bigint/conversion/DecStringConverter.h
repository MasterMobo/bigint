#pragma once

#ifndef DEC_STRING_CONVERTER_H
#define DEC_STRING_CONVERTER_H

#include "bigint/BigInt.h"
#include "bigint/utils.h"
#include "bigint/conversion/StringEncoder.h"
#include "bigint/conversion/StringDecoder.h"
#include "bigint/conversion/BinStringConverter.h"

#include <string>

class DecStringConverter: public StringEncoder, public StringDecoder {
    public:
        BigInt fromString(std::string s) override {
            // TODO: Remove leading zeros and check for signs
            BinStringConverter binConverter;
            return binConverter.fromString(decToBin(s));
        }

        std::string toString(const BigInt& bigInt) override {
            BinStringConverter binConverter;
            std::string s;

            std::string binString = binConverter.toString(bigInt);

            s.append(binToDec(binString)); 

            if (bigInt.getSign() == -1) {
                s.insert(0, "-");
            } 

            return s;
        }
};

#endif