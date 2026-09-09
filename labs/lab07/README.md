# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
- For both parts, create the Makefile to compile and run the unit tests.  Implement appropriate unit tests.   Unit tests must have docstrings explaining what they are testing.  Thus running just `make` should compile all code and run all unit tests.

#### Part 1 - Chapter 12
- Consider an ADT circular list, which is like the ADT list but treats its first entry as if it were immediately after its last entry. For example, if a circular list contains six items, retrieval or removal of the eighth item actually involves the list’s second item. Let insertion into a circular list, however, behave exactly like insertion into a list. 

Define and implement the ADT circular list inheriting/implementing ListInterface.  This implementation should not have a head pointer, but only a tail pointer and must be linked based using the Node class (no structs).  Also the last node must have a pointer to the first, thus a true circular list.   

Example code for LinkedList is included in the repo. 

### Setup command
N/A



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
