# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
- Write a Makefile that compiles and tests your programs.   Write unit tests in the tests directory.  Unit tests must have docstrings explaining what they are testing.

#### Part 1 - chapter 14
- Write a link-based implementation of a queue that uses a circular linked chain to represent the items in the queue (you can re-use code from your circular list from assignment 7). You will need a single tail pointer.   Your implementation must inherit from the Queue interface and properly implement the required methods.  

When you are done, compare your implementation to the one given in this chapter that uses a linear linked chain with two external pointers. Which implementation is easier to write? Which is easier to understand? Which is more efficient?  Answer these questions in the README.md.
- Be sure to modify the makefile to compile this implementation and write a proper unit tests to test it. 

#### Part 2 - chapter 15 
Develop a program that can be used to test an implementation of BinaryTreeInterface.  The preferred method is to write unit tests.  The interface and an implementation is included to help with your test writing.   Note, you will have to write the NotFoundException class.  See Interlude 3 from the book for help.  

### Setup command
N/A

### Run command
`make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.

### Grading Rubric (note, this is a rough guide)
- Program Correctness 50%
    - 100%: No errors, program always works correctly and meets the specification(s). 
    - 80%: Minor details of the program specification are violated, program functions incorrectly for some inputs.
    - 60%: Significant details of the specification are violated, program often exhibits incorrect behavior.
    - 0%: Program only functions correctly in very limited cases or not at all.   **Code does not compile.**  If the code does not compile, it is an zero for the program correctness portion of your grade.  Code must compile using `make` command.  This may require modifications to the `Makefile`.
- Unit Tests 20%
    - 100%: Unit tests cover all functions/methods including corner and edge cases. 
    - 80%: Missing tests of a few methods.
    - 60%: Missing tests for many of the methods/functions.
    - 0%: No unit tests or the unit tests do not compile.
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