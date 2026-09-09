# all compiles all the unit tests and runs them
all: run_linked_bag run_doubleNode

# If you want to test your code outside of the unit
# tests, create a new .cpp file and add a main() function
#

# note, we don't compile any of our classes directly.   They are all 
# template classes (generic), thus to compile, we need to create a concreate 
# instance with a type and compile that file.   We do this in the unit tests

# compile the unit tests for the LinkedBag class
test_linked_bag: tests/test_lb.cpp
	g++ -std=c++11 -o test_linked_bag tests/test_lb.cpp

# run the unit tests for the LinkedBag class
run_linked_bag: test_linked_bag
	./test_linked_bag

# compile the unit tests for the DoubleNode class
test_doubleNode: 
	g++ -std=c++11 -o test_doubleNode tests/test_doubleNode.cpp

# run the unit tests for the DoubleNode class
run_doubleNode: test_doubleNode
	./test_doubleNode


clean:
	rm -f test_linked_bag test_doubleNode
