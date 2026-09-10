# CS258 Lab 2a: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment

#### Chapter 3 - array based implementation
For this part of the assignment you will create a class.  Note, you will have to write the header file also.  I would suggest writing the code for the header first.

The unit tests in `tests/test_poly.cpp` are written for you.  They expect specific names,
so **use exactly these or the tests will not compile:**

| What | Name |
| ---- | ---- |
| Header file | `poly.h` |
| Implementation file | `poly.cpp` |
| Class | `Polynomial` |
| Constructor | `Polynomial(double coefficients[], int degree)` |
| Return the degree | `degree()` |
| Return one coefficient | `coefficient(int exponent)` |
| Change one coefficient | `changeCoefficient(double value, int exponent)` |

Note the argument order of `changeCoefficient` - the new **value** comes first, then the
**exponent** it belongs to.

**Out of range exponents.**  A valid exponent is between `0` and `degree` inclusive.  If
`coefficient` or `changeCoefficient` is given an exponent outside that range, it must
throw `std::out_of_range`.  You will need to `#include <stdexcept>`.  Note this means a
polynomial never grows - `changeCoefficient` cannot be used to add a new term above the
current degree.

**Your constructor must copy the array it is given**, not store a pointer to it.  The
caller must be able to change or destroy their array afterwards without affecting your
polynomial.

- Implement the ADT `Polynomial` that Exercise 9 in Chapter 1 describes by using an array.  Make sure to include a constructor.  The constructor should have a parameter, a double array.   
    -   If you look at the unit tests (`tests/test_poly.cpp`), it gives some clues on
        how to implement this.
    -   The constructor has two parameters, an array of co-efficients and the
        degree of the polynomial.   In the unit test example,     
    ```
    double testArr[6] = {9, 0, 1, 7, 0, 4};
    Polynomial myPoly(testArr, 5);
    ```
    -   The constructor shows passing in an array of size 6, and the parameter 5.   5 is the largest polynomial. The example represents 9x^0 + 0x^1 + 1x^2 + 7x^3 + 0x^4 + 4x^5 polynomial.   We can see 5 is the largest exponent.  But we don't need to store the exponents, we just the the place of the coefficient in the array to represent the exponent.



**The calender ADT is extra credit**
- Design and implement an ADT that represents a calendar date.  Call this class `calendar`. You can represent a date’s month, day, and year as integers (for example, 4/1/2014). Include operations that advance the date by one day and display the date by using either numbers or words for the months. As an enhancement, include the name of the day.  Create a new `.cpp` with a main() function that demonstrates the calendar.   Add a line to the `Makefile` to compile this file (also modify the clean to remove it).

### Setup command
N/A

### Makefile
Running `make` already compiles the `Polynomial` class and runs its unit tests.  You do
not need to change anything to complete the main assignment.

#### Note, there is not a test for the `calendar` class.
If you do the calendar extra credit, add the lines needed to compile it to the Makefile,
and update `clean` to remove its executable.  You may add new targets to the Makefile -
just do not change the existing ones, and do not modify anything in the `tests` directory.

### Notes
- **Do not modify anything in the `tests` directory.**  The tests are written to match the names listed above.
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.

### Grading Rubric (note, this is a rough guide)
- Program Correctness 70%
    - 100%: No errors, program always works correctly and meets the specification(s). 
    - 80%: Minor details of the program specification are violated, program functions incorrectly for some inputs.
    - 60%: Significant details of the specification are violated, program often exhibits incorrect behavior.
    - 0%: Program only functions correctly in very limited cases or not at all.   **Code does not compile.**  If the code does not compile, it is an zero for the program correctness portion of your grade.  Code must compile using `make` command.  This may require modifications to the `Makefile`.
- Readability 10%
    - 100%: No errors, code is clean, understandable, and well organized. 
    - 80%: Minor issues with consistent indentation, use of whitespace, variable naming, or general organization.
    - 60%: At least one major issue with indentation, whitespace, variable names, or organization.
    - 0%: Major problems with at three or four of the readability subcategories.
- Documentation (Comments) 20% 
    - 100%: Code is well-commented 
    - 80%: One or two places that could benefit from comments are missing them or the code is overly commented.
    - 60%: File header missing, complicated lines or sections of code uncommented or lacking meaningful comments.
    - 0%: No file header or comments present.
