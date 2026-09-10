#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../ArrayQueue.h"
#include "../SL_PriorityQueue.h"
#include "catch.hpp"

/* Starting point for this session's tests.  Write assertions against
    ArrayQueue as we work through the exercises in the README. */
TEST_CASE("### placeholder ###", "[test1]")
{
    REQUIRE(true);
}

/* The sorted-list priority queue: the highest priority item is the largest
    value, and it sits at the end of the sorted list. */
TEST_CASE("### SL_PriorityQueue ###", "[test2]")
{
    SL_PriorityQueue<int> pq;
    REQUIRE(pq.isEmpty());
    pq.enqueue(3);
    pq.enqueue(1);
    pq.enqueue(7);
    REQUIRE(pq.peek() == 7);
    pq.dequeue();
    REQUIRE(pq.peek() == 3);
    REQUIRE(pq.isEmpty() == false);
}
