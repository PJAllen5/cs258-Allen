# CS258 In-class 16: Binary Search Trees
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Design another algorithm to remove items from a binary search tree. This algorithm differs from the one
described in this chapter when a node N has two children. First let N's right child take the place of the deleted
node N in the same manner in which you delete a node with one child. Next reconnect N's left child (along with
its subtree, if any) to the left side of the node containing the inorder successor of the value in N.
- A level-order traversal of a tree processes (visits) nodes one level at a time, from left to right, beginning with
the root. Design an algorithm that performs a level-order traversal of a binary tree.   HINT:  Use an ADT that we learned about recently
- If you know in advance that you often access a given item in a binary search tree several times in succession
before accessing a different item, you will end up searching for the same item repeatedly. One way to avoid this
problem is to add an extra bookkeeping component to your implementation. That is, you can maintain a last-
accessed pointer that will always reference the last item that any binary search tree operation accessed. When-
ever you perform such an operation, you can check the search key of the item most recently accessed before
performing the operation.
Revise the implementation of the ADT binary search tree to add this new feature by adding the data mem-
ber lastAccessed to the class.


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
