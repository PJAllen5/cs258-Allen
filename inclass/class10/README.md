# CS258 in-class-9: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
Using Big O notation, indicate the time requirement of each of the following tasks in the worst case. Describe any assumptions that you make.
- After arriving at a party, you shake hands with each person there.
- Each person in a room shakes hands with everyone else in the room.
- You climb a flight of stairs.
- You slide down the banister.
- After entering an elevator, you press a button to choose a floor.
- You ride the elevator from the ground floor up to the $n^{th}$ floor.
- You read a book twice.

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
