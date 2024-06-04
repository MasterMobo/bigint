#include <gtest/gtest.h>
#include "bigint/BigInt.h"

struct ComparisonTest: testing::Test {
  // Positve numbers
  BigInt* p1; // Bigger
  BigInt* p2; // Smaller

  //Negative Numbers
  BigInt* n1; // Bigger
  BigInt* n2; // Smaller

  ComparisonTest() {
    p1 = new BigInt("22134513231099180912312832687123213618242349852301234761240");
    p2 = new BigInt("221345345345123127318272378123512376125312342134292342");

    n1 = new BigInt("42342349087548962384060923423423482936423423423894723445");
    n1->makeNegative();
    n2 = new BigInt("4234232093472342893453645873465287345234212777345342786342347");
    n2->makeNegative();
  }

  ~ComparisonTest() {
    delete p1;
    delete p2;
    delete n1;
    delete n2;
  }
};

TEST_F(ComparisonTest, EqualCheck) {
  EXPECT_EQ(*p1 == *p2, false);
  EXPECT_EQ(*n1 == *n2, false);
}

TEST_F(ComparisonTest, InequalCheck) {
  EXPECT_EQ(*p1 != *p2, true);
  EXPECT_EQ(*n1 != *n2, true);
}

TEST_F(ComparisonTest, LargerCheck) {
  EXPECT_EQ(*p1 > *p2, true);
  EXPECT_EQ(*n1 > *n2, true);
}

TEST_F(ComparisonTest, LargerEqualCheck) {
  EXPECT_EQ(*p1 >= *p2, true);
  EXPECT_EQ(*n1 >= *n2, true);
}

TEST_F(ComparisonTest, SmallerCheck) {
  EXPECT_EQ(*p1 < *p2, false);
  EXPECT_EQ(*n1 < *n2, false);
}

TEST_F(ComparisonTest, SmallerEqualCheck) {
  EXPECT_EQ(*p1 <= *p2, false);
  EXPECT_EQ(*n1 <= *n2, false);
}
