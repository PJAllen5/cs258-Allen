# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
Note, you can use the C++ stack library by adding `#include <stack>`
#### Part 1
- Suppose that you have a stack `aStack` and an empty auxiliary stack `auxStack`. Show how you can do each of the following tasks by using only the ADT stack operations.
  a. Display the contents of aStack in reverse order; that is, display the top last.
  b. Count the number of items in `aStack`, leaving `aStack` unchanged.
  c. Delete every occurrence of a specified item from `aStack`, leaving the order of the remaining items unchanged.
- Suppose that the ADT stack included a method remove(n) that removes the topmost n entries from a stack.  Specify this method by writing comments and a header. Consider the various ways that the method could behave when the stack does not contain at least n entries.
- Write a function that uses a stack to determine whether a string is in the language L, where
  - L = {s s' : s is a string of characters, s' = reverse (s) }
  - Note: The following strings are not in the language: The empty string, a string with fewer than two characters, and a string with an odd number of characters.
  - Hint, get the length of the string before you start doing stack operations

### Setup command
N/A

### Run command
`make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
