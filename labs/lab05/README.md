# CS258 Lab 5
For lab 5, you are going to create a new ADT from scratch, with no starter code.    However, we will not do this all at once.  
This lab will be done in steps, each step due a week later.  

Each part of the lab must be in its own **git branch**.   Part A should be in the `main` branch, but Part b should be in branch `partb`, Part C in branch `partc` etc.  

The Makefile must have a separate command for each part.  For example, I should be able to run `make partb`, and it will compile only the files for Part B and run the part B unit tests.   

## Part A
Create an Abstract class to define a Set interface.   A Set is an unordered collection of items, where no duplicate items are allowed.  

Sets should support some basic operations, such as:
- Create an empty set
- Add an element to the set
- Check to see if an item is in a set
- Remove an item from a set
- Return the size of the set
  
Some more complex operations to include:
- Check to see if two sets are equal (overload operator==)
- Set Union: S union T is a set consisting of the elements of S combined with the elements of T. For example, {2,7,3} union {3,1,2} = {2,7,3,1}
- Set Intersection: S intersect T is a set consisting of those elements common to both S and T. For example, {2,7,3} intersect {3,1,2} = {2,3}
- Set Difference: S - T is a set consisting of those elements of S that are not in T. For example, {2,7,3} - {3,1,2} = {7}

No Makefile is required for part A, primarily because you cannot compile a virtual class!

### Create unit tests
You might be thinking, how can we unit test an abstract class?   Well you can't really.   But all of the information provided in the abstract class is enough to write unit tests.  What I would suggest is to have a helper function that returns an instance of the class to test that can be changed later.  Something like this:
```c++
#include "../SetInterface.h"
#include "catch.hpp"

// a helper function that returns a concrete object that
// implements our set Interface
SetInterface<int> returnSetObject(){
  return // update this later when we have a concrete set to test
}

// Test Set 
TEST_CASE( "### Set test 1 ###" ) {
    // SetInterface <int> theSet;  // instead of this, call helper function
    auto theSet = returnSetObject();
```

Note, Catch 2 has the ability to re-use the same tests for different types.   This can greatly simplify your test cases.  See the `Type parametrised test cases` section from the Catch 2 docs:  <https://github.com/catchorg/Catch2/blob/devel/docs/test-cases-and-sections.md>   You can do this instead of the helperfunction `returnSetObject()`.    

Unit tests must have docstrings explaining what they are testing.

## Part B
Create an array based implementation of the Set.  Note you must use the C style array, not the array library for C++ and not the Vector library.  Failure to do this will result in a zero on this part of the assignment.  This implementation should not have a limit to the size of the Set.

Be sure to include unit tests for this implementation (re-use from part A).

This should be in a subfolder.

Create a Makefile that compiles this code and the unit tests and runs the unit tests.   There should be separate Make commands to compile the source code, the unit test and a Make command to run the unit tests for this array based implementation.

In the header file for this implementation, in the doc strings for each method, state the Big O effeciency of each method.

## Part C
Create a link (node) based implementation of the Set.  You must use the Node class from previous in class/homeworks.  I don't want to see any structs.  ailure to do this will result in a zero on this part of the assignment.

Be sure to include unit tests for this implementation (re-use from part A).

This should be in a subfolder.

Update the Makefile to compiles this code and the unit tests and runs the unit tests for this link based implementation.  There should be separate Make commands for each and a Make command that compiles all versions and runs all unit tests.

In the header file for this implementation, in the doc strings for each method, state the Big O effeciency of this method.

## Part D
Instead of creating an implementation from scratch, instead let's re-use code we already have from this class.  

Create an implementation that uses one of the ADTs from this course (List, Queue, Stack, Bag, Tree, etc).  You can use inheritance or simply have an instance variable of this type.

Be sure to include unit tests for this implementation (re-use from part A). This should be in a subfolder.

In the subfolder for part D, include a README.md that explains your design choice and discuss the effeciencly in Big O terms of the various operations of all three of the implementations.

Update the Makefile to compiles this code and the unit tests and runs the unit tests.   There should be separate Make commands for each and a Make command that compiles all versions and runs all unit tests.

