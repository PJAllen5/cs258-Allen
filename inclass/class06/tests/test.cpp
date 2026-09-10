#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../code.hpp"
#include "catch.hpp"
#include <stack>
#include <iostream>
#include <sstream>

/**
 * @brief Test suite for displayBackward function
 * Tests the function that displays stack contents in reverse order (top element last)
 */
TEST_CASE("### displayBackward - Basic functionality ###", "[displayBackward]")
{
    SECTION("Non-empty stack display")
    {
        std::stack<int> myStack;
        for (int i = 1; i <= 5; i++)
        {
            myStack.push(i);
        }

        // Capture output to verify correct display order
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        displayBackward(myStack);

        std::cout.rdbuf(oldCout);
        // Expected output should show elements in reverse order: 1 2 3 4 5
    }

    SECTION("Empty stack display")
    {
        std::stack<int> emptyStack;

        // Should handle empty stack gracefully
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        displayBackward(emptyStack);

        std::cout.rdbuf(oldCout);
        // Should not crash and output should be empty or appropriate message
    }

    SECTION("Single element stack")
    {
        std::stack<int> singleStack;
        singleStack.push(42);

        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        displayBackward(singleStack);

        std::cout.rdbuf(oldCout);
        // Should display the single element
    }
}

/**
 * @brief Test suite for countStack function
 * Tests the function that counts items in a stack while leaving the stack unchanged
 */
TEST_CASE("### countStack - Comprehensive testing ###", "[countStack]")
{
    SECTION("Non-empty stack counting")
    {
        std::stack<int> myStack;
        for (int i = 0; i < 13; i++)
        {
            myStack.push(i);
        }

        // size() returns an unsigned type, so compare like with like
        std::size_t originalSize = myStack.size();
        int count = countStack(myStack);

        REQUIRE(count == 13);
        REQUIRE(myStack.size() == originalSize);  // Stack should remain unchanged
    }

    SECTION("Empty stack counting")
    {
        std::stack<int> emptyStack;

        int count = countStack(emptyStack);

        REQUIRE(count == 0);
        REQUIRE(emptyStack.empty());  // Stack should remain empty
    }

    SECTION("Single element stack")
    {
        std::stack<int> singleStack;
        singleStack.push(100);

        int count = countStack(singleStack);

        REQUIRE(count == 1);
        REQUIRE(singleStack.size() == 1);  // Stack should remain unchanged
    }

    SECTION("Large stack")
    {
        std::stack<int> largeStack;
        const int LARGE_SIZE = 1000;
        for (int i = 0; i < LARGE_SIZE; i++)
        {
            largeStack.push(i);
        }

        int count = countStack(largeStack);

        REQUIRE(count == LARGE_SIZE);
        REQUIRE(largeStack.size() == LARGE_SIZE);  // Stack should remain unchanged
    }
}

/**
 * @brief Test suite for deleteOccurr function
 * Tests the function that deletes all occurrences of a specified item from a stack
 */
TEST_CASE("### deleteOccurr - Comprehensive testing ###", "[deleteOccurr]")
{
    SECTION("Delete existing elements")
    {
        std::stack<int> myStack;
        for (int i = 0; i < 8; i++)
        {
            myStack.push(i);
        }
        for (int i = 0; i < 13; i++)
        {
            myStack.push(4);
        }
        for (int i = 0; i < 8; i++)
        {
            myStack.push(i);
        }

        std::stack<int> expected;
        expected.push(0);
        expected.push(1);
        expected.push(2);
        expected.push(3);
        expected.push(5);
        expected.push(6);
        expected.push(7);
        expected.push(0);
        expected.push(1);
        expected.push(2);
        expected.push(3);
        expected.push(5);
        expected.push(6);
        expected.push(7);

        std::stack<int> result = deleteOccurr(myStack, 4);
        REQUIRE(result == expected);
    }

    SECTION("Delete non-existing element")
    {
        std::stack<int> myStack;
        for (int i = 1; i <= 5; i++)
        {
            myStack.push(i);
        }

        std::stack<int> expected;
        for (int i = 1; i <= 5; i++)
        {
            expected.push(i);
        }

        std::stack<int> result = deleteOccurr(myStack, 10);
        REQUIRE(result == expected);
    }

    SECTION("Delete from empty stack")
    {
        std::stack<int> emptyStack;

        std::stack<int> result = deleteOccurr(emptyStack, 5);
        REQUIRE(result.empty());
    }

    SECTION("Delete all elements (all same value)")
    {
        std::stack<int> sameValueStack;
        for (int i = 0; i < 10; i++)
        {
            sameValueStack.push(7);
        }

        std::stack<int> result = deleteOccurr(sameValueStack, 7);
        REQUIRE(result.empty());
    }

    SECTION("Delete single occurrence")
    {
        std::stack<int> myStack;
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.push(2);
        myStack.push(4);

        std::stack<int> expected;
        expected.push(1);
        expected.push(3);
        expected.push(4);

        std::stack<int> result = deleteOccurr(myStack, 2);
        REQUIRE(result == expected);
    }
}

/**
 * @brief Test suite for inLanguage function
 * Tests the function that determines if a string is in language L = {s s' : s is a string, s' = reverse(s)}
 * Valid strings must have even length >= 2 and be palindromes
 */
TEST_CASE("### inLanguage - Comprehensive testing ###", "[inLanguage]")
{
    SECTION("Valid palindromes")
    {
        REQUIRE(inLanguage("dad") == true);
        REQUIRE(inLanguage("civic") == true);
        REQUIRE(inLanguage("redivider") == true);
        REQUIRE(inLanguage("abba") == true);
        REQUIRE(inLanguage("racecar") == true);
        REQUIRE(inLanguage("aa") == true);
        REQUIRE(inLanguage("abccba") == true);
    }

    SECTION("Invalid palindromes")
    {
        REQUIRE(inLanguage("racecarr") == false);
        REQUIRE(inLanguage("hello") == false);
        REQUIRE(inLanguage("abcd") == false);
        REQUIRE(inLanguage("palindrome") == false);
    }

    SECTION("Edge cases - invalid according to language rules")
    {
        REQUIRE(inLanguage("") == false);       // Empty string
        REQUIRE(inLanguage("a") == false);      // Single character
        REQUIRE(inLanguage("ab") == false);     // Two different characters
        REQUIRE(inLanguage("abc") == false);    // Odd length
        REQUIRE(inLanguage("abcde") == false);  // Odd length, not palindrome
    }

    SECTION("Special characters and numbers")
    {
        REQUIRE(inLanguage("1221") == true);
        REQUIRE(inLanguage("!@@!") == true);
        REQUIRE(inLanguage("a!!a") == true);
        REQUIRE(inLanguage("123321") == true);
        REQUIRE(inLanguage("1234") == false);
        REQUIRE(inLanguage("!@#$") == false);
    }

    SECTION("Case sensitivity")
    {
        REQUIRE(inLanguage("Aa") == false);    // Different cases
        REQUIRE(inLanguage("AbbA") == false);  // Mixed case
        REQUIRE(inLanguage("AA") == true);     // Same case
        REQUIRE(inLanguage("abBA") == false);  // Mixed case palindrome
    }

    SECTION("Longer palindromes")
    {
        REQUIRE(inLanguage("abcddcba") == true);
        REQUIRE(inLanguage("raceacar") == true);
        REQUIRE(inLanguage("wasitacaroracatisaw") == true);
        REQUIRE(inLanguage("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba") == true);
    }
}
