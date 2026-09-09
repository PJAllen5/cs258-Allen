#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() - only do this in one cpp file

#include <math.h>
#include "../fractions.hpp"
#include "catch.hpp"

// test the fractions class - subtracting
TEST_CASE("### part 2 - Fractions ###" ) {
    Fractions myFrac3(1, 3);
    Fractions myFrac2(4, 6);
    Fractions subFrac(1, 3);
    REQUIRE(myFrac2.subtract(myFrac3) == subFrac);
}

// test the fractions class - dividing
TEST_CASE("### part 2 - Fractions ###" ) {
    Fractions myFrac(2, 3);
    Fractions myFrac2(4, 6);
    Fractions divFrac(1, 1);
    REQUIRE(myFrac.divide(myFrac2) == divFrac);
}

// test the fractions class - multiplying
TEST_CASE("### part 2 - Fractions ###" ) {
    Fractions myFrac(2, 3);
    Fractions myFrac2(4, 6);
    Fractions multFrac(4, 9);
    REQUIRE(myFrac.multiply(myFrac2) == multFrac);
}

// test the fractions class - no zero denominator
TEST_CASE("### part 2 - Fractions ###" ) {
    CHECK_THROWS(myFrac(2, 0), std::invalid_argument);
}

// test the fractions class - reduce to lowest terms
TEST_CASE("### part 2 - Fractions ###") {
    Fractions myFrac(2, 3);
    Fractions myFrac2(12, 18);
    myFrac2.reduce_to_lowest_terms();
    REQUIRE(myFrac2 == myFrac);
}
