# CS258 In-class 1: Compiling C++ Files in Linux

## Prerequisites

Most Linux distributions come with a C++ compiler pre-installed. The most common is `g++` (GNU C++ Compiler). To check if it's installed:

```bash
g++ --version
```

If not installed, you can install it using your package manager:
- Ubuntu/Debian: `sudo apt install g++`
- CentOS/RHEL: `sudo yum install gcc-c++`
- Fedora: `sudo dnf install gcc-c++`

## Basic Compilation

### Single File
For a simple program in one file (e.g., `hello.cpp`):

```bash
g++ hello.cpp -o hello
```

This creates an executable named `hello`. Run it with:
```bash
./hello
```

### Without Specifying Output Name
If you don't use `-o`, the default output is `a.out`:

```bash
g++ hello.cpp
./a.out
```

## Multiple Files

When your program spans multiple files:

```bash
g++ main.cpp utils.cpp math.cpp -o myprogram
```

## Template Classes
Template classes require special handling since they are defined in header files:

### Template Structure
Templates are typically organized like this:
- container.h - contains the complete template class definition
- main.cpp - uses the template class

### Example Template Files
#### container.h:
```c++
#ifndef CONTAINER_H
#define CONTAINER_H

template<typename T>
class Container {
private:
    T items[10];
    int count;
public:
    Container() : count(0) {}
    
    void add(T item) {
        if (count < 10) {
            items[count++] = item;
        }
    }
    
    T get(int index) {
        return items[index];
    }
    
    int size() { return count; }
};

#endif
```
#### main.cpp
```c++
#include <iostream>
#include "container.h"

int main() {
    Container<int> numbers;
    numbers.add(42);
    std::cout << numbers.get(0) << std::endl;
    return 0;
}
```

### Compiling Templates
Since templates are in headers, you only compile the source files that use them, you never compile a template class directly:

```bash
g++ main.cpp -o myprogram
```

**Important**: Template classes are compiled when they're instantiated (used), not when they're defined. The compiler generates the actual class code only for the types you use.

## Compiling to Object Files

### Using the -c Option
The `-c` option compiles source files to object files (`.o`) without linking:

```bash
g++ -c utils.cpp
g++ -c math.cpp
g++ -c main.cpp
```

This creates `utils.o`, `math.o`, and `main.o` object files.

### Combining Object Files with Main
After creating object files, you can link them together to create the final executable:

```bash
g++ main.o utils.o math.o -o myprogram
```

### Complete Workflow Example
Here's a typical workflow using object files:

```bash
# Compile each source file to object file
g++ -c main.cpp     # creates main.o
g++ -c utils.cpp    # creates utils.o
g++ -c math.cpp     # creates math.o

# Link all object files to create executable
g++ main.o utils.o math.o -o myprogram
```

This approach is useful for larger projects where you only need to recompile changed files rather than the entire program.


# Linux Makefile Basics

## What is a Makefile?

A Makefile is a configuration file that tells the `make` utility how to build your project. It defines rules for compiling source files, linking object files, and managing dependencies automatically.

## Basic Makefile Structure

A Makefile consists of rules that follow this format:

```makefile
target: dependencies
	command
```

- **target**: The file you want to create (or a task name)
- **dependencies**: Files that the target depends on
- **command**: The shell command to create the target (must be indented with a TAB, not spaces)

## Example Makefile

Here's a Makefile for our example project with `main.cpp`, `utils.cpp`, and `math.cpp`:

```makefile
# Main target - builds the executable
myprogram: main.o utils.o math.o
	g++ main.o utils.o math.o -o myprogram

# Object file rules
main.o: main.cpp utils.h math.h
	g++ -c main.cpp

utils.o: utils.cpp utils.h
	g++ -c utils.cpp

math.o: math.cpp math.h
	g++ -c math.cpp

# Clean target
clean:
	rm -f main.o utils.o math.o myprogram
```

## Template Classes in Makefiles

Template classes require special consideration since they're defined in header files:

### Template Project Structure
```
project/
├── main.cpp
├── container.h        # Template class definition
├── shape.cpp
├── shape.h
└── Makefile
```

