# CS258 In-class 10: Algorithm Efficiency and Big O
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
`make` builds everything and runs the unit tests.

`make test` runs just the tests.

Standalone programs: `make code` then `./code`

### Other test commands
Use `make test1` or `make test2` to run a single tagged test.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
