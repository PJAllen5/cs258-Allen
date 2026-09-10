# CS258 Lab 5
For lab 5, you are going to create a new ADT from scratch, with no starter code.    However, we will not do this all at once.  
This lab will be done in steps, each step due a week later.  

Each part goes in its own **subfolder**, and they all share the one interface you write
in Part A:

```
labs/lab05/
    SetInterface.h      part A - the interface every implementation uses
    Makefile
    partb/              part B - the array based set, and its tests
    partc/              part C - the node based set, and its tests
    partd/              part D - the reuse-an-ADT set, its tests, and its README.md
```

The Makefile must have a separate command for each part.  For example, I should be able to run `make partb`, and it will compile only the files for Part B and run the part B unit tests.   

## Part A
Create an Abstract class to define a Set interface.   A Set is an unordered collection of items, where no duplicate items are allowed.  

### The operations

Your interface must declare exactly these methods.  Every implementation in Parts B, C
and D implements this same interface, and your unit tests are written against it, so the
names and signatures matter.

| Method | What it does |
| ------ | ------------ |
| `bool add(const ItemType& item)` | Add an item.  Returns `false` if it was already there. |
| `bool remove(const ItemType& item)` | Remove an item.  Returns `false` if it was not there. |
| `bool contains(const ItemType& item) const` | Is this item in the set? |
| `int size() const` | How many items are in the set. |
| `bool isEmpty() const` | Is the set empty. |
| `void clear()` | Remove everything. |
| `std::vector<ItemType> toVector() const` | Return the items as a vector, in any order. |
| `bool operator==(const SetInterface<ItemType>& other) const` | Are these two sets equal? |
| `void unionWith(const SetInterface<ItemType>& other)` | This set becomes S ∪ T. |
| `void intersectWith(const SetInterface<ItemType>& other)` | This set becomes S ∩ T. |
| `void differenceWith(const SetInterface<ItemType>& other)` | This set becomes S − T. |

### The set operations modify the set they are called on

`unionWith`, `intersectWith` and `differenceWith` **change the set you call them on**.
They do not return a new set.  If `s` is `{2,7,3}` and `t` is `{3,1,2}`, then after
`s.unionWith(t)`, `s` is `{2,7,3,1}` and `t` is unchanged.

- **Union**: S ∪ T is a set consisting of the elements of S combined with the elements of T. `{2,7,3}` union `{3,1,2}` = `{2,7,3,1}`
- **Intersection**: S ∩ T is a set consisting of those elements common to both S and T. `{2,7,3}` intersect `{3,1,2}` = `{2,3}`
- **Difference**: S − T is a set consisting of those elements of S that are not in T. `{2,7,3}` − `{3,1,2}` = `{7}`

<br>

Because these operations destroy the set they are called on, you will need a **copy
constructor** if you want to keep the original.  For example, to work out S ∪ T without
losing S:

```c++
ArraySet<int> result = s;   // copy constructor
result.unionWith(t);        // s is untouched
```

Your classes manage their own memory with `new` and `delete`, so the copy constructor the
compiler writes for you is not good enough - it would copy the pointer instead of the
data, and two sets would end up sharing one array and both trying to free it.  You must
write your own **copy constructor, assignment operator and destructor**.  This is the
Rule of Three.

### Why the interface needs `toVector`

`unionWith` has to look at every element of the *other* set.  `contains` can only answer
questions about items you already have, so it cannot help you here - there is no way to
ask "what is in you?" without a method that hands the items back.  `toVector` is that
method, and it lets you write union against the interface:

```c++
for (const ItemType& item : other.toVector()) {
    this->add(item);        // add() already rejects duplicates
}
```

<br>

Do **not** use `dynamic_cast` to turn `other` into your own concrete class.  That would
mean your set can only be unioned with sets of the same implementation, which defeats the
purpose of having an interface at all.  You have already used a `toVector` method on the
`LinkedBag` in lab 3.

### Equality does not depend on order

A set is unordered, so `{2,7,3}` and `{3,2,7}` are the **same set** and must compare
equal.  Do not compare positions.  Two sets are equal when they are the same size and
every element of one is contained in the other.

Note this means `operator==` can be written using only the interface - `size()` and
`contains()` - which is exactly how it should be written.

### Create unit tests
You might be thinking, how can we unit test an abstract class?   Well you can't really.   But all of the information provided in the abstract class is enough to write unit tests.  What I would suggest is to have a helper function that returns an instance of the class to test that can be changed later.  

