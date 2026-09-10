# CS258 In-class 7: Stack Implementations
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
#### Part 1
- An operation that displays the contents of a stack can be useful during program debugging. Add a display
method to the ADT stack such that
  - a. The method uses only ADT stack operations; that is, it is independent of the stack’s implementation.
  - b. The method assumes and uses the link-based implementation of the ADT stack and inherit from the `LinkedStack` implementation that the book provides (code included in repo)
  - c. The method assumes and uses the array-based implementation of the ADT stack and inherit from the `ArrayStack` implementation that the book provides (code included in repo)
#### Part 2
Note, you can use the C++ stack library by adding `#include <stack>`
- Suppose that the ADT stack included a method remove(n) that removes the topmost n entries from a stack.  Specify this method by writing comments and a header. Consider the various ways that the method could behave when the stack does not contain at least n entries.
- Write a function that uses a stack to determine whether a string is in the language L, where
  - L = {s s' : s is a string of characters, s' = reverse (s) }
  - Note: The following strings are not in the language: The empty string, a string with fewer than two characters, and a string with an odd number of characters.
  - Hint, get the length of the string before you start doing stack operations

### Setup command
N/A

### Run command
`make` builds everything and runs the unit tests.

`make test` runs just the tests.

### Other test commands
Use `make test1` or `make test2` to run a single tagged test.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
