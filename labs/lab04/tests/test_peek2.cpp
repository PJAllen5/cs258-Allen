#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do
                           // this in one cpp file

#include "../StackPeek2.h"
#include "catch.hpp"


TEST_CASE("### Peek2 ###", "[peek2]")
{
    StackPeek2<int> myStack;
    // peek2 should fail (stack size is zero), make sure
    // it throws an exception
    REQUIRE_THROWS_AS(myStack.peek2(), PeekException);
    for (int i = 0; i < 7; i++)
    {
        myStack.push(i);
    }
    REQUIRE(myStack.peek2() == 5);
    REQUIRE(myStack.peek2() == 5);
    myStack.push(7);
    REQUIRE(myStack.peek2() == 6);
}

// peek2 needs TWO entries, so one entry must still throw
TEST_CASE("### Peek2 - fewer than two entries ###", "[peek2]")
{
    StackPeek2<int> myStack;
    REQUIRE_THROWS_AS(myStack.peek2(), PeekException);  // zero entries

    myStack.push(1);
    REQUIRE(myStack.peek() == 1);
    REQUIRE_THROWS_AS(myStack.peek2(), PeekException);  // one entry

    myStack.push(2);
    REQUIRE(myStack.peek2() == 1);  // two entries is enough
}

// your exception must inherit from std::exception
TEST_CASE("### Peek2 - exception type ###", "[peek2]")
{
    StackPeek2<int> myStack;
    REQUIRE_THROWS_AS(myStack.peek2(), std::exception);
}

// neither peek nor peek2 may remove anything
TEST_CASE("### Peek2 - peeking does not pop ###", "[peek2]")
{
    StackPeek2<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    REQUIRE(myStack.peek() == 3);
    REQUIRE(myStack.peek2() == 2);
    REQUIRE(myStack.peek() == 3);   // still there
    REQUIRE(myStack.peek2() == 2);  // still there

    myStack.pop();  // now remove one for real
    REQUIRE(myStack.peek() == 2);
    REQUIRE(myStack.peek2() == 1);
}
