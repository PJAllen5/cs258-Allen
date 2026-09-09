#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../palindrome.h"

#include "catch.hpp"

TEST_CASE( "### Palindrome ###", "[test1]" ) {
    REQUIRE( isPalindrome("madamimadam") );
    REQUIRE( isPalindrome("hello world") == false );
    REQUIRE( isPalindrome("dadseesdad") );
}




