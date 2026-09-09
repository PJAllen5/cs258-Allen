# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
#### Part 1 - Chapter 6
- Write a function that uses a stack to test whether a given string is a palindrome. Exercise 14 asked you to write an algorithm for such a function.
- Design and implement a postfix calculator. Use the algorithm given in this chapter to evaluate postfix expressions as entered into the calculator. Use only the operators +, −, *, and /. Assume that the postfix expressions are syntactically correct.   Hint, this is simple if you use a stack.  Also, there is a library function atoi() that will convert a string to an integer.


#### Part 2 - Chapter 7
- Write an implementation of the ADT stack that uses a resizable array to represent the stack items. Anytime the stack becomes full, double the size of the array. Maintain the stack’s bottom entry at the beginning of the array. Title your class `ArrayStackRS` and Inherit from the `ArrayStack` implementation that the book provides (code included in repo).  In addition to the code necessary to implement the growing of the array, add a `getSize` method that returns the current size of the array.
- The ADT stack lets you peek at its top entry without removing it. For some applications of a stack, you need to also peek at the entry beneath the top entry without removing it. Let’s name such an operation `peek2`. If `peek2` fails because the stack contains fewer than two entries, it should throw an exception. Create a custom exception that inherits from the base class exception and use it in the `peek2` method.   Write a link-based implementation of the ADT stack that includes both `peek` and `peek2`. Call the class `StackPeek2` and inherit from `LinkedStack`.  

Note, if you do this properly and understand inheritance, this will need very little coding to complete part 2.  

Example code for ArrayStack and LinkedStack is included in the repo.  You might have to modify the variables from private to protected status.  Also note, to access protected variables in an inherited class,  you will need `this->`

### Setup command
N/A

### Run command
`make all`


### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **If you do modify the Makefile, make sure the the all command will compile all code and run all of the unit tests**
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

