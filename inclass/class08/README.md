# CS258 in-class-7: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Consider an ADT list of integers. Write a function that computes the sum of the integers in the list 	aList. The definition of your function should be independent of the list’s implementation.  Hint: use getLength() and getEntry()
- Write a function swap(aList, i, j) that interchanges the items currently in positions i and j of a list. Define the function in terms of the ADT list operations, so that it is independent of any particular implementation of the list. What if the list, does not have items at positions i and j? Return a value that indicates whether the swap is successful.
- Use the function swap that you wrote in Exercise 2 to write a function that reverses the order of the items in a list aList.
-  Write a function getPosition at the client level thatreturns the position of a given entry within a given list
- Write a function contains at the client level that tests whether a given list contains a given entry.
- The ADT list method remove removes from the list the entry at a given position. Suppose that the ADT list has another method remove that removes a given entry from the list. What if list contains duplicate entries?  Write a function remove at the client level that removes a given entry from a given list.

### Setup command
N/A

### Run command
`make code`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
