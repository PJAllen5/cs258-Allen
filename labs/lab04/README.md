# CS258 Lab 4: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
#### Part 1 - Chapter 6
- Write a function that uses a stack to test whether a given string is a palindrome. Exercise 14 asked you to write an algorithm for such a function.  The function is `bool isPalindrome(std::string str)`, declared for you in `palindrome.h`; write the body in `palindrome.cpp`.
    - Compare the string exactly as it is given.  Do **not** strip spaces or punctuation, and do **not** ignore capitalisation.  `"abba"` is a palindrome; `"Abba"` is not.
- Design and implement a postfix calculator. Use the algorithm given in this chapter to evaluate postfix expressions as entered into the calculator. Use only the operators +, −, *, and /. Assume that the postfix expressions are syntactically correct.   Hint, this is simple if you use a stack.  Also, there is a library function atoi() that will convert a string to an integer.  The function is `int postFixCalc(std::string expression)`, declared for you in `postfix.h`.
    - Operands and operators are separated by single spaces, as in `"4 5 + 2 *"`.
    - Everything is integer arithmetic, so division truncates toward zero: `"7 2 /"` is `3`.
    - All four operators `+`, `-`, `*`, `/` must work.  Remember that order matters for `-` and `/`: `"7 2 -"` is `5`, not `-5`.


#### Part 2 - Chapter 7
- Write an implementation of the ADT stack that uses a resizable array to represent the stack items. Anytime the stack becomes full, double the size of the array. Maintain the stack's bottom entry at the beginning of the array. Title your class `ArrayStackRS` and inherit from the `ArrayStack` implementation that the book provides (code included in repo).
    - `ArrayStack` has been changed from the book's fixed array to a **dynamically allocated** one.  It holds `ItemType* items`, an `int capacity`, and starts at `MAX_STACK`, which is **5**.  It already provides `getSize()`, which returns the capacity of the array, along with a destructor, copy constructor and assignment operator.
    - This means `ArrayStackRS` only has to override `push`: when the array is full, allocate a new array of twice the capacity, copy the items across, delete the old one, update `items` and `capacity`, and then push.
    - The capacity therefore grows 5 → 10 → 20 → 40.  The unit test depends on this, so do not change the starting capacity.
- The ADT stack lets you peek at its top entry without removing it. For some applications of a stack, you need to also peek at the entry beneath the top entry without removing it. Let's name such an operation `peek2`. If `peek2` fails because the stack contains fewer than two entries, it should throw an exception. Create a custom exception that inherits from the base class `std::exception` and use it in the `peek2` method.   Write a link-based implementation of the ADT stack that includes both `peek` and `peek2`. Call the class `StackPeek2` and inherit from `LinkedStack`.
    - Name your exception class `PeekException` and define it in `StackPeek2.h`.  It must inherit publicly from `std::exception`.  The unit test checks for this type by name, so a plain `std::runtime_error` will not do.
    - `peek2` throws when the stack holds **fewer than two** entries - that means both an empty stack and a stack with exactly one entry.
    - Neither `peek` nor `peek2` may remove anything from the stack.

Note, if you do this properly and understand inheritance, this will need very little coding to complete part 2.  

Example code for `ArrayStack` and `LinkedStack` is included in the repo.  `ArrayStack` is already set up for you, but **`LinkedStack` keeps its member variables `private`**, so `StackPeek2` cannot reach them - change them to `protected`.  Also note, to access protected variables in an inherited class, you will need `this->`

### Setup command
N/A

### Run command
`make` builds everything and runs all four test programs.

To build and run just one of them, use `make run_palindrome`, `make run_postfix`,
`make run_peek2`, or `make run_arrayStack`.


### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **If you do modify the Makefile, make sure the the all command will compile all code and run all of the unit tests**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.

### Grading Rubric (note, this is a rough guide)
I cannot stress enough the importance of readability and documentations.  Code that is hard to read because of poor readability and documentation will be graded harshly.
- Program Correctness 70%
    - 100%: No errors, program always works correctly and meets the specification(s). 
    - 80%: Minor details of the program specification are violated, program functions incorrectly for some inputs.
    - 60%: Significant details of the specification are violated, program often exhibits incorrect behavior.
    - 0%: Program only functions correctly in very limited cases or not at all.   **Code does not compile.**  If the code does not compile, it is an zero for the program correctness portion of your grade.  Code must compile using `make` command.  Note, if parts of your code do not work, you might modify the `Makefile` to only compile the portions that do work.   If you do this, make sure the `all` command will compile all files and unit tests and run the unit tests.  
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

