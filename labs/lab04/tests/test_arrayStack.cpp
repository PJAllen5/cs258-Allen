#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../ArrayStackRS.h"
#include "catch.hpp"


TEST_CASE("### ArrayStack ###", "[arraystack]")
{
    ArrayStackRS<int> myStack;

    for (int i = 0; i < 7; i++)
    {
        myStack.push(i);
    }
    REQUIRE(myStack.getSize() == 10);
    for (int i = 0; i < 27; i++)
    {
        myStack.push(i);
    }
    REQUIRE(myStack.getSize() == 40);
}

// growing the array must not lose or reorder anything that was already in it
TEST_CASE("### ArrayStackRS - items survive the resize ###", "[arraystack]")
{
    ArrayStackRS<int> myStack;
    for (int i = 0; i < 30; i++)
    {
        myStack.push(i * 10);
    }
    REQUIRE(myStack.getSize() == 40);

    // pop everything back off - it must come out in reverse order, intact
    for (int i = 29; i >= 0; i--)
    {
        REQUIRE(myStack.peek() == i * 10);
        REQUIRE(myStack.pop());
    }
    REQUIRE(myStack.isEmpty());
}

// it only doubles when it actually runs out of room
TEST_CASE("### ArrayStackRS - grows at the right moment ###", "[arraystack]")
{
    ArrayStackRS<int> myStack;
    REQUIRE(myStack.getSize() == 5);  // MAX_STACK, before anything is pushed
    REQUIRE(myStack.isEmpty());

    for (int i = 0; i < 5; i++)
    {
        myStack.push(i);
    }
    REQUIRE(myStack.getSize() == 5);  // exactly full, no growth yet

    myStack.push(99);
    REQUIRE(myStack.getSize() == 10);  // the 6th push doubles it
    REQUIRE(myStack.peek() == 99);
}

// an empty stack still behaves
TEST_CASE("### ArrayStackRS - empty stack ###", "[arraystack]")
{
    ArrayStackRS<int> myStack;
    REQUIRE(myStack.isEmpty());
    REQUIRE(myStack.pop() == false);
    myStack.push(1);
    REQUIRE(myStack.isEmpty() == false);
    REQUIRE(myStack.pop());
    REQUIRE(myStack.isEmpty());
}
