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
# NOTE ON THE C++ STANDARD
#
# This folder builds with -std=c++17, not -std=c++11 like the earlier
# sessions.  From here on we use smart pointers (shared_ptr, unique_ptr,
# make_unique) and the return type deduction that goes with them, none of
# which C++11 supports.
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

PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -std=c++17 -Wall -Wextra -c PrecondViolatedExcep.cpp

# link the unit tests into their own program
test_code: PrecondViolatedExcep.o ArrayMaxHeap.cpp ArrayMaxHeap.h HeapInterface.h PrecondViolatedExcep.h tests/catch.hpp tests/test.cpp
	g++ -std=c++17 -Wall -Wextra -o test_code PrecondViolatedExcep.o tests/test.cpp

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
	rm -f PrecondViolatedExcep.o test_code

.PHONY: all test test1 test2 clean
