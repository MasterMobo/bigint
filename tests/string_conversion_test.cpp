#include <gtest/gtest.h>

#include "bigint/BigInt.h"
#include <string>

struct StringConversionTest: testing::Test {
    std::string binString;
    std::string decString;

    StringConversionTest() {
        binString = std::string("101001110100101011101010010101000111110100111010101000101010011100011001111");
        decString = std::string("478922353498192387143528927348923483122389472398465239823489273423489273423431846124891246235");
    }

};

TEST_F(StringConversionTest, BinStringConversion) {
    BigInt n = BigInt::fromBinString(binString);
    EXPECT_EQ(n.toBinString(), binString);
}

TEST_F(StringConversionTest, DecStringConversion) {
    BigInt n = BigInt::fromDecString(decString);
    EXPECT_EQ(n.toDecString(), decString);
}