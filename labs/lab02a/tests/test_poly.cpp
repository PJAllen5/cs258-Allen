#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() -     only do this in one cpp file

#include <stdexcept>
#include "../poly.h"
#include "catch.hpp"

// test the polynomial class
TEST_CASE("### part 1 - polynomial ###", "[test3]")
{
    double testArr[6] = {9, 0, 1, 7, 0, 4};
    Polynomial myPoly(testArr, 5);
    REQUIRE(myPoly.degree() == 5);
    REQUIRE(myPoly.coefficient(0) == 9);
    REQUIRE(myPoly.coefficient(1) == 0);
    REQUIRE(myPoly.coefficient(2) == 1);
    REQUIRE(myPoly.coefficient(3) == 7);
    REQUIRE(myPoly.coefficient(4) == 0);
    REQUIRE(myPoly.coefficient(5) == 4);
    myPoly.changeCoefficient(11, 4);
    REQUIRE(myPoly.coefficient(4) == 11);
}

// test the polynomial class
TEST_CASE("### part 2 - polynomial 2 ###", "[test4]")
{
    double testArr[3] = {6, 3, 8};
    Polynomial myPoly(testArr, 2);
    REQUIRE(myPoly.degree() == 2);
    REQUIRE(myPoly.coefficient(0) == 6);
    REQUIRE(myPoly.coefficient(1) == 3);
    REQUIRE(myPoly.coefficient(2) == 8);
    myPoly.changeCoefficient(12, 1);
    REQUIRE(myPoly.coefficient(1) == 12);
}


// a constant polynomial - the smallest legal case
TEST_CASE("### polynomial - degree zero ###", "[test5]")
{
    double testArr[1] = {7};
    Polynomial myPoly(testArr, 0);
    REQUIRE(myPoly.degree() == 0);
    REQUIRE(myPoly.coefficient(0) == 7);
    myPoly.changeCoefficient(12, 0);
    REQUIRE(myPoly.coefficient(0) == 12);
}

// change the first and last coefficients, not just the middle ones
TEST_CASE("### polynomial - change the end coefficients ###", "[test6]")
{
    double testArr[4] = {1, 2, 3, 4};
    Polynomial myPoly(testArr, 3);
    myPoly.changeCoefficient(99, 0);
    myPoly.changeCoefficient(55, 3);
    REQUIRE(myPoly.coefficient(0) == 99);
    REQUIRE(myPoly.coefficient(1) == 2);
    REQUIRE(myPoly.coefficient(2) == 3);
    REQUIRE(myPoly.coefficient(3) == 55);
}

// coefficients are doubles, and may be negative
TEST_CASE("### polynomial - fractional and negative coefficients ###",
          "[test7]")
{
    double testArr[3] = {1.5, -2.25, 0.125};
    Polynomial myPoly(testArr, 2);
    REQUIRE(myPoly.coefficient(0) == Approx(1.5));
    REQUIRE(myPoly.coefficient(1) == Approx(-2.25));
    REQUIRE(myPoly.coefficient(2) == Approx(0.125));
    myPoly.changeCoefficient(-0.5, 1);
    REQUIRE(myPoly.coefficient(1) == Approx(-0.5));
}

// the constructor must COPY the array it is given, not point at it
TEST_CASE("### polynomial - constructor copies the array ###", "[test8]")
{
    double testArr[3] = {1, 2, 3};
    Polynomial myPoly(testArr, 2);
    testArr[1] = 999;                     // change the caller's array
    REQUIRE(myPoly.coefficient(1) == 2);  // the polynomial must be unaffected
}

// two polynomials must not share storage
TEST_CASE("### polynomial - objects are independent ###", "[test9]")
{
    double arrA[3] = {1, 2, 3};
    double arrB[3] = {4, 5, 6};
    Polynomial polyA(arrA, 2);
    Polynomial polyB(arrB, 2);
    polyA.changeCoefficient(77, 1);
    REQUIRE(polyA.coefficient(1) == 77);
    REQUIRE(polyB.coefficient(1) == 5);
}

// an exponent outside 0..degree is an error
TEST_CASE("### polynomial - out of range exponent ###", "[test10]")
{
    double testArr[3] = {1, 2, 3};
    Polynomial myPoly(testArr, 2);
    CHECK_THROWS_AS(myPoly.coefficient(3), std::out_of_range);
    CHECK_THROWS_AS(myPoly.coefficient(-1), std::out_of_range);
    CHECK_THROWS_AS(myPoly.changeCoefficient(9, 3), std::out_of_range);
    CHECK_THROWS_AS(myPoly.changeCoefficient(9, -1), std::out_of_range);
}
