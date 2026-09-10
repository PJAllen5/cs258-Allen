# CS258 In-class 17: Heaps
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Implement MinHeap
- Section 2.4.4 of Chapter 2 discussed the problem of finding the k th smallest value in an array of n values. Design
an algorithm that uses a minheap to solve this problem. Using the class ArrayMinHeap defined in Programming
Problem 3, implement your algorithm as a function at the client level.



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
