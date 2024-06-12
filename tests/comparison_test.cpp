#include <gtest/gtest.h>
#include "bigint/BigInt.h"

struct ComparisonTest: testing::Test {
  // Positve numbers
  BigInt p1; // Bigger
  BigInt p2; // Smaller

  //Negative Numbers
  BigInt n1; // Bigger
  BigInt n2; // Smaller

  ComparisonTest() {
    p1 = BigInt("22134513231099180912312832687123213618242349852301234761240");
    p2 = BigInt("221345345345123127318272378123512376125312342134292342"); 

    n1 = BigInt("42342349087548962384060923423423482936423423423894723445");
    n1.makeNegative();

    n2 = BigInt("4234232093472342893453645873465287345234212777345342786342347");
    n2.makeNegative();
  }
};

TEST_F(ComparisonTest, EqualCheck) {
  EXPECT_FALSE(p1 == p2);
  EXPECT_FALSE(n1 == n2);
}

TEST_F(ComparisonTest, InequalCheck) {
  EXPECT_TRUE(p1 != p2);
  EXPECT_TRUE(n1 != n2);
}

TEST_F(ComparisonTest, LargerCheck) {
  EXPECT_TRUE(p1 > p2);
  EXPECT_TRUE(n1 > n2);
}

TEST_F(ComparisonTest, LargerEqualCheck) {
  EXPECT_TRUE(p1 >= p2);
  EXPECT_TRUE(n1 >= n2);
}

TEST_F(ComparisonTest, SmallerCheck) {
  EXPECT_FALSE(p1 < p2);
  EXPECT_FALSE(n1 < n2);
}

TEST_F(ComparisonTest, SmallerEqualCheck) {
  EXPECT_FALSE(p1 <= p2);
  EXPECT_FALSE(n1 <= n2);
}
