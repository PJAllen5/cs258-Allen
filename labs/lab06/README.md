# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
- Create a makefile to compile and test your code.   Write appropriate unit tests.
#### Part 1
- Write a C++ program that implements the following three algorithms and times them for various values of n. The program should display a table of the run times of each algorithm for various values of n. (Note, in your tests you will probably have to run them many times, like 100 or 1000 in a for loop, otherwise they will finish so quickly that the timing information will have little meaning).

```
// Algorithm A
sum = 0;
for i = 1 to n
    sum = sum + i
```

```
// Algorithm B
sum = 0
for i = 1 to n
{
    for j = 1 to i
        sum = sum + 1
}
```

```
// Algorithm C
sum = n * (n + 1) / 2
```

- In mythology, the Hydra was a monster with many heads. Every time the hero chopped off a head, two smaller heads would grow in its place. Fortunately for the hero, if the head was small enough, he could chop it off with-out two more growing in its place. To kill the Hydra, all our hero needed to do was to chop off all the heads.

- Write a program that simulates the Hydra. Create a class for this.  Instead of heads, we will use strings. A bag of strings, then, represents the Hydra. Every time you remove a string from the bag, delete the first letter of the string and put two copies of the remaining string back into the bag. For example, if you remove `HYDRA`, you add two copies of `YDRA` to the bag. If you remove a one-letter word, you add nothing to the bag. To begin, this class should have a run method that reads one word from the keyboard and place it into an empty bag. The Hydra dies when the bag becomes empty.   

- Using Big O notation, predict the time requirement for this algorithm in terms of the number n of characters in the initial string. Then time the actual execution of the program for various values of n and plot its performance as a function of n.   Place this Big O notation in the comments at the top of your Hydra program.


### Setup command
N/A


### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace
`<x>` with the test number.

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