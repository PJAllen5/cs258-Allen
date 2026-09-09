#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../code.hpp"
#include "catch.hpp"

/**
 * @brief Test suite for sumOfBag function
 * Tests the sumOfBag function with basic positive integers
 * Verifies that the sum calculation works correctly for a bag containing 4, 8, and 20
 */
TEST_CASE( "### In Class - 1 - sumOfBag ###", "[test1]" ) {
    ArrayBag<int> myBag;
    myBag.add(4);
    myBag.add(8);
    myBag.add(20);

    REQUIRE( sumOfBag(myBag) == 32 );
}

/**
 * @brief Test sumOfBag with empty bag
 * Verifies that an empty bag returns a sum of 0
 */
TEST_CASE( "sumOfBag - Empty bag", "[sumOfBag]" ) {
    ArrayBag<int> emptyBag;
    REQUIRE( sumOfBag(emptyBag) == 0 );
}

/**
 * @brief Test sumOfBag with single item
 * Verifies that a bag with one item returns that item's value
 */
TEST_CASE( "sumOfBag - Single item", "[sumOfBag]" ) {
    ArrayBag<int> singleBag;
    singleBag.add(42);
    REQUIRE( sumOfBag(singleBag) == 42 );
}

/**
 * @brief Test sumOfBag with negative numbers
 * Verifies that negative numbers are handled correctly
 */
TEST_CASE( "sumOfBag - Negative numbers", "[sumOfBag]" ) {
    ArrayBag<int> negativeBag;
    negativeBag.add(-5);
    negativeBag.add(-10);
    negativeBag.add(-3);
    REQUIRE( sumOfBag(negativeBag) == -18 );
}

/**
 * @brief Test sumOfBag with mixed positive and negative numbers
 * Verifies that both positive and negative numbers are handled correctly together
 */
TEST_CASE( "sumOfBag - Mixed positive and negative", "[sumOfBag]" ) {
    ArrayBag<int> mixedBag;
    mixedBag.add(10);
    mixedBag.add(-5);
    mixedBag.add(3);
    mixedBag.add(-2);
    REQUIRE( sumOfBag(mixedBag) == 6 );
}

/**
 * @brief Test sumOfBag with zero values
 * Verifies that zero values are handled correctly
 */
TEST_CASE( "sumOfBag - Zero values", "[sumOfBag]" ) {
    ArrayBag<int> zeroBag;
    zeroBag.add(0);
    zeroBag.add(5);
    zeroBag.add(0);
    REQUIRE( sumOfBag(zeroBag) == 5 );
}

/**
 * @brief Test sumOfBag with maximum capacity
 * Verifies that the function works with a full bag (6 items)
 */
TEST_CASE( "sumOfBag - Maximum capacity", "[sumOfBag]" ) {
    ArrayBag<int> fullBag;
    fullBag.add(1);
    fullBag.add(2);
    fullBag.add(3);
    fullBag.add(4);
    fullBag.add(5);
    fullBag.add(6);
    REQUIRE( sumOfBag(fullBag) == 21 );
}

/**
 * @brief Test replace function with successful replacement
 * Verifies that an existing item can be successfully replaced
 */
TEST_CASE( "replace - Successful replacement", "[replace]" ) {
    ArrayBag<std::string> stringBag;
    stringBag.add("hello");
    stringBag.add("world");
    stringBag.add("test");
    
    REQUIRE( replace(stringBag, "world", "universe") == true );
    REQUIRE( stringBag.contains("universe") == true );
    REQUIRE( stringBag.contains("world") == false );
}

/**
 * @brief Test replace function with item not found
 * Verifies that attempting to replace a non-existent item returns false
 */
TEST_CASE( "replace - Item not found", "[replace]" ) {
    ArrayBag<std::string> stringBag;
    stringBag.add("hello");
    stringBag.add("world");
    
    REQUIRE( replace(stringBag, "nonexistent", "replacement") == false );
    REQUIRE( stringBag.contains("hello") == true );
    REQUIRE( stringBag.contains("world") == true );
}

/**
 * @brief Test replace function with empty bag
 * Verifies that attempting to replace in an empty bag returns false
 */
TEST_CASE( "replace - Empty bag", "[replace]" ) {
    ArrayBag<std::string> emptyBag;
    REQUIRE( replace(emptyBag, "anything", "replacement") == false );
}

/**
 * @brief Test replace function with multiple occurrences
 * Verifies behavior when the item to replace appears multiple times
 */
TEST_CASE( "replace - Multiple occurrences", "[replace]" ) {
    ArrayBag<std::string> stringBag;
    stringBag.add("duplicate");
    stringBag.add("unique");
    stringBag.add("duplicate");
    
    bool result = replace(stringBag, "duplicate", "replaced");
    REQUIRE( result == true );
    REQUIRE( stringBag.contains("replaced") == true );
}

/**
 * @brief Test replace function with same value replacement
 * Verifies that replacing an item with itself works correctly
 */
TEST_CASE( "replace - Same value replacement", "[replace]" ) {
    ArrayBag<std::string> stringBag;
    stringBag.add("hello");
    stringBag.add("world");
    
    REQUIRE( replace(stringBag, "hello", "hello") == true );
    REQUIRE( stringBag.contains("hello") == true );
}

/**
 * @brief Test replace function with empty string
 * Verifies that empty strings are handled correctly
 */
TEST_CASE( "replace - Empty string handling", "[replace]" ) {
    ArrayBag<std::string> stringBag;
    stringBag.add("");
    stringBag.add("nonempty");
    
    REQUIRE( replace(stringBag, "", "filled") == true );
    REQUIRE( replace(stringBag, "nonempty", "") == true );
}

