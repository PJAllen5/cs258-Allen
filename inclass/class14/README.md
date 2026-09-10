# CS258 In-class 14: Queue Implementations
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Modify an array-based implementation of a queue to use a resizable, circular array to represent the items in the
queue.
- This chapter described another array-based implementation of a queue that uses no special data member—such
as count or isFull (see the previous programming problem)—to distinguish between the full and empty conditions. In this implementation, you declare MAX_QUEUE + 1 locations for the array items, but use only MAX_QUEUE
of them for queue items. You sacrifice one array location by making front the index of the location before the
front of the queue. The queue is full if front equals (back + 1) % (MAX_QUEUE + 1), but the queue is empty if
front equals back. Implement this array-based approach.
- Exercise 9 in the previous chapter defined the double-ended queue, or deque. Implement the ADT deque by
using a circular array to contain the items in the deque.
- Implement the ADT deque, as described in Exercise 9 of the previous chapter, as a derived class of ArrayQueue,
as given in Listings 14-4 and 14-5.


### Setup command
N/A

### Run command
`make` builds everything and runs the unit tests.

`make test` runs just the tests.

### Other test commands
Use `make test1` or `make test2` to run a single tagged test.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
