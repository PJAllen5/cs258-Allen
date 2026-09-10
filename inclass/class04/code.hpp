/**
 * @file code.hpp
 * @brief Header file containing function declarations for bag operations
 *
 * This file contains declarations for client functions that operate on ArrayBag
 * objects. Includes functions for computing sum of integers in a bag and
 * replacing items in a string bag.
 */

#include <string>
#include "ArrayBag.h"

/**
 * @brief Computes the sum of all integers in a bag
 *
 * This function iterates through all items in the provided ArrayBag of integers
 * and calculates their total sum. Empty bags return a sum of 0.
 *
 * @param aBag Reference to an ArrayBag containing integers
 * @return int The sum of all integers in the bag
 */
int sumOfBag(ArrayBag<int>& aBag);

/**
 * @brief Replaces a specific item in a string bag with a new item
 *
 * This function searches for the first occurrence of itemToReplace in the bag
 * and replaces it with the replacement string. The function maintains the bag's
 * structure and only replaces the first matching item found.
 *
 * @param aBag Reference to an ArrayBag containing strings
 * @param itemToReplace The string item to search for and replace
 * @param replacement The string to replace the found item with
 * @return bool true if the replacement was successful, false if item was not
 * found
 */
bool replace(ArrayBag<std::string>& aBag, std::string itemToReplace,
             std::string replacement);
