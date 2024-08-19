#include "gtest/gtest.h"
#include "rational.h"

//
// Created by miche on 18/07/2024.
//
#include "rational.h"
class RationalTestSuite : public ::testing::Test{
public:
    Rational one_half{1, 2};
    Rational two_thirds{2, 3};
    Rational one{1, 1};
};

TEST_F(RationalTestSuite, ZeroDenominatorThrowsDomainError){
    EXPECT_THROW(Rational(1,0), std::domain_error);
}

TEST_F(RationalTestSuite, SimplifyReturnsCorrectSimplification){
    Rational four_eigth{4, 8};
    four_eigth.simplify();
    EXPECT_EQ(four_eigth.num(), 1);
    EXPECT_EQ(four_eigth.den(), 2);
}

TEST_F(RationalTestSuite, ConversionToDoubleReturnsCorrectDouble){
    EXPECT_EQ(double(one_half), 0.5);
}

TEST_F(RationalTestSuite, OperatorPlusEqualRationalReturnsCorrectRational){
    one_half += two_thirds;
    EXPECT_FLOAT_EQ(one_half.num(), 7);
    EXPECT_FLOAT_EQ(one_half.den(), 6);

}

TEST_F(RationalTestSuite, OperatorPlusEqualIntReturnsCorrectRational){
    one_half += 1;
    EXPECT_FLOAT_EQ(one_half.num(), 3);
    EXPECT_FLOAT_EQ(one_half.den(), 2);
}

TEST_F(RationalTestSuite, OperatorMinusEqualRationalReturnsCorrectRational){
    one_half -= two_thirds;
    EXPECT_FLOAT_EQ(one_half.num(), -1);
    EXPECT_FLOAT_EQ(one_half.den(), 6);
}

TEST_F(RationalTestSuite, OperatorMinusEqualIntReturnsCorrectRational){
    one_half -= 1;
    EXPECT_FLOAT_EQ(one_half.num(), -1);
    EXPECT_FLOAT_EQ(one_half.den(), 2);
}

TEST_F(RationalTestSuite, OperatorMultiplyEqualRationalReturnsCorrectResult){
    one_half *= two_thirds;
    EXPECT_FLOAT_EQ(one_half.num(), 1);
    EXPECT_FLOAT_EQ(one_half.den(), 3);
}

TEST_F(RationalTestSuite, OperatorMultiplyEqualIntReturnsCorrectResult){
    one_half *= 2;
    EXPECT_FLOAT_EQ(one_half.num(), 1);
    EXPECT_FLOAT_EQ(one_half.den(), 1);
}
