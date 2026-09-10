/**
 * @file code.hpp
 * @brief Header file containing stack manipulation functions and string
 * language validation
 */

#include <string>
#include <stack>

/**
 * @brief Displays the contents of a stack in reverse order (bottom to top)
 *
 * This function displays stack elements such that the top element is displayed
 * last, effectively showing the stack contents in the order they were inserted.
 * The original stack remains unchanged after the operation.
 *
 * @param aStack Reference to the stack to be displayed
 * @pre Stack can be empty or contain any number of integer elements
 * @post Stack contents are displayed in reverse order, original stack unchanged
 */
void displayBackward(std::stack<int>& aStack);

/**
 * @brief Counts the number of items in a stack without modifying the stack
 *
 * This function returns the total number of elements in the provided stack
 * while ensuring the stack remains in its original state after counting.
 *
 * @param aStack Reference to the stack to be counted
 * @return int The number of elements in the stack
 * @pre Stack can be empty or contain any number of integer elements
 * @post Stack remains unchanged, returns accurate count of elements
 */
int countStack(std::stack<int>& aStack);

/**
 * @brief Removes all occurrences of a specified item from a stack
 *
 * This function creates and returns a new stack containing all elements from
 * the original stack except for the specified item. The order of remaining
 * elements is preserved. The original stack is not modified.
 *
 * @param aStack Reference to the source stack
 * @param item The integer value to be removed from the stack
 * @return std::stack<int> New stack with all occurrences of item removed
 * @pre aStack can be empty or contain any number of integer elements
 * @post Returns new stack without specified item, original stack unchanged,
 *       order of remaining elements preserved
 */
std::stack<int> deleteOccurr(std::stack<int>& aStack, int item);

/**
 * @brief Determines whether a string belongs to language L = {s s' : s is a
 * string, s' = reverse(s)}
 *
 * This function checks if a string is a valid member of the specified formal
 * language. A string is in the language if:
 * - It has even length and is at least 2 characters long
 * - It is a palindrome (reads the same forwards and backwards)
 * - It is not empty and not a single character
 *
 * The function uses a stack-based approach to determine if the string is a
 * palindrome by comparing the first half with the reverse of the second half.
 *
 * @param theString The string to be evaluated
 * @return bool True if the string is in language L, false otherwise
 * @pre theString can be any valid std::string
 * @post Returns true for valid palindromes of even length >= 2, false otherwise
 *
 * @note Empty strings, single characters, and odd-length strings are not in the
 * language
 * @note The comparison is case-sensitive
 */
bool inLanguage(std::string theString);
