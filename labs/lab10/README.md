# CS258 Lab 10: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
- Write a Makefile to compile and test your programs and write appropriate unit tests.

#### Part 1 - Chapter 18
- A C++ compiler uses a symbol table to keep track of the identifiers that a program uses. When the compiler encounters an identifier, it searches the symbol table to see whether that identifier has already been encountered. If the identifier is new, it is inserted into the table. Thus, the symbol table needs only insertion and retrieval operations. Which implementation of the ADT dictionary would be most efficient as a symbol table?  Put this as a comment in your SymbolTableHash.h file.
- Implement the symbol table described above using the class HashedDictionary
  which uses separate chaining to resolve collisions.  Note, you will need to create the NotFoundException.  The key is the symbol name, the value is its type.  We can represent the type as a string or enum.  Recall your design choices.  Your SymbolTableHash class can inherit from HashedDictionary (private or public inheritance) or it can have an instance of a HashedDictionary as a class variable.  Think about the consequences from each before making your choice.
- Write unit tests  


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

### Setup command N/A 

### Run command `make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace
`<x>` with the test number.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
