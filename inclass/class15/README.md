# CS258 in-class-14: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Write pseudocode or C++ code for a binary search tree method that visits all nodes whose data lies within a given range of values (such as all values between 100 and 1,000).
- Develop a program that can be used to test an implementation of BinaryTreeInterface.



### Setup command
N/A

### Run command
`make ?`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
