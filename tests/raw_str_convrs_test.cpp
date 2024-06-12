#include <gtest/gtest.h>

#include "bigint/BigInt.h"
#include <string>
#include <stdexcept>

struct RawStringConversionTest: testing::Test {
    std::string binString;
    std::string decString;

    std::string correctPosPrefix;
    std::string correctNegPrefix;
    std::string wrongPrefix;

    RawStringConversionTest() {
        binString = std::string("101001110100101011101010010101000111110100111010101000101010011100011001111");
        decString = std::string("478922353498192387143528927348923483122389472398465239823489273423489273423431846124891246235");
        
        correctPosPrefix = std::string("0000");
        correctPosPrefix = std::string("-0000000000");
        wrongPrefix = std::string("~ ?>  <");
    }
};

TEST_F(RawStringConversionTest, PosBinStringConversion) {
    BigInt n = BigInt::fromBinString(correctPosPrefix + binString);
    ASSERT_EQ(1, n.getSign());
    ASSERT_EQ(binString, n.toBinString());
}

TEST_F(RawStringConversionTest, PosDecStringConversion) {
    BigInt n = BigInt::fromDecString(correctPosPrefix + decString);
    ASSERT_EQ(1, n.getSign());
    ASSERT_EQ(decString, n.toDecString());
}

TEST_F(RawStringConversionTest, NegBinStringConversion) {
    BigInt n = BigInt::fromBinString(correctNegPrefix + binString);
    ASSERT_EQ(-1, n.getSign());
    ASSERT_EQ("-" + binString, n.toBinString());
}

TEST_F(RawStringConversionTest, NegDecStringConversion) {
    BigInt n = BigInt::fromDecString(correctNegPrefix + decString);
    ASSERT_EQ(-1, n.getSign());
    ASSERT_EQ("-" + decString, n.toDecString());
}

TEST_F(RawStringConversionTest, WrongPrefixBinConversion) {
    EXPECT_THROW(
        BigInt n = BigInt::fromBinString(wrongPrefix + binString),
        std::invalid_argument);
}
