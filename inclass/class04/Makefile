# =============================================================================
# In-class exercise Makefile.
#
# Reminder of how a rule works (lab02's Makefile explains this in full):
#
#     target: prerequisite1 prerequisite2 ...
#     <TAB>recipe line
#
# Make runs the recipe only if the target FILE is missing or a prerequisite is
# newer than it, so each target is named after the file its recipe creates.
# Targets that create no file are listed as .PHONY at the bottom.
#
# Template classes are never compiled on their own - their .cpp is #included by
# their .h, and the code only becomes real when a test asks for a concrete type
# like LinkedBag<int>.  That is why they appear as prerequisites but have no
# rule of their own.
#
# DO NOT MODIFY THE TESTS DIRECTORY
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

all: test

code.o: ArrayBag.cpp ArrayBag.h BagInterface.h code.cpp code.hpp
	g++ -std=c++11 -Wall -Wextra -c code.cpp

# link the unit tests into their own program
test_code: code.o ArrayBag.cpp ArrayBag.h BagInterface.h code.hpp tests/catch.hpp tests/test.cpp
	g++ -std=c++11 -Wall -Wextra -o test_code code.o tests/test.cpp

# -s shows the tests that passed, not just the failures
test: test_code
	./test_code -s

# run just one tagged test
test1: test_code
	./test_code -s [test1]

test2: test_code
	./test_code -s [test2]

# -f means do not complain if the files are not there
clean:
	rm -f code.o test_code

.PHONY: all test test1 test2 clean
