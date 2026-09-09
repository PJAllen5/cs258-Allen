# CS258 in-class-11: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Consider an ADT front list, which restricts insertions, removals, and retrievals to the first item in the list. Implement FrontList in each of the following ways:
  - a. Store the list’s entries in an instance of LinkedList.
  - b. Derive FrontList from LinkedList using public inheritance.
  - c. Derive FrontList from LinkedList using private inheritance.
  
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
