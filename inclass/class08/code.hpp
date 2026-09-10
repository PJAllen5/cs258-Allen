// code.hpp
#include <string>
#include "ListInterface.h"

/*
 * Consider an ADT list of integers. Write a function that computes the sum of
 * the integers in the list aList. The definition of your function should be
 * independent of the list’s implementation.  Hint: use getLength() and getEntry()
                */
// Takes the INTERFACE, not a concrete list, so it works with any
// implementation of ListInterface - that is the point of the exercise.
int sumOfList(ListInterface<int>& aList);

/* Write a function swap(aList, i, j) that interchanges the items currently in
 * positions i and j of a list. Define the function in terms of the ADT list
    operations, so that it is independent of any particular implementation of the
    list. Assume that the list, in fact, has items at positions i and j.
    Return a value that indicates whether the swap is successful.
 * */


/* Use the function swap that you wrote in Exercise 2 to write a function that
 * reverses the order of the items in a list aList.
 */


/* Write a function getPosition at the client level that returns the position
 * of a given entry within a given list.
 */


/* Write a function contains at the client level that tests whether a given
 * list contains a given entry.
 */


/* The ADT list method remove removes from the list the entry at a given position.
 * Suppose that the ADT list has another method remove that removes a given
 * entry from the list. What if list contains duplicate entries?  Write a function
 * remove at the client level that removes a given entry from a given list.
*/
