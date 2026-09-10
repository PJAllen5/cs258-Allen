# CS258 In-class 9: Array and Linked List Implementations
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Modify the Makefile with options to compile ArrayList, LinkedList or both
- Add a constructor to each of the classes ArrayList and LinkedList that creates a list containing the entries in a given array.
- Implement the method getPosition, as described in Exercise 5 of Chapter 8, for each of the classes ArrayList and LinkedList.
- Repeat the previous exercise, but use recursion in your definitions.
- Implement the method contains, as described in Exercise 7 of Chapter 8, for each of the classes ArrayList and LinkedList.
- Repeat the previous exercise, but use recursion in your definitions.
- Write a recursive definition of the private method getNodeAt for the class LinkedList.
- Write an array-based implementation of the ADT list that expands the size of the array of list entries as needed so that the list can always accommodate a new entry.
- Repeat the previous programming problem, but also reduce the size of the array as needed to accommodate several removals. When the size of the array is greater than 20 and the number of entries in the list is less than half the size of the array, reduce the size of the array so that it is three quarters of its current size.

### Setup command
N/A

### Run command
`make` builds everything and runs the unit tests.

`make test` runs just the tests.

### Other test commands
Use `make test1` or `make test2` to run a single tagged test.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
