#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() - only do this in one cpp file

#include <math.h>
#include "../recursion.hpp"
#include "catch.hpp"

// Test the power function
TEST_CASE("### part 1 - power ###", "[test1]" ) {
    recursion myRec;
    REQUIRE(myRec.power(88, 0) == 1);  // Base Case
    REQUIRE(myRec.power(2, 3) == 8);
    REQUIRE(myRec.power(2.2345, 4) == pow(2.2345, 4));
    REQUIRE(myRec.power(3.14159, 5) == Approx(pow(3.14159, 5)).epsilon(0.001));
}

// test teh sumOfSquares function
TEST_CASE("### part 1 - sumOfSquares ###", "[test2]" ) {
    recursion myRec = recursion();
    REQUIRE(myRec.sumOfSquares(4) == 30);
    REQUIRE(myRec.sumOfSquares(3) == 14);
    REQUIRE(myRec.sumOfSquares(9) == 285);
}
