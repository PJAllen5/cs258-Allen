all: rec utest test
# update the all command so that it compiles and runs all of
#  your code and unit tests

# If you want to test your code outside of the unit
# tests, create a new .cpp file and add a main() function


rec:
	g++ -std=c++11 -c recursion.cpp

# add a line to compile your fractions class

# compile the unit test code
utest: rec
	g++ -std=c++11 -o test recursion.o tests/test.cpp

# add a line to compile your fractions class unit tests

# run the unit tests.  -s parameter means show passed tests
# and not just the failed tests
test: utest
	./test -s

# add commands to run your polynomial class and fractions class unit tests

# update the clean command to remove all object files and executables
clean:
	rm *.o test 