Note that the helper must return a **pointer**, not an object.  An abstract class cannot
be created or returned by value - the compiler will tell you `invalid abstract return
type` if you try.

```c++
#include "../SetInterface.h"
#include "catch.hpp"

// A helper that hands back a concrete object implementing our Set interface.
// In part A there is nothing concrete to return yet, so this will not compile
// until part B.  Update it then.
SetInterface<int>* makeSet(){
  return nullptr;   // part B: return new ArraySet<int>();
}

// Test Set
TEST_CASE( "### Set test 1 ###" ) {
    SetInterface<int>* theSet = makeSet();
    theSet->add(4);
    REQUIRE( theSet->contains(4) );
    delete theSet;
}
```

Writing your tests this way means the **same tests** work for Part B, Part C and Part D -
you only change what `makeSet()` returns.  Re-use them, do not write them three times.

Note, Catch 2 has the ability to re-use the same tests for different types.   This can greatly simplify your test cases.  See the `Type parametrised test cases` section from the Catch 2 docs:  <https://github.com/catchorg/Catch2/blob/devel/docs/test-cases-and-sections.md>   You can do this instead of the helper function `makeSet()`.    

Unit tests must have docstrings explaining what they are testing.

The Catch2 header is provided for you in `tests/catch.hpp` - copy it next to whichever
tests you are writing, or point your compiler at it with `-I`.  Everything else in this

Compile with `-Wall -Wextra` in every rule, as the provided Makefiles in the earlier
labs do:

```
g++ -std=c++11 -Wall -Wextra -c yourfile.cpp
```

These two flags ask the compiler to report code that is legal but almost certainly
wrong - a function that never returns a value, an unused variable, an `if` whose
indentation lies about what it guards.  They do not change what your program does.  A
warning is not a failed build, but treat one as a bug until you have proved otherwise.

lab is yours to write, including the Makefile.

No Makefile is required for part A.   There is nothing to run yet - an abstract class
cannot be created on its own, so there is no object to test until part B.

## Part B
Create an array based implementation of the Set.  Note you must use the C style array, not the array library for C++ and not the Vector library.  Failure to do this will result in a zero on this part of the assignment.  This implementation should not have a limit to the size of the Set.

Call this class `ArraySet`.

Be sure to include unit tests for this implementation (re-use from part A).

This should be in a subfolder.

Create a Makefile that compiles this code and the unit tests and runs the unit tests.   There should be separate Make commands to compile the source code, the unit test and a Make command to run the unit tests for this array based implementation.

In the header file for this implementation, in the doc strings for each method, state the Big O effeciency of each method.

<br>

Note the one place `std::vector` is allowed: `toVector` returns one, because that is its
whole job.  Your set must not *store* its items in a vector.

## Part C
Create a link (node) based implementation of the Set.  You must use the Node class from previous in class/homeworks.  I don't want to see any structs.  Failure to do this will result in a zero on this part of the assignment.

Call this class `LinkedSet`.

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

## Requirements that apply to every part

- Parts B, C and D each in their own subfolder, as shown at the top of this page.
- Declarations in a `.h` file, implementations in a `.cpp` file.  Do not put the whole class in the header.
- A separate `make` command for each part, plus one that builds and runs everything.
- Big O efficiency stated in the docstring of every method in your header files.
- Copy constructor, assignment operator and destructor on any class that allocates memory.
- Every unit test has a docstring saying what it tests.

## Grading Rubric

| Category | Points |
| -------- | ------ |
| Implementation Correctness | 50 |
| Unit Tests | 30 |
| Code Quality & Documentation | 20 |
| **Total** | **100** |

- **Implementation Correctness (50)** - the set behaves correctly, including duplicates, empty sets, and the three set operations.  Code must compile.  Code that does not compile receives 0 for this category.
- **Unit Tests (30)** - you write the tests for this lab, so they are worth real credit.  Tests should cover every method, including the empty set, the one element set, duplicates, and sets that do not overlap.  Tests that only exercise the easy path do not earn full marks.
- **Code Quality & Documentation (20)** - readable, consistently formatted code, meaningful names, file headers, docstrings on methods and tests, and the Big O documentation.

### Deductions

These apply on top of the categories above:

| Issue | Deduction |
| ----- | --------- |
| Missing copy constructor / assignment operator / destructor where memory is allocated | −4 |
| Class not split into `.h` and `.cpp` files | −5 |
| Missing a required `make` command | −3 |
| Big O documentation missing from the docstrings | −10 |
| Using `dynamic_cast` to reach another set's internals | −5 |
