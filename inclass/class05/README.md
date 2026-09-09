# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
Note, not all of these items are required.   It depends on how much time we have left after lecture.

#### Part 1
- If headPtr is a pointer variable that points to the first node of a linked chain of at least two nodes, write C++ statements that delete the second node and return it to the system.
- Create a method that performs that same tast as the public method getFrequencyOf in the class LinkedBag, but make it so that it is recursive.  Call this method getFreqRec.
- Add a constructor to the class LinkedBag that creates a bag from a given array of entries.
- Specify and define a method for LinkedBag that removes a random entry from the bag.
- Implement the ADT polynomial that Exercise 9 in Chapter 1 describes by using a linked chain.
### Setup command
N/A

### Run command
`make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make code`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
