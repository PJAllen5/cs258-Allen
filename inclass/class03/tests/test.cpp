#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../code.hpp"
#include "catch.hpp"
#include <iostream>
#include <sstream>
#include <string>

/**
 * Test writeBackward function with base case of string length 1
 * Tests: normal strings, single character strings, empty strings
 * Edge cases: empty string should handle gracefully
 */
TEST_CASE( "### In Class - 1 - writeBackward ###", "[test1]" ) {
    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    
    // Test normal string
    std::cout.rdbuf(captured.rdbuf());
    writeBackward("hello");
    std::string result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "olleh" );
    
    // Test single character (base case)
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeBackward("a");
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "a" );
    
    // Test empty string edge case
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeBackward("");
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "" );
    
    // Test longer string
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeBackward("recursion");
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "noisrucer" );
}

/**
 * Test sumOfInts function - recursive sum from start to end inclusive
 * Tests: normal ranges, single number ranges, negative numbers, invalid ranges
 * Edge cases: start > end, negative values, start == end
 */
TEST_CASE( "### In Class - 2 - sumOfInts ###", "[test2]" ) {
    // Normal cases
    REQUIRE( sumOfInts(2,4) == 9 );
    REQUIRE( sumOfInts(1,8) == 36 );
    REQUIRE( sumOfInts(5,10) == 45 );
    
    // Edge case: single number (start == end)
    REQUIRE( sumOfInts(1,1) == 1 );
    REQUIRE( sumOfInts(5,5) == 5 );
    
    // Edge case: negative numbers
    REQUIRE( sumOfInts(-3,-1) == -6 );
    REQUIRE( sumOfInts(-2,2) == 0 );
    
    // Edge case: start > end (should return 0 or handle gracefully)
    REQUIRE( sumOfInts(5,3) == 0 );
    REQUIRE( sumOfInts(10,1) == 0 );
}

/**
 * Test writeInts function - writes integers 1 through n
 * Tests: normal values, edge cases with n <= 0
 * Edge cases: n = 0, negative n values
 */
TEST_CASE( "### In Class - 3 - writeInts ###", "[test3]" ) {
    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    
    // Normal case
    std::cout.rdbuf(captured.rdbuf());
    writeInts(5);
    std::string result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "12345" );
    
    // Base case: n = 1
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeInts(1);
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "1" );
    
    // Edge case: n = 0 (should print nothing)
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeInts(0);
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "" );
    
    // Edge case: negative n (should print nothing)
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeInts(-5);
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "" );
    
    // Larger case
    captured.str("");
    captured.clear();
    std::cout.rdbuf(captured.rdbuf());
    writeInts(10);
    result = captured.str();
    std::cout.rdbuf(orig);
    REQUIRE( result == "12345678910" );
}

/**
 * Test sumOfN function - sum of first n integers in array
 * Tests: normal arrays, single element, edge cases
 * Edge cases: n = 0, n > array size, negative n
 */
TEST_CASE( "### In Class - 4 - sumOfN ###", "[test4]" ) {
    int myArr[] = {1,3,4,7,2};
    int myArr2[] = {4,6,7,2};
    int myArr3[] = {10};
    int emptyArr[] = {};
    
    // Normal cases
    REQUIRE( sumOfN(3, myArr ) == 8 );
    REQUIRE( sumOfN(4, myArr2) == 19 );
    REQUIRE( sumOfN(1, myArr3) == 10 );
    
    // Edge case: n = 0 (should return 0)
    REQUIRE( sumOfN(0, myArr) == 0 );
    REQUIRE( sumOfN(0, myArr2) == 0 );
    
    // Edge case: negative n (should return 0)
    REQUIRE( sumOfN(-1, myArr) == 0 );
    REQUIRE( sumOfN(-5, myArr2) == 0 );
    
    // Edge case: n larger than what we want to sum
    REQUIRE( sumOfN(5, myArr) == 17 );
    REQUIRE( sumOfN(2, myArr2) == 10 );
    
    // Single element case
    REQUIRE( sumOfN(1, myArr3) == 10 );
}

/**
 * Test fibonacci function - generates nth Fibonacci number
 * Tests: base cases (0,1), normal values, edge cases
 * Edge cases: negative n values should return -1 or 0
 */
TEST_CASE( "### In Class - 5 - fibonacci ###", "[test5]" ) {
    // Base cases
    REQUIRE( fibonacci(0) == 0 );
    REQUIRE( fibonacci(1) == 1 );
    
    // Normal sequence values
    REQUIRE( fibonacci(2) == 1 );
    REQUIRE( fibonacci(3) == 2 );
    REQUIRE( fibonacci(4) == 3 );
    REQUIRE( fibonacci(5) == 5 );
    REQUIRE( fibonacci(6) == 8 );
    REQUIRE( fibonacci(7) == 13 );
    REQUIRE( fibonacci(8) == 21 );
    
    // Edge case: negative n (should return 0 or handle gracefully)
    REQUIRE( fibonacci(-1) == 0 );
    REQUIRE( fibonacci(-5) == 0 );
    
    // Larger Fibonacci numbers
    REQUIRE( fibonacci(10) == 55 );
    REQUIRE( fibonacci(12) == 144 );
}

/**
 * Test arraySearch function - counts occurrences of item in array
 * Tests: normal arrays, no matches, all matches, edge cases
 * Edge cases: length = 0, negative length, null-like scenarios
 */
TEST_CASE( "### In Class - 6 - arraySearch ###", "[test6]" ) {
    int arr1[] = {1, 2, 3, 2, 4, 2};
    int arr2[] = {5, 5, 5, 5};
    int arr3[] = {1, 2, 3, 4, 5};
    int arr4[] = {7};
    
    // Normal cases - multiple occurrences
    REQUIRE( arraySearch(arr1, 6, 2) == 3 );
    REQUIRE( arraySearch(arr2, 4, 5) == 4 );
    
    // Single occurrence
    REQUIRE( arraySearch(arr1, 6, 1) == 1 );
    REQUIRE( arraySearch(arr3, 5, 3) == 1 );
    
    // No occurrences
    REQUIRE( arraySearch(arr1, 6, 7) == 0 );
    REQUIRE( arraySearch(arr3, 5, 10) == 0 );
    
    // Single element array
    REQUIRE( arraySearch(arr4, 1, 7) == 1 );
    REQUIRE( arraySearch(arr4, 1, 8) == 0 );
    
    // Edge case: length = 0 (should return 0)
    REQUIRE( arraySearch(arr1, 0, 2) == 0 );
    REQUIRE( arraySearch(arr2, 0, 5) == 0 );
    
    // Edge case: negative length (should return 0)
    REQUIRE( arraySearch(arr1, -1, 2) == 0 );
    REQUIRE( arraySearch(arr2, -5, 5) == 0 );
    
    // Search in partial array
    REQUIRE( arraySearch(arr1, 3, 2) == 1 );  // Only first 3 elements
    REQUIRE( arraySearch(arr2, 2, 5) == 2 );  // Only first 2 elements
}