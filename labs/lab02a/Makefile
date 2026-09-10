# =============================================================================
# Reminder of how a rule works (lab02's Makefile explains this in full):
#
#     target: prerequisite1 prerequisite2 ...
#     <TAB>recipe line
#
# Make runs the recipe only if the target FILE is missing or some prerequisite
# is newer than it.  That is why each target below is named after the file its
# recipe actually creates - if the name did not match a real file, make could
# never see it as finished and would rebuild it every time.
#
# Targets that create no file (all, run_poly, clean) are listed as .PHONY at
# the bottom, so make never confuses them with a filename.
#
# DO NOT MODIFY THE TESTS DIRECTORY
# You may ADD targets to this Makefile (for the calendar extra credit),
# but do not change the existing ones.
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

# The default goal: build the Polynomial class, build its unit tests, run them.
all: run_poly

# If you want to test your code outside of the unit tests, create a new .cpp
# file with a main() function and add a rule for it here.

# ---- compiling ---------------------------------------------------------
# -c compiles to an object file without linking, producing poly.o.
# poly.h is a prerequisite as well, so that editing the header rebuilds this.
poly.o: poly.cpp poly.h
	g++ -std=c++11 -Wall -Wextra -c poly.cpp

# ---- linking the test program ------------------------------------------
# -o names the program, so the target has that same name.
test_poly: poly.o poly.h tests/catch.hpp tests/test_poly.cpp
	g++ -std=c++11 -Wall -Wextra -o test_poly poly.o tests/test_poly.cpp

# ---- running the tests -------------------------------------------------
# -s tells Catch2 to show passing tests as well as failures.
run_poly: test_poly
	./test_poly -s

# ---- housekeeping ------------------------------------------------------
# -f means do not complain if the files are not there.
# If you do the calendar extra credit, add its program name here too.
clean:
	rm -f *.o test_poly

.PHONY: all run_poly clean
