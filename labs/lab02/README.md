# CS258 Lab 2: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
#### Part 1 - recursion - Chapter 2
- Given an integer n > 0, write a recursive C++ function `sumOfSquares` that returns the sum of the squares of 1 through n.
- Implement a recursive function `power` that computes a^n, where a is a real number and n is a nonnegative integer.  



#### Part 2 - chapter 3 - array based implementations
For this part of the assignment, create a class for each problem.  Note, you will have to create the header file also.  I would suggest writing the code for the header first.

- Specify and implement an ADT for `Fractions`. Provide operations that `add`, `subtract`, `multiply`, and `divide` these numbers.  These methods should return a new Fraction object, not modify any of the existing Fractions. The results of all arithmetic operations should be in lowest terms, so include a private method `reduceToLowestTerms`. Exercise 23 in Chapter 2 will help you with the details of this method. To simplify the determination of a fraction’s sign, you can assume that the denominator of the fraction is positive.  Include a constructor with two int parameters, the numerator and denominator.   Also include a method operator==.   It should look like this:
    - bool operator==(const Fractions& afraction){// fill in appropriate code here to check if the two objects are equal }
    - Writing this code is necessary in order to compare objects with the `==` operator
    - It will also be helpful when viewing the unit test results to overload the `operator<<` function so that printing an instance of Fractions has some meaning.  Note that this is not part of the class, but a function outside the class.  For example, if the class had variable num and den:


```c++
std::ostream& operator<< (std::ostream &out, const Fractions & frac){
    out << frac.num << '/' << frac.den;
    return out;
}
```
### Makefile
Modify the Makefile so that running `make` compiles all code **and** runs all
unit tests.

### Setup command
N/A

### Run command
`make test`

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.

### Grading Rubric (note, this is a rough guide)
I cannot stress enough the importance of readability and documentations.  Code that is hard to read because of poor readability and documentation will be graded harshly.
- Program Correctness 60%
    - 100%: No errors, program always works correctly and meets the specification(s). 
    - 80%: Minor details of the program specification are violated, program functions incorrectly for some inputs.
    - 60%: Significant details of the specification are violated, program often exhibits incorrect behavior.
    - 0%: Program only functions correctly in very limited cases or not at all.   **Code does not compile.**  If the code does not compile, it is an zero for the program correctness portion of your grade.  Code must compile using `make` command.  Note, if parts of your code do not work, you might modify the `Makefile` to only compile the portions that do work.   If you do this, make sure the `all` command will compile all files and unit tests and run the unit tests.  
- Readability 20%
    - 100%: No errors, code is clean, understandable, and well organized. 
    - 80%: Minor issues with consistent indentation, use of whitespace, variable naming, or general organization.
    - 60%: At least one major issue with indentation, whitespace, variable names, or organization.
    - 0%: Major problems with at three or four of the readability subcategories.
- Documentation (Comments) 20% 
    - 100%: Code is well-commented 
    - 80%: One or two places that could benefit from comments are missing them or the code is overly commented.
    - 60%: File header missing, complicated lines or sections of code uncommented or lacking meaningful comments.
    - 0%: No file header or comments present.
