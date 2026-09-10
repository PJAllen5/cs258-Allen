#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../ArrayList.h"
#include "../LinkedList.h"
#include "catch.hpp"

// This session's work is done inside ArrayList and LinkedList themselves, so
// the tests go straight at those classes - there is no separate code.cpp here.
//
// Both classes implement the same ListInterface, so anything you add to one
// should behave identically in the other.  Write each test twice, once per
// implementation, and they should agree.

/* The list behaves the same whichever implementation is underneath. */
TEST_CASE("### both lists agree on the basics ###", "[test1]")
{
    ArrayList<int> arr;
    LinkedList<int> lnk;

    for (int i = 1; i <= 3; i++)
    {
        arr.insert(i, i * 10);
        lnk.insert(i, i * 10);
    }

    REQUIRE(arr.getLength() == 3);
    REQUIRE(lnk.getLength() == 3);
    REQUIRE(arr.getEntry(2) == 20);
    REQUIRE(lnk.getEntry(2) == 20);
}

/* Add your tests for the new constructor, getPosition and contains here -
   once for ArrayList and once for LinkedList. */
TEST_CASE("### the methods you are adding ###", "[test2]")
{
    // REQUIRE( arr.getPosition(20) == 2 );
    // REQUIRE( lnk.contains(30) );
}
