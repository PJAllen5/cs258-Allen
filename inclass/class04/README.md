# CS258 In-class 4: Bags and Designing an ADT
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Consider a bag of integers. Write a client function that computes the sum of the integers in the bag aBag.
- Write a client function replace that replaces a given item in a given bag with another given item. The function should return a boolean value to indicate whether the replacement was successful.
- Design and implement an ADT that represents a rectangle. Include typical operations, such as setting and retrieving the dimensions of the rectangle, and finding the area and the perimeter of the rectangle.  This ADT should include:
    - A virtual class called RectangleInterface
    - A Recentangle class (header and .cpp file) that inherits from the virtual class
    - These should be in seperate files.  Modify the Makefile to compile these

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
