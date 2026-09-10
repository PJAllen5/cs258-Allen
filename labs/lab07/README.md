# CS258 Lab 7: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
There is no Makefile in this folder - you write it from scratch, as you did in lab 6.
Running just `make` must compile all code and run all of your unit tests, and there must
be a `clean` command.  Implement appropriate unit tests; every test needs a docstring
explaining what it is testing.  The Catch2 header is provided in `tests/catch.hpp`.

Compile with `-Wall -Wextra` in every rule, as the provided Makefiles in the earlier
labs do:

```
g++ -std=c++11 -Wall -Wextra -c yourfile.cpp
```

These two flags ask the compiler to report code that is legal but almost certainly
wrong - a function that never returns a value, an unused variable, an `if` whose
indentation lies about what it guards.  They do not change what your program does.  A
warning is not a failed build, but treat one as a bug until you have proved otherwise.


#### Chapter 12 - the circular list
- Consider an ADT circular list, which is like the ADT list but treats its first entry as if it were immediately after its last entry. For example, if a circular list contains six items, retrieval or removal of the eighth item actually involves the list’s second item. Let insertion into a circular list, however, behave exactly like insertion into a list. 

Define and implement the ADT circular list inheriting/implementing ListInterface.  This implementation should not have a head pointer, but only a tail pointer and must be linked based using the Node class (no structs).  Also the last node must have a pointer to the first, thus a true circular list.   

Call your class `CircularList`, in `CircularList.h` and `CircularList.cpp`.

Example code for LinkedList is included in the repo.

##### What wraps, and what does not

- `getEntry`, `replace` and `remove` **wrap**.  On a six item list, position 8 refers to
  position 2, position 13 refers to position 1, and so on.
- `insert` does **not** wrap.  It behaves exactly as it does in an ordinary list, so a
  position outside `1` to `getLength() + 1` fails and returns false.

Note this means your class deliberately breaks the preconditions written in
`ListInterface.h`.  Those docstrings say `1 <= position <= getLength()`; for the three
wrapping operations that restriction no longer applies, and your own docstrings should
say what your version does instead.

##### The two cases the wrapping formula does not cover

Work out the arithmetic before you write it - both of these will bite you otherwise.

- **An empty list.** Wrapping a position means dividing by the length, and the length is
  zero.  `getEntry` and `replace` on an empty list must throw `PrecondViolatedExcep`
  (provided for you in the repo, and already used by the supplied `LinkedList`).
  `remove` on an empty list returns false.
- **Position zero or negative.** In C++, `-1 % 6` is `-1`, not `5`, so the obvious
  formula walks off the front of the list.  Positions below `1` are invalid: throw
  `PrecondViolatedExcep` from `getEntry` and `replace`, and return false from `remove`.

Your unit tests must cover both of these.

### Setup command
N/A



### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **If you do modify the Makefile, make sure the the all command will compile all code and run all of the unit tests**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.

### Grading Rubric

| Category | Points |
| -------- | ------ |
| Implementation Correctness | 50 |
| Unit Tests | 30 |
| Code Quality & Documentation | 20 |
| **Total** | **100** |

- **Implementation Correctness (50)** - the circular list behaves correctly, including wrapping, the empty list, and invalid positions.  Code must compile.  Code that does not compile receives 0 for this category.
- **Unit Tests (30)** - you write the tests for this lab, so they are worth real credit.  Cover wrapping past the end, the empty list, position zero, and the fact that `insert` does not wrap.  Tests that only exercise the easy path do not earn full marks.
- **Code Quality & Documentation (20)** - readable, consistently formatted code, meaningful names, file headers, and docstrings on every method and every test.
