#include "pch.h"
#include "..//calculator.cpp"
Calculator calculator;

TEST(CalculatorTests, AdditionTest) {
    std::string expression = "5+19";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, 24);
}

TEST(CalculatorTests, SubtractionTest) {
    std::string expression = "5-1";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, 4);
}

TEST(CalculatorTests, MultiplicationTest) {
    std::string expression = "5*10";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, 50);
}

TEST(CalculatorTests, DivisionTest) {
    std::string expression = "10/4";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, 2.5);
}

TEST(CalculatorTests, DoublePrecisionTest) {
    std::string expression = "1.2/0.3";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, 4.0);
}

TEST(CalculatorTests, ParenthesesTest1) {
    std::string expression = "5*(10-4)";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, 30);

    expression = "(10-4)/3";
    calculator.setExpression(expression);
    outcome = calculator.calculation();
    EXPECT_EQ(outcome, 2);
}

TEST(CalculatorTests, NegativeNumbersTest1) {
    std::string expression = "6*(-2)";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, -12);
}

TEST(CalculatorTests, NegativeNumbersTest2) {
    std::string expression = "-3*5";
    calculator.setExpression(expression);
    double outcome = calculator.calculation();
    EXPECT_EQ(outcome, -15);
}

TEST(ExpressionValidityTests, ValidExpression) {
    std::string expression = "3+4*(-3)/3";
    calculator.setExpression(expression);
    bool isValid = calculator.expressionIsCorrect();
    EXPECT_TRUE(isValid);
}

TEST(ExpressionValidityTests, InvalidCharactersTest) {
    std::string expression = "a+b";
    calculator.setExpression(expression);
    bool isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);
}

TEST(ExpressionValidityTests, EdgeOperatorsTest) {
    std::string expression = "+2-3";
    calculator.setExpression(expression);
    bool isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "2-3+";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);
}

TEST(ExpressionValidityTests, ConsecutiveOperatorsTest) {
    std::string expression = "2++3";
    calculator.setExpression(expression);
    bool isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "2--3";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "2**3";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "2//3";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);
}

TEST(ExpressionValidityTests, IncorrectMinusTest) {
    std::string expression = "2+-3";
    calculator.setExpression(expression);
    bool isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "2*-3";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "2/-3";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);
}

TEST(ExpressionValidityTests, IncorrectParenthesesTest) {
    std::string expression = "(3+4";
    calculator.setExpression(expression);
    bool isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);
    expression = "3+4)";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "(3+)";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "(+3)";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "()";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "((3+4)";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);

    expression = "(3+4))";
    calculator.setExpression(expression);
    isValid = calculator.expressionIsCorrect();
    EXPECT_FALSE(isValid);
}
