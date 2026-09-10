# =============================================================================
# Reminder of how a rule works (lab02's Makefile explains this in full):
#
#     target: prerequisite1 prerequisite2 ...
#     <TAB>recipe line
#
# Make runs the recipe only if the target FILE is missing or some prerequisite
# is newer than it.  Each target below is named after the file its recipe
# creates, so make can tell when the work is already done.
#
# THIS LAB BUILDS FOUR SEPARATE PROGRAMS
#
# Each of the four test files starts with #define CATCH_CONFIG_MAIN, so each
# one contains its own main() and its own copy of Catch2.  They cannot be
# linked together - that would be four main() functions in one program.  So
# there are four executables, each built and run on its own.
#
# Two different styles appear below, and it is worth noticing why:
#
#   palindrome and postfix are ordinary classes, so they are compiled to .o
#   files first and then linked into a test program.
#
#   ArrayStackRS and StackPeek2 are TEMPLATES.  A template cannot be compiled
#   on its own - it only becomes real code once something asks for a specific
#   type, like ArrayStackRS<int>.  That happens in the test file, so those two
#   are compiled in a single step straight from the test, with every header
#   they depend on listed as a prerequisite.
#
# Targets that create no file (all, run_*, clean) are marked .PHONY at the end.
# =============================================================================

# WHY -Wall -Wextra
#
# By default the compiler only complains about code it cannot compile at all.
# Code that is legal but almost certainly wrong compiles in silence.  These two
# flags ask g++ to tell you what it already knows:
#
#   -Wall     the warnings everyone agrees are worth having - a non-void
#             function that never returns a value, an unused variable, an if
#             whose indentation lies about what it guards, and so on.
#   -Wextra   a further useful set - comparing signed to unsigned, an unused
#             parameter, a member the constructor forgot to initialise.
#
# Neither flag changes what your program does.  They change how much you are
# told before you find out the hard way.  A warning is not a failed build, but
# treat one as a bug until you have proved otherwise - a "no return statement"
# warning means your function returns garbage, which is exactly the kind of
# fault that is miserable to track down later.
#

# The default goal: build everything and run all four test programs.
all: run_palindrome run_postfix run_peek2 run_arrayStack

# If you want to test your code outside of the unit tests, create a new .cpp
# file with a main() function and add a rule for it here.
# If you do modify this Makefile, make sure `all` still compiles all of your
# code and runs all of the unit tests.

# ---- part 1: palindrome ------------------------------------------------
# -c compiles to an object file without linking, producing palindrome.o.
palindrome.o: palindrome.cpp palindrome.h
	g++ -std=c++11 -Wall -Wextra -c palindrome.cpp

# -o names the program, so the target has that same name.
test_palindrome: palindrome.o palindrome.h tests/catch.hpp tests/test_palindrome.cpp
	g++ -std=c++11 -Wall -Wextra -o test_palindrome palindrome.o tests/test_palindrome.cpp

# -s tells Catch2 to show passing tests as well as failures.
run_palindrome: test_palindrome
	./test_palindrome -s

# ---- part 1: postfix calculator ----------------------------------------
postfix.o: postfix.cpp postfix.h
	g++ -std=c++11 -Wall -Wextra -c postfix.cpp

test_postfix: postfix.o postfix.h tests/catch.hpp tests/test_postFix.cpp
	g++ -std=c++11 -Wall -Wextra -o test_postfix postfix.o tests/test_postFix.cpp

run_postfix: test_postfix
	./test_postfix -s

# ---- part 2: StackPeek2 (a template - no .o step) ----------------------
test_peek2: LinkedStack.cpp LinkedStack.h Node.cpp Node.h StackInterface.h StackPeek2.h tests/catch.hpp tests/test_peek2.cpp
	g++ -std=c++11 -Wall -Wextra -o test_peek2 tests/test_peek2.cpp

run_peek2: test_peek2
	./test_peek2 -s

# ---- part 2: ArrayStackRS (a template - no .o step) --------------------
test_arrayStack: ArrayStack.cpp ArrayStack.h ArrayStackRS.h StackInterface.h tests/catch.hpp tests/test_arrayStack.cpp
	g++ -std=c++11 -Wall -Wextra -o test_arrayStack tests/test_arrayStack.cpp

run_arrayStack: test_arrayStack
	./test_arrayStack -s

# ---- housekeeping ------------------------------------------------------
# -f means do not complain if the files are not there.
clean:
	rm -f *.o test_postfix test_palindrome test_peek2 test_arrayStack

.PHONY: all run_palindrome run_postfix run_peek2 run_arrayStack clean
