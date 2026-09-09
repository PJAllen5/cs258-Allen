all: utest

# If you want to test your code outside of the unit
# tests, create a new .cpp file and add a main() function
#

# compile the unit test code
utest: code
	g++ -std=c++11 -o test tests/test.cpp

# run the unit tests.  -s parameter means show passed tests
# and not just the failed tests
test: utest
	./test -s

clean:
	rm test
