# CS258 in-class-10: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Add a counter to the functions insertionSort and mergeSort that counts the number of comparisons that are made. Run the two functions with arrays of various sizes. At what size does the difference in the number of comparisons become signiﬁ cant? How does this size compare with the size that the orders of these algorithms predict?
- Revise the function quickSort so that it always chooses the ﬁ rst item in the array as the pivot. Add a counter to the function partition that counts the number of comparisons that are made. Compare the behavior of the revised function with the original one, using arrays of various sizes. At what size array does the difference in the number of comparisons become signiﬁ cant? For which pivot selection strategy does the difference in the
number of comparisons become significant?
- You can sort a large array of integers that are in the range 1 to 100 by using an array count of 100 items to count the number of occurrences of each integer in the array. Fill in the details of this sorting algorithm, which is called a bucket sort , and write a C++ function that implements it. What is the order of the bucket sort? Why is the bucket sort not useful as a general sorting algorithm?
- Write a program to display the running time of the sorts described in this chapter. Test the sorts on arrays of various sizes. Arrays of the same size should contain identical entries. Use the function clock from <ctime> to time each sort. See the beginning of the programming problems in Chapter 10 for an example of how to time code.

### Setup command
N/A

### Run command
`make ?`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
