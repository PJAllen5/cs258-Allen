# CS258 Lab 2a: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment

#### Part 2 - chapter 3 - array based implementations
For this part of the assignment, create a class for each problem.  Note, you will have to modify the header file also.  I would suggest writing the code for the header first.
- Implement the ADT `Polynomial` that Exercise 9 in Chapter 1 describes by using an array.  Make sure to include a constructor.  The constructor should have a parameter, a double array.   
    -   If you look at the unit tests (tests/test.cpp), it gives some clues on
        how to implement this.
    -   The constructor has two parameters, an array of co-efficients and the
        degree of the polynomial.   In the unit test example,     
    ```
    int testArr[6] = {9,0,1,7,0,4};
    Polynomial myPoly(testArr, 5);
    ```
    -   The constructor shows passing in an array of size 6, and the parameter 5.   5 is the largest polynomial. The example represents 9x^0 + 0x^1 + 1x^2 + 7x^3 + 0x^4 + 4x^5 polynomial.   We can see 5 is the largest exponent.  But we don't need to store the exponents, we just the the place of the coefficient in the array to represent the exponent.



**The calender ADT is extra credit**
- Design and implement an ADT that represents a calendar date.  Call this class `calendar`. You can represent a date’s month, day, and year as integers (for example, 4/1/2014). Include operations that advance the date by one day and display the date by using either numbers or words for the months. As an enhancement, include the name of the day.  Create a new `.cpp` with a main() function that demonstrates the calendar.   Add a line to the `Makefile` to compile this file (also modify the clean to remove it).

### Setup command
N/A

### Makefile
Modify the Makefile so that running `make` compiles all code **and** runs all 
unit tests.

#### Note, there is not a test for the `calendar` class.
If you create separate files for the Polynomial, Fraction or Calendar, add the
appropriate lines to the makefile and the unit tests file (import).

### Notes
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
