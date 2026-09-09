all: test

# If you want to test your code outside of the unit
# tests, create a new .cpp file and add a main() function
#
# DO NOT MODIFY THIS MAKEFILE OR THE TESTS DIRECTORY

code:
	g++ -std=c++11 -c code.cpp

# compile the unit test code
utest: code
	g++ -std=c++11 -o test code.o tests/test.cpp

# run the unit tests.  -s parameter means show passed tests
# and not just the failed tests
test: utest
	./test -s

# compile the linkedbag unit tests
linkedbag_utest: code
	g++ -std=c++11 -o linkedbag_test code.o tests/linkedbag_tests.cpp

# run the linkedbag unit tests
linkedbag_test: linkedbag_utest
	./linkedbag_test -s

clean:
	rm *.o test linkedbag_test
