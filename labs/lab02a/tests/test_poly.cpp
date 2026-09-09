#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() -     only do this in one cpp file

#include "../poly.h"
#include "catch.hpp"

// test the polynomial class
TEST_CASE("### part 1 - polynomial ###", "[test3]" ) {
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
TEST_CASE("### part 2 - polynomial 2 ###", "[test4]" ) {
    double testArr[3] = {6, 3, 8};
    Polynomial myPoly(testArr, 2);
    REQUIRE(myPoly.degree() == 2);
    REQUIRE(myPoly.coefficient(0) == 6);
    REQUIRE(myPoly.coefficient(1) == 3);
    REQUIRE(myPoly.coefficient(2) == 8);
    myPoly.changeCoefficient(12, 1);
    REQUIRE(myPoly.coefficient(1) == 12);
}

