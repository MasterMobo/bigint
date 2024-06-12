#pragma once

#ifndef STRING_ENCODER_H
#define STRING_ENCODER_H

#include "bigint/BigInt.h"
#include <string>

class StringEncoder {
    public:
        virtual std::string toString(const BigInt& bigInt) = 0;
};

#endif