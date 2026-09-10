#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../LinkedBag.h"
#include "catch.hpp"

// Test linked bag
TEST_CASE("### 1 - Linked Bag ###", "[test1]")
{
    LinkedBag<int> theBag;
    for (int i = 1; i < 6; i++)
    {
        theBag.add(i);
        REQUIRE(theBag.getCurrentSize() == i);
    }
    std::vector<int> v1 = {5, 4, 3, 2, 1};
    REQUIRE(theBag.toVector() == v1);
    REQUIRE(theBag.getCurrentSizeRecursive() == 5);
    REQUIRE(theBag.getCurrentSizeIterative() == 5);
    REQUIRE(theBag.getCurrentSize() == 5);

    theBag.add(3);
    theBag.addEnd(3);

    // add() puts the new node at the FRONT, addEnd() puts it at the BACK.
    // The bag held {5,4,3,2,1}, so it must now hold {3,5,4,3,2,1,3}.
    std::vector<int> v2 = {3, 5, 4, 3, 2, 1, 3};
    REQUIRE(theBag.toVector() == v2);

    REQUIRE(theBag.getFrequencyOfRecursive(3) == 3);
    REQUIRE(theBag.getCurrentSizeRecursive() == 7);
    REQUIRE(theBag.getCurrentSizeIterative() == 7);
    REQUIRE(theBag.getCurrentSize() == 7);
}

// An empty bag - this is the base case of every recursive method
TEST_CASE("### 2 - Linked Bag, empty ###", "[test2]")
{
    LinkedBag<int> theBag;
    REQUIRE(theBag.isEmpty());
    REQUIRE(theBag.getCurrentSize() == 0);
    REQUIRE(theBag.getCurrentSizeRecursive() == 0);
    REQUIRE(theBag.getCurrentSizeIterative() == 0);
    REQUIRE(theBag.getFrequencyOfRecursive(9) == 0);
}

// addEnd has to work when there is no chain to walk to the end of
TEST_CASE("### 3 - addEnd on an empty bag ###", "[test3]")
{
    LinkedBag<int> theBag;
    theBag.addEnd(7);
    std::vector<int> v = {7};
    REQUIRE(theBag.toVector() == v);
    REQUIRE(theBag.getCurrentSize() == 1);
    REQUIRE(theBag.getCurrentSizeRecursive() == 1);
    REQUIRE(theBag.getCurrentSizeIterative() == 1);

    theBag.addEnd(8);
    std::vector<int> v2 = {7, 8};
    REQUIRE(theBag.toVector() == v2);
}

// getFrequencyOfRecursive must agree with the provided getFrequencyOf,
// including for items that are not in the bag
TEST_CASE("### 4 - recursive frequency ###", "[test4]")
{
    LinkedBag<int> theBag;
    theBag.add(4);
    theBag.add(7);
    theBag.add(4);
    theBag.add(1);
    REQUIRE(theBag.getFrequencyOfRecursive(4) == 2);
    REQUIRE(theBag.getFrequencyOfRecursive(7) == 1);
    REQUIRE(theBag.getFrequencyOfRecursive(99) == 0);
    REQUIRE(theBag.getFrequencyOfRecursive(4) == theBag.getFrequencyOf(4));
    REQUIRE(theBag.getFrequencyOfRecursive(99) == theBag.getFrequencyOf(99));
}
