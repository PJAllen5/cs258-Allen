# CS258 Lab 3: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
#### Part 1 - Chapter 4
- LinkedBag
    - Revise the public method `add` in the class `LinkedBag` so that the new node is inserted at the end of the linked chain.  Call this new method `addEnd`.  Keep the original `add` method unchanged. 
    - Suppose that the class `LinkedBag` did not have the data member itemCount. Revise the method `getCurrentSize` so that it counts the number of nodes in the linked chain Iteratively and Recursively.  Call these new methods `getCurrentSizeRecursive` and `getcurrentSizeIterative`.
    - Revise the public method `getFrequencyOf` in the class `LinkedBag` so that it is recursive.  Call this `getFrequencyOfRecursive`.  Leave `getFrequencyOf` method unmodified.
- In a doubly linked chain, each node can point to the previous node as well as to the next node. figure 4-9 from the book shows a doubly linked chain and its head pointer. define a class to represent a node in a doubly linked chain, call it `doublelinknode`.  There is a header file partially created.  finish its implementation and write the .cpp file. hint: take a look at the `node.h` and `node.cpp` file.   Note, we are only creating the double linked node, not a double linked list or bag.

To compile these classes, there is a unit test that creates a concrete instance of this class.  Note, that you should never compile a template class directly.   If it compiles, it will give odd behavior that is hard to debug.   

### Setup command
N/A

### Run command (this will compile and run the unit tests)
`make`


### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

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

