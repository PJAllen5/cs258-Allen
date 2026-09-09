# CS258 in-class-17: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Write a program that maintains a database containing data, such as name and birthday, about your friends and
relatives. You should be able to enter, remove, modify, or search this data. Initially, you can assume that the
names are unique. 
Design a class to represent the database and another class to represent the people. Use an ADT dictionary (`#include <map>`)
of people as a data member of the database class. 

- Develop a program that can be used to test an implementation of the ADT dictionary

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
