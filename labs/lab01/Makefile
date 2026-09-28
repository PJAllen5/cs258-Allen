# links object files into an executable called result
result: main.o hello.o hello2.o
	g++ -o result main.o hello.o hello2.o

# creates objects file main.o from source files
main.o: main.cpp hello.h hello2.h # main.cpp depends on hello.h and hello2.h
	g++ -c main.cpp

# creates objects file hello.o from source files
hello.o: hello.cpp hello.h
	g++ -c hello.cpp

# creates objects file hello2.o from source files
hello2.o: hello2.cpp hello2.h
	g++ -c hello2.cpp

# run the program we just built as ./result
run: result
	./result

# -f (force flag) means "do not complain if these files are not there"
clean: 
	rm -f *.o result # cleans directory by removing .o files and the result executable

.PHONY: run clean # flags run and clean (actions) as non-files, so they are not compliled
