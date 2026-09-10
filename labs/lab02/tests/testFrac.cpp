#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() - only do this in one cpp file.
// Note: tests/test.cpp also defines it, so these two test files must be
// compiled into two SEPARATE executables.  See the Makefile.

#include <math.h>
#include <stdexcept>
#include "../fractions.hpp"
#include "catch.hpp"

// test the fractions class - subtracting
TEST_CASE("### part 2 - Fractions - subtract ###", "[frac1]")
{
    Fractions myFrac3(1, 3);
    Fractions myFrac2(4, 6);
    Fractions subFrac(1, 3);
    REQUIRE(myFrac2.subtract(myFrac3) == subFrac);
}

// test the fractions class - dividing
TEST_CASE("### part 2 - Fractions - divide ###", "[frac2]")
{
    Fractions myFrac(2, 3);
    Fractions myFrac2(4, 6);
    Fractions divFrac(1, 1);
    REQUIRE(myFrac.divide(myFrac2) == divFrac);
}

// test the fractions class - multiplying
TEST_CASE("### part 2 - Fractions - multiply ###", "[frac3]")
{
    Fractions myFrac(2, 3);
    Fractions myFrac2(4, 6);
    Fractions multFrac(4, 9);
    REQUIRE(myFrac.multiply(myFrac2) == multFrac);
}

// test the fractions class - adding
TEST_CASE("### part 2 - Fractions - add ###", "[frac4]")
{
    Fractions myFrac(1, 2);
    Fractions myFrac2(1, 3);
    Fractions addFrac(5, 6);
    REQUIRE(myFrac.add(myFrac2) == addFrac);
}

// test the fractions class - a zero denominator is not allowed
TEST_CASE("### part 2 - Fractions - no zero denominator ###", "[frac5]")
{
    CHECK_THROWS_AS(Fractions(2, 0), std::invalid_argument);
}

// test the fractions class - reduce to lowest terms
TEST_CASE("### part 2 - Fractions - reduceToLowestTerms ###", "[frac6]")
{
    Fractions myFrac(2, 3);
    Fractions myFrac2(12, 18);
    myFrac2.reduceToLowestTerms();
    REQUIRE(myFrac2 == myFrac);
}
