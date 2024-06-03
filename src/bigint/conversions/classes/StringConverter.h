#pragma once

#ifndef STRING_CONVERTER_H
#define STRING_CONVERTER_H

#include "bigint/BigInt.h"
#include <string>

class StringConverter {
    public:
        StringConverter() {};

        virtual std::string toString(const BigInt& bigInt);
        virtual BigInt fromString(std::string s);
};

#endif