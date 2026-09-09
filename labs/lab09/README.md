# CS258 Lab 9: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
- Write a Makefile that compiles and tests your programs.   Write appropriate unit tests.  Unit tests must have docstrings explaining what they are testing.

#### Part 1 - Chapter 16
- Complete the implementation of the class `BinaryNodeTree` that was begun in Section 16.2.2 of this chapter.
- Implement the class BinarySearchTree, as given in Listing 16-4.
- Note that these are dependent on the `NotFoundException.h`, which is not  provided.   Please see the appropriate interlude in the book for creating a custom exception.

#### Part 2 - Chapter 17
- Complete the implementation file for the class ArrayMaxHeap that is described in Section 17.2.2.


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

### Setup command
N/A

### Run command
`make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace
`<x>` with the test number.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
