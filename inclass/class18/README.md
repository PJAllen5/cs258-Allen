# CS258 In-class 18: Dictionaries
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
`make` builds everything and runs the unit tests.

`make test` runs just the tests.

### Other test commands
Use `make test1` or `make test2` to run a single tagged test.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
