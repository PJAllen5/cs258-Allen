#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../palindrome.h"

#include "catch.hpp"

TEST_CASE("### Palindrome ###", "[palindrome]")
{
    REQUIRE(isPalindrome("madamimadam"));
    REQUIRE(isPalindrome("hello world") == false);
    REQUIRE(isPalindrome("dadseesdad"));
}

// odd length palindromes have a middle character, even length ones do not -
// these are the two cases your loop has to get right
TEST_CASE("### Palindrome - even and odd length ###", "[palindrome]")
{
    REQUIRE(isPalindrome("abba"));     // even
    REQUIRE(isPalindrome("racecar"));  // odd
    REQUIRE(isPalindrome("abca") == false);
    REQUIRE(isPalindrome("ab") == false);
}

// the smallest inputs
TEST_CASE("### Palindrome - short strings ###", "[palindrome]")
{
    REQUIRE(isPalindrome(""));   // an empty string reads the same both ways
    REQUIRE(isPalindrome("a"));  // so does a single character
    REQUIRE(isPalindrome("aa"));
}

// the comparison is exact - spaces and capitals count
TEST_CASE("### Palindrome - exact comparison ###", "[palindrome]")
{
    REQUIRE(isPalindrome("Abba") == false);   // capital A, lowercase a
    REQUIRE(isPalindrome("abba ") == false);  // the trailing space breaks it
    REQUIRE(isPalindrome("ab ba"));           // a b space b a - still symmetric
    REQUIRE(isPalindrome("ab a ba"));         // so is this one
}
