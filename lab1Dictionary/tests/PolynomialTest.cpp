#include <gtest/gtest.h>
#include "../../lab1Polynomial/Include/Polynomial.h"

class PolynomialTests : public ::testing::Test {
protected:
    void SetUp() override {
        poly0 = Polynomial({0});
        poly1 = Polynomial({1});
        poly2 = Polynomial({1, 2});
        poly3 = Polynomial({3, 1});
        poly4 = Polynomial({2, 3, 1});
        poly5 = Polynomial({0, 0, 5});
    }
    Polynomial poly0, poly1, poly2, poly3, poly4, poly5;
};

TEST_F(PolynomialTests, ConstructorAndGetter) {
    Polynomial p1({1, 2, 3});
    EXPECT_EQ(p1.getDegree(), 2);

    Polynomial p2({0});
    EXPECT_EQ(p2.getDegree(), 0);

    Polynomial p3;
    EXPECT_EQ(p3.getDegree(), 0);
}

TEST_F(PolynomialTests, IndexOperator) {
    Polynomial polynomial({1, 2, 3});

    EXPECT_EQ(polynomial[0], 1);
    EXPECT_EQ(polynomial[1], 2);
    EXPECT_EQ(polynomial[2], 3);

    polynomial[5] = 5;
    EXPECT_EQ(polynomial[5], 5);
    EXPECT_EQ(polynomial.getDegree(), 5);

    EXPECT_THROW(polynomial[-1], std::out_of_range);
}

TEST_F(PolynomialTests, EvaluationTest) {
    Polynomial polynomial({1, 2, 1});

    EXPECT_DOUBLE_EQ(polynomial(0), 1);
    EXPECT_DOUBLE_EQ(polynomial(1), 4);
    EXPECT_DOUBLE_EQ(polynomial(2), 9);
    EXPECT_DOUBLE_EQ(polynomial(-1), 0);
}

TEST_F(PolynomialTests, AdditionTest) {
    Polynomial result = poly2 + poly3;

    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 3);

    result = poly2 + poly0;
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
}

TEST_F(PolynomialTests, MultipleAdditionTest) {
    Polynomial result = poly2 += poly3 += poly4;
    EXPECT_EQ(result.getDegree(), 2);
    EXPECT_DOUBLE_EQ(result[0], 6);
    EXPECT_DOUBLE_EQ(result[1], 6);
    EXPECT_DOUBLE_EQ(result[2], 1);
}

TEST_F(PolynomialTests, SubtractionTest) {
    Polynomial result = poly2 - poly3;
    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], -2);
    EXPECT_DOUBLE_EQ(result[1], 1);

    result = poly2 - poly2;
    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], 0);
}

TEST_F(PolynomialTests, MultipleSubtractionTest) {
    Polynomial result = poly4 -= poly2 -= poly3;
    EXPECT_EQ(result.getDegree(), 2);
    EXPECT_DOUBLE_EQ(result[0], 4);
    EXPECT_DOUBLE_EQ(result[1], 2);
    EXPECT_DOUBLE_EQ(result[2], 1);
}

TEST_F(PolynomialTests, MultiplicationTest) {
    Polynomial result = poly2 * poly3;
    EXPECT_EQ(result.getDegree(), 2);
    EXPECT_DOUBLE_EQ(result[0], 3);
    EXPECT_DOUBLE_EQ(result[1], 7);
    EXPECT_DOUBLE_EQ(result[2], 2);

    result = poly2 * poly1;
    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], 1);
    EXPECT_DOUBLE_EQ(result[1], 2);

    result = poly2 * poly0;
    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], 0);
}

TEST_F(PolynomialTests, MultipleMultiplicationTest) {
    Polynomial result = poly2 *= poly3 *= poly5;
    EXPECT_EQ(result.getDegree(), 4);
    EXPECT_DOUBLE_EQ(result[0], 0);
    EXPECT_DOUBLE_EQ(result[1], 0);
    EXPECT_DOUBLE_EQ(result[2], 15);
    EXPECT_DOUBLE_EQ(result[3], 35);
    EXPECT_DOUBLE_EQ(result[4], 10);
}

TEST_F(PolynomialTests, DivisionTest) {
    Polynomial divisor({1, 1});
    Polynomial result = poly4 / divisor;
    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], 2);
    EXPECT_DOUBLE_EQ(result[1], 1);

    result = poly2 / poly1;
    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], 1);
    EXPECT_DOUBLE_EQ(result[1], 2);

    EXPECT_THROW(poly2/poly0, std::invalid_argument);
}

TEST_F(PolynomialTests, MultipleDivisionTest) {
    Polynomial multiplication = poly2 * poly3;
    Polynomial result = multiplication /= poly3 /= poly1;

    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_DOUBLE_EQ(result[0], 1);
    EXPECT_DOUBLE_EQ(result[1], 2);
}

TEST_F(PolynomialTests, PrintTest) {
    testing::internal::CaptureStdout();
    poly2.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("2x + 1")!=std::string::npos);

    testing::internal::CaptureStdout();
    poly0.print();
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output2.find("0")!=std::string::npos);
}