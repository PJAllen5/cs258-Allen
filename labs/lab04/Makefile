# compile all code and run all unit tests
all: test1 test2 test3 test4

# If you want to test your code outside of the unit
# tests, create a new .cpp file and add a main() function
#
# If you do modify this Makefile, make sure the the all command will compile all code and run all of the unit tests

# compile the palindrome code
palindrome:
	g++ -std=c++11 -c palindrome.cpp

# compile the postfix code
postfix:
	g++ -std=c++11 -c postfix.cpp

# compile the postfix unit test code
test_postfix: postfix
	g++ -std=c++11 -o test_postfix postfix.o tests/test_postFix.cpp

# compile the palindrome unit test code
test_palindrome: palindrome
	g++ -std=c++11 -o test_palindrome palindrome.o tests/test_palindrome.cpp

# compile the peek2 unit test code.  Note we can't compile peek2 directly, it is a virtual class
test_peek2:
	g++ -std=c++11 -o test_peek2 tests/test_peek2.cpp

# compile the arrayStackRS unit test code.  Note we can't compile the class directly, it is a virtual class
test_arrayStackRS:
	g++ -std=c++11 -o test_arrayStack tests/test_arrayStack.cpp


# run just the palindrome unit test
test1: test_palindrome
	./test_palindrome -s 

# run just the postfix unit test
test2: test_postfix
	./test_postfix -s 

# run just the peek2 unit test
test3: test_peek2
	./test_peek2 -s 

# run just the arrayStackRS unit test
test4: test_arrayStackRS
	./test_arrayStack -s 

clean:
	rm *.o test_postfix test_palindrome test_peek2 test_arrayStack
