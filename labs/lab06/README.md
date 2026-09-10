# CS258 Lab 6: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).  Note, we are using the single header from Catch V2.   

### The assignment
There is no starter code for this lab.  You write the classes, the `Makefile` and the
unit tests yourself.

#### Part 1 - timing three algorithms
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

Put the three algorithms in a class of their own so they can be unit tested, and put the
timing table in a separate program with a `main()`.

<br>

**What to unit test here:** all three algorithms compute the same thing, so for any n
they must return the same answer.  `algoA(10)`, `algoB(10)` and `algoC(10)` must all be
55.  Test several values of n, including `n = 0` and `n = 1`.  That is an exact check,
and it will catch the off-by-one errors that are easy to make in A and B.

Timing is not something a unit test can check, so the timing table belongs in the
`main()` program, not in your tests.

#### Part 2 - the Hydra

- In mythology, the Hydra was a monster with many heads. Every time the hero chopped off a head, two smaller heads would grow in its place. Fortunately for the hero, if the head was small enough, he could chop it off with-out two more growing in its place. To kill the Hydra, all our hero needed to do was to chop off all the heads.

- Write a program that simulates the Hydra. Create a class for this.  Instead of heads, we will use strings. A bag of strings, then, represents the Hydra. Every time you remove a string from the bag, delete the first letter of the string and put two copies of the remaining string back into the bag. For example, if you remove `HYDRA`, you add two copies of `YDRA` to the bag. If you remove a one-letter word, you add nothing to the bag. The Hydra dies when the bag becomes empty.

Use the `LinkedBag` class you wrote in lab 3 to hold the strings.

**Keep the input separate from the logic**, or you will not be able to test this class:

- a method that takes a `std::string` and puts it into an empty bag - this is what your
  unit tests call
- a `run()` method that reads one word from the keyboard and then calls the method above

A method that reads from the keyboard cannot be unit tested, because a test has no
keyboard to type at.  Anything you want to test has to be reachable without input.

- Using Big O notation, predict the time requirement for this algorithm in terms of the number n of characters in the initial string. Then time the actual execution of the program for various values of n and plot its performance as a function of n.   Place this Big O notation in the comments at the top of your Hydra program.

> **Start small and work up.**  Every extra character in the word **doubles** the amount
> of work, so the running time does not creep up, it explodes.  Chopping a 20 letter word
> takes a fraction of a second; a 24 letter word takes several seconds; by the high
> twenties you are waiting minutes, and it only gets worse from there.  Work out the
> number of chops for a word of length n before you choose your test values, and add one
> letter at a time.
>
> If your program seems to have hung, it probably has not - it is doing exactly what you
> asked, and there is a great deal of it to do.  That is the point of the exercise.  Do
> not go hunting for an infinite loop before you have done the arithmetic.


### Setup command
N/A


### The Makefile
There is no Makefile in this folder.  You write it from scratch - you have been reading
and extending them since lab 1, and this is where you write your own.

It must:

- build everything and run all of your unit tests when you type `make` on its own
- have separate commands for the pieces, so I can run just one part, for example
  `make run_algorithms` and `make run_hydra`
- have a `clean` command that removes every object file and executable you create
- name each target after the file its recipe creates, and list the real prerequisites so
  that editing a source file actually causes a rebuild
- declare the targets that do not create a file as `.PHONY`


Compile with `-Wall -Wextra` in every rule, as the provided Makefiles in the earlier
labs do:

```
g++ -std=c++11 -Wall -Wextra -c yourfile.cpp
```

These two flags ask the compiler to report code that is legal but almost certainly
wrong - a function that never returns a value, an unused variable, an `if` whose
indentation lies about what it guards.  They do not change what your program does.  A
warning is not a failed build, but treat one as a bug until you have proved otherwise.

Remember that each test file starting with `#define CATCH_CONFIG_MAIN` contains its own
`main()`, so each one has to become its own executable.

The Catch2 header is provided in `tests/catch.hpp`.  Everything else in this lab is
yours to write.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **If you do modify the Makefile, make sure the the all command will compile all code and run all of the unit tests**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.

### Grading Rubric

| Category | Points |
| -------- | ------ |
| Implementation Correctness | 50 |
| Unit Tests | 30 |
| Code Quality & Documentation | 20 |
| **Total** | **100** |

- **Implementation Correctness (50)** - the algorithms and the Hydra behave correctly, the timing program produces a readable table, and everything compiles.  Code that does not compile receives 0 for this category.
- **Unit Tests (30)** - you write the tests for this lab, so they are worth real credit.  Cover all three algorithms against each other, and the Hydra including a one-letter word and a word that is already gone.  Tests that only exercise the easy path do not earn full marks.
- **Code Quality & Documentation (20)** - readable, consistently formatted code, meaningful names, file headers, docstrings on methods and tests, and the Big O comment at the top of your Hydra program.
