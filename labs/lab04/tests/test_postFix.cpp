#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../postfix.h"
#include "catch.hpp"



TEST_CASE( "### postFixCalc ###", "[test2]" ) {
    REQUIRE( postFixCalc("4 5 + 2 *") == 18 );
    REQUIRE( postFixCalc("4 5 + 2 3 + *") == 45 );
    REQUIRE( postFixCalc("4 5 * 2 3 * +") == 26 );
    REQUIRE( postFixCalc("4 5 + 2 + 3 +") == 14 );
}

