#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do
                           // this in one cpp file

#include "../postfix.h"
#include "catch.hpp"


TEST_CASE("### postFixCalc ###", "[postfix]")
{
    REQUIRE(postFixCalc("4 5 + 2 *") == 18);
    REQUIRE(postFixCalc("4 5 + 2 3 + *") == 45);
    REQUIRE(postFixCalc("4 5 * 2 3 * +") == 26);
    REQUIRE(postFixCalc("4 5 + 2 + 3 +") == 14);
}

// subtraction and division are not commutative, so the order you pop the two
// operands off the stack matters.  "7 2 -" means 7 - 2, not 2 - 7.
TEST_CASE("### postFixCalc - subtraction and division ###", "[postfix]")
{
    REQUIRE(postFixCalc("7 2 -") == 5);
    REQUIRE(postFixCalc("2 7 -") == -5);
    REQUIRE(postFixCalc("8 2 /") == 4);
    REQUIRE(postFixCalc("20 5 2 - /") == 6);  // 20 / (5-2)
    REQUIRE(postFixCalc("9 3 / 2 -") == 1);   // (9/3) - 2
}

// integer division truncates, and results may be negative
TEST_CASE("### postFixCalc - integer arithmetic ###", "[postfix]")
{
    REQUIRE(postFixCalc("7 2 /") == 3);  // not 3.5
    REQUIRE(postFixCalc("3 10 -") == -7);
    REQUIRE(postFixCalc("2 3 - 4 *") == -4);
}

// a single operand is a valid postfix expression
TEST_CASE("### postFixCalc - single operand ###", "[postfix]")
{
    REQUIRE(postFixCalc("42") == 42);
    REQUIRE(postFixCalc("7 8 9 + +") == 24);  // multi digit operands
}
