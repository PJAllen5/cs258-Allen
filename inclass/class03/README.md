# CS258 In-class 3: Recursion
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Revise the function writeBackward, discussed in Section 2.3.1, so that its base case is a string of length 1.
- Given two integers, start and end , where end is greater than start, write a recursive C++ function that returns the sum of the integers from start through end, inclusive.
- Given an integer n > 0, write a recursive C++ function that writes the integers 1, 2, . . ., n .
- Write a recursive function that will compute the sum of the first n integers in an array of at least n integers.
    Hint: Begin with the n th integer.
- Write a program to print out the Fibonacci Sercies.   The first 2 numbers of the Fibonacci sequence is 0,1.   To get the nth Fibonacci number, you add the (n-1) + (n-2) Fibonacci numbers.
- Write a recursive function that takes as input an array, its length and an item that we will seach for.   Return the number of times this item appears in the array.

### Setup command
N/A

### Run command
`make` builds everything and runs the unit tests.

`make test` runs just the tests.

Standalone programs: `make main` then `./main`

### Other test commands
Use `make test1` or `make test2` to run a single tagged test.
:

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
