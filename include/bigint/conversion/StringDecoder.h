#pragma once

#ifndef STRING_DECODER_H
#define STRING_DECODER_H

#include "bigint/BigInt.h"
#include <string>

class StringDecoder {
    public:
        virtual BigInt fromString(std::string s) = 0;
};

#endif