#define CATCH_CONFIG_MAIN
#include "../LinkedBag.h"
#include "catch.hpp"
#include <vector>
#include <algorithm>

/**
 * Test the recursive frequency counter method getFreqRec.
 * Verifies that it returns the same results as the iterative getFrequencyOf method.
 */
TEST_CASE("getFreqRec - Basic functionality")
{
    LinkedBag<int> bag;
    bag.add(1);
    bag.add(2);
    bag.add(1);
    bag.add(3);
    bag.add(1);

    REQUIRE(bag.getFreqRec(1) == 3);
    REQUIRE(bag.getFreqRec(2) == 1);
    REQUIRE(bag.getFreqRec(3) == 1);
    REQUIRE(bag.getFreqRec(4) == 0);
}

/**
 * Test getFreqRec with empty bag.
 * Should return 0 for any item when bag is empty.
 */
TEST_CASE("getFreqRec - Empty bag")
{
    LinkedBag<int> bag;
    REQUIRE(bag.getFreqRec(1) == 0);
    REQUIRE(bag.getFreqRec(0) == 0);
}

/**
 * Test getFreqRec with single item.
 * Verifies correct counting with minimal data.
 */
TEST_CASE("getFreqRec - Single item")
{
    LinkedBag<int> bag;
    bag.add(5);

    REQUIRE(bag.getFreqRec(5) == 1);
    REQUIRE(bag.getFreqRec(3) == 0);
}

/**
 * Test getFreqRec with all identical items.
 * Verifies counting when all items are the same.
 */
TEST_CASE("getFreqRec - All identical items")
{
    LinkedBag<int> bag;
    for (int i = 0; i < 5; i++)
    {
        bag.add(7);
    }

    REQUIRE(bag.getFreqRec(7) == 5);
    REQUIRE(bag.getFreqRec(8) == 0);
}

/**
 * Test getFreqRec with string data type.
 * Verifies template functionality works with different types.
 */
TEST_CASE("getFreqRec - String data type")
{
    LinkedBag<std::string> bag;
    bag.add("hello");
    bag.add("world");
    bag.add("hello");
    bag.add("test");
    bag.add("hello");

    REQUIRE(bag.getFreqRec("hello") == 3);
    REQUIRE(bag.getFreqRec("world") == 1);
    REQUIRE(bag.getFreqRec("test") == 1);
    REQUIRE(bag.getFreqRec("missing") == 0);
}

/**
 * Test array constructor with basic integer array.
 * Verifies that all items from array are added to the bag.
 */
TEST_CASE("Array constructor - Basic functionality")
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    LinkedBag<int> bag(arr, size);

    REQUIRE(bag.getCurrentSize() == 5);
    REQUIRE(bag.contains(1));
    REQUIRE(bag.contains(2));
    REQUIRE(bag.contains(3));
    REQUIRE(bag.contains(4));
    REQUIRE(bag.contains(5));
    REQUIRE_FALSE(bag.contains(6));
}

/**
 * Test array constructor with duplicate elements.
 * Verifies that duplicates are properly handled.
 */
TEST_CASE("Array constructor - With duplicates")
{
    int arr[] = {1, 2, 2, 3, 2, 1};
    int size = 6;
    LinkedBag<int> bag(arr, size);

    REQUIRE(bag.getCurrentSize() == 6);
    REQUIRE(bag.getFrequencyOf(1) == 2);
    REQUIRE(bag.getFrequencyOf(2) == 3);
    REQUIRE(bag.getFrequencyOf(3) == 1);
}

/**
 * Test array constructor with empty array.
 * Should create an empty bag.
 */
TEST_CASE("Array constructor - Empty array")
{
    int* arr = nullptr;
    int size = 0;
    LinkedBag<int> bag(arr, size);

    REQUIRE(bag.getCurrentSize() == 0);
    REQUIRE(bag.isEmpty());
}

/**
 * Test array constructor with single element.
 * Verifies minimal case functionality.
 */
TEST_CASE("Array constructor - Single element")
{
    int arr[] = {42};
    int size = 1;
    LinkedBag<int> bag(arr, size);

    REQUIRE(bag.getCurrentSize() == 1);
    REQUIRE(bag.contains(42));
    REQUIRE_FALSE(bag.isEmpty());
}

/**
 * Test array constructor with string array.
 * Verifies template functionality with different data types.
 */
TEST_CASE("Array constructor - String array")
{
    std::string arr[] = {"apple", "banana", "cherry", "apple"};
    int size = 4;
    LinkedBag<std::string> bag(arr, size);

    REQUIRE(bag.getCurrentSize() == 4);
    REQUIRE(bag.getFrequencyOf("apple") == 2);
    REQUIRE(bag.getFrequencyOf("banana") == 1);
    REQUIRE(bag.getFrequencyOf("cherry") == 1);
    REQUIRE(bag.getFrequencyOf("date") == 0);
}