### Makefile for Templates
```makefile
# Main target
myprogram: main.o shape.o
	g++ main.o shape.o -o myprogram

# Object files depend on headers too
main.o: main.cpp container.h shape.h
	g++ -c main.cpp

shape.o: shape.cpp shape.h
	g++ -c shape.cpp

# Clean target
clean:
	rm -f main.o shape.o myprogram
```

### Key Points for Templates

1. **Header dependencies**: Any .cpp file that uses a template must list the template header as a dependency
2. **No template compilation**: Template .h files don't get compiled directly
3. **Automatic instantiation**: Templates are compiled when used in .cpp files

### Example with Template Dependencies
```makefile
# If main.cpp uses Container<int> and Container<string>
main.o: main.cpp container.h shape.h string_utils.h
	g++ -c main.cpp

# If another file uses the same template
math_operations.o: math_operations.cpp container.h
	g++ -c math_operations.cpp
```

## Understanding Rules and Dependencies

### Rule Breakdown

1. **Main executable rule**:
   ```makefile
   myprogram: main.o utils.o math.o
   	g++ main.o utils.o math.o -o myprogram
   ```
   - Target: `myprogram`
   - Dependencies: `main.o utils.o math.o`
   - Command: Links all object files into the executable

2. **Object file rules**:
   ```makefile
   main.o: main.cpp utils.h math.h
   	g++ -c main.cpp
   ```
   - Target: `main.o`
   - Dependencies: `main.cpp`, `utils.h`, `math.h`
   - Command: Compiles `main.cpp` to `main.o`

### How Dependencies Work

When you run `make`, it:

1. **Checks timestamps**: If a dependency is newer than the target, the target needs rebuilding
2. **Builds dependencies first**: If `main.o` doesn't exist, make will build it before building `myprogram`
3. **Skips unchanged files**: If `utils.cpp` hasn't changed, `utils.o` won't be rebuilt

### Template Dependencies

For templates, dependencies work differently:

- **Header changes**: If `container.h` changes, all .cpp files that include it must be recompiled
- **Template instantiation**: Changing how you use a template (like `Container<int>` to `Container<double>`) requires recompilation
- **No template objects**: Template headers never create .o files themselves

### Example Build Process

```bash
$ make
g++ -c main.cpp
g++ -c utils.cpp
g++ -c math.cpp
g++ main.o utils.o math.o -o myprogram
```

If you only change `main.cpp` and run `make` again:

```bash
$ make
g++ -c main.cpp
g++ main.o utils.o math.o -o myprogram
```

### Template Build Example

For a project with templates:

```bash
$ make
g++ -c main.cpp      # Compiles main.cpp and instantiates templates
g++ -c shape.cpp     # Compiles regular class
g++ main.o shape.o -o myprogram
```

If you change `container.h`:

```bash
$ make
g++ -c main.cpp      # Recompiles because container.h changed
g++ main.o shape.o -o myprogram
```

Only `main.cpp` gets recompiled because `utils.o` and `math.o` are up to date.

## Using the Makefile

### Basic Commands

```bash
make           # Builds the default target (first one listed)
make clean     # Removes object files and executable
make myprogram # Builds specific target
```

## Simplified Version

For smaller projects, you can use a more compact Makefile:

```makefile
myprogram: main.cpp utils.cpp math.cpp
	g++ main.cpp utils.cpp math.cpp -o myprogram

clean:
	rm -f myprogram
```

### Simplified Template Version

For simple template projects:

```makefile
myprogram: main.cpp shape.cpp container.h
	g++ main.cpp shape.cpp -o myprogram

clean:
	rm -f myprogram
```

This compiles all source files directly into the executable without creating separate object files. Note that `container.h` is listed as a dependency even though it's not compiled directly.

## Key Benefits

- **Incremental builds**: Only recompiles changed files
- **Dependency management**: Automatically handles file relationships, including template headers
- **Automation**: One command builds entire project
- **Consistency**: Same build process every time
- **Template efficiency**: Rebuilds only when template definitions or usage changes

This covers the fundamentals of Makefiles, including how to handle template classes. Start with a simple version and add complexity as your projects grow.


## The assignment
Create a makefile (don't copy and paste, but type it).   Run the make commands to compile this code.  
