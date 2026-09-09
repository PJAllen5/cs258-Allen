# compile all unit tests and classses
all: testp

# If you want to test your code outside of the unit
# tests, create a new .cpp file and add a main() function
#
# DO NOT MODIFY THIS MAKEFILE OR THE TESTS DIRECTORY

# compile the polynomial class
poly: poly.cpp
	g++ -std=c++11 -c poly.cpp

# compile the poly unit tests
polytest: poly
	g++ -std=c++11 -o testp poly.o tests/test_poly.cpp

# run just the poly unit test
testp: polytest
	./testp -s

clean:
	rm *.o testp 
