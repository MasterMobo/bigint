#include <gtest/gtest.h>

#include "bigint/BigInt.h"

struct AdditionTest: testing::Test
{   
    // Positive Numbers
    BigInt p1;
    BigInt p2;
    
    // Negative Numbers
    BigInt n1;
    BigInt n2;

    // Expected results;
    BigInt p1_p2; // p1 + p2
    BigInt p1_n1; // p1 + n1
    BigInt n2_p2; // n2 + p2
    BigInt n1_n2; // n1 + n2


    AdditionTest() {
        p1 = BigInt("2323492020942389472523049238423097423042394872340134713498357345029343");
        p2 = BigInt("92283472398521340239423729835234298347234982374352305234239823847234989234");

        n1 = BigInt("453409523429502349234203423423429834713409123423042349283472492834342888");
        n1.makeNegative();
        n2 = BigInt("3242340923582503945834523894723423498235230423942384230497235823957235255");
        n2.makeNegative();

        p1_p2 = BigInt("92285795890542282628896252884472721444658024769224645368953322204580018577");

        p1_n1 = BigInt("451086031408559959761680374185006737290366728550702214569974135489313545");
        p1_n1.makeNegative();

        n2_p2 = BigInt("89041131474938836293589205940510874848999751950409921003742588023277753979");

        n1_n2 = BigInt("3695750447012006295068727318146853332948639547365426579780708316791578143");
        n1_n2.makeNegative();
    }
};

TEST_F(AdditionTest, PosPosAdd) {
    EXPECT_EQ(p1 + p2, p1_p2);
}

TEST_F(AdditionTest, PosNegAdd) {
    EXPECT_EQ(p1 + n1, p1_n1);
}

TEST_F(AdditionTest, NegPosAdd) {
    EXPECT_EQ(n2 + p2, n2_p2);
}

TEST_F(AdditionTest, NegNegAdd) {
    EXPECT_EQ(n1 + n2, n1_n2);
}