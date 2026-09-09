# CS258 in class 2: C++
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
`make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
