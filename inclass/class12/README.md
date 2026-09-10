# CS258 In-class 12: Inheritance and the Sorted List
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Consider an ADT front list, which restricts insertions, removals, and retrievals to the first item in the list. Implement FrontList in each of the following ways:
  - a. Store the list’s entries in an instance of LinkedList.
  - b. Derive FrontList from LinkedList using public inheritance.
  - c. Derive FrontList from LinkedList using private inheritance.
  
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
