all: code utest

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

# run just the first unit test
test1: utest
	./test -s [test1]

# run just the second unit test
test2: utest
	./test -s [test2]

clean:
	rm *.o test