/**
 * Test removeRandom method basic functionality.
 * Verifies that an item is removed and bag size decreases.
 */
TEST_CASE("removeRandom - Basic functionality")
{
    LinkedBag<int> bag;
    bag.add(1);
    bag.add(2);
    bag.add(3);

    int initialSize = bag.getCurrentSize();
    ItemType removedItem = bag.removeRandom();

    REQUIRE(bag.getCurrentSize() == initialSize - 1);
    REQUIRE((removedItem == 1 || removedItem == 2 || removedItem == 3));
    REQUIRE_FALSE(bag.contains(removedItem) && bag.getFrequencyOf(removedItem) == 0);
}

/**
 * Test removeRandom from bag with single item.
 * Should remove the only item and leave bag empty.
 */
TEST_CASE("removeRandom - Single item")
{
    LinkedBag<int> bag;
    bag.add(42);

    ItemType removedItem = bag.removeRandom();

    REQUIRE(removedItem == 42);
    REQUIRE(bag.getCurrentSize() == 0);
    REQUIRE(bag.isEmpty());
    REQUIRE_FALSE(bag.contains(42));
}

/**
 * Test removeRandom from empty bag.
 * Should handle gracefully (may return default value or throw exception).
 */
TEST_CASE("removeRandom - Empty bag")
{
    LinkedBag<int> bag;

    // This test depends on implementation - might return default value or throw
    // For now, we'll test that the bag remains empty
    int initialSize = bag.getCurrentSize();

    // Attempt to remove from empty bag
    try
    {
        ItemType removedItem = bag.removeRandom();
        // If no exception, verify bag is still empty
        REQUIRE(bag.getCurrentSize() == 0);
    }
    catch (...)
    {
        // If exception thrown, that's also acceptable behavior
        REQUIRE(bag.getCurrentSize() == 0);
    }
}

/**
 * Test removeRandom with duplicate items.
 * Verifies that only one instance is removed when duplicates exist.
 */
TEST_CASE("removeRandom - With duplicates")
{
    LinkedBag<int> bag;
    bag.add(5);
    bag.add(5);
    bag.add(5);

    int initialFreq = bag.getFrequencyOf(5);
    ItemType removedItem = bag.removeRandom();

    REQUIRE(removedItem == 5);
    REQUIRE(bag.getFrequencyOf(5) == initialFreq - 1);
    REQUIRE(bag.getCurrentSize() == 2);
}

/**
 * Test removeRandom multiple times.
 * Verifies that repeated calls work correctly until bag is empty.
 */
TEST_CASE("removeRandom - Multiple removals")
{
    LinkedBag<int> bag;
    std::vector<int> originalItems = {1, 2, 3, 4, 5};
    std::vector<int> removedItems;

    // Add items to bag
    for (int item : originalItems)
    {
        bag.add(item);
    }

    // Remove all items
    while (!bag.isEmpty())
    {
        ItemType removed = bag.removeRandom();
        removedItems.push_back(removed);
    }

    // Verify all items were removed
    REQUIRE(bag.getCurrentSize() == 0);
    REQUIRE(removedItems.size() == originalItems.size());

    // Verify all original items were removed (order may differ)
    std::sort(originalItems.begin(), originalItems.end());
    std::sort(removedItems.begin(), removedItems.end());
    REQUIRE(originalItems == removedItems);
}

/**
 * Test removeRandom with string data type.
 * Verifies template functionality with different data types.
 */
TEST_CASE("removeRandom - String data type")
{
    LinkedBag<std::string> bag;
    bag.add("first");
    bag.add("second");
    bag.add("third");

    std::string removed = bag.removeRandom();

    REQUIRE(bag.getCurrentSize() == 2);
    REQUIRE((removed == "first" || removed == "second" || removed == "third"));
    REQUIRE_FALSE(bag.contains(removed) && bag.getFrequencyOf(removed) == 0);
}

/**
 * Test that getFreqRec produces same results as getFrequencyOf.
 * Ensures consistency between recursive and iterative implementations.
 */
TEST_CASE("getFreqRec - Consistency with getFrequencyOf")
{
    LinkedBag<int> bag;
    std::vector<int> testItems = {1, 2, 3, 1, 4, 2, 1, 5};

    for (int item : testItems)
    {
        bag.add(item);
    }

    // Test that both methods return same results
    for (int i = 1; i <= 6; i++)
    {
        REQUIRE(bag.getFreqRec(i) == bag.getFrequencyOf(i));
    }
}
