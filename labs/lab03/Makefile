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
# NOTE ON THE LONG PREREQUISITE LISTS
#
# These classes are templates, so there are no .o files here at all - the whole
# implementation lives in the headers, and the .cpp files are #included by them
# (look at the bottom of Node.h).  Everything is compiled in one step, straight
# from the test file.  That means the test program depends on every header and
# .cpp it pulls in, which is why they are all listed.  If they were not, you
# could edit LinkedBag.cpp, run make, be told there was nothing to do, and
# spend an hour wondering why your change did nothing.
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

# The default goal: build both test programs and run them.
all: run_linked_bag run_doubleNode

# If you want to test your code outside of the unit tests, create a new .cpp
# file with a main() function and add a rule for it here.

# note, we don't compile any of our classes directly.   They are all
# template classes (generic), thus to compile, we need to create a concreate
# instance with a type and compile that file.   We do this in the unit tests

# ---- build the LinkedBag test program ----------------------------------
test_linked_bag: BagInterface.h LinkedBag.cpp LinkedBag.h Node.cpp Node.h tests/catch.hpp tests/test_lb.cpp
	g++ -std=c++11 -Wall -Wextra -o test_linked_bag tests/test_lb.cpp

# ---- run it ------------------------------------------------------------
run_linked_bag: test_linked_bag
	./test_linked_bag

# ---- build the DoubleLinkNode test program -----------------------------
test_doubleNode: DoubleLinkNode.cpp DoubleLinkNode.h tests/catch.hpp tests/test_doubleNode.cpp
	g++ -std=c++11 -Wall -Wextra -o test_doubleNode tests/test_doubleNode.cpp

# ---- run it ------------------------------------------------------------
run_doubleNode: test_doubleNode
	./test_doubleNode

# ---- housekeeping ------------------------------------------------------
# -f means do not complain if the files are not there.
clean:
	rm -f test_linked_bag test_doubleNode

.PHONY: all run_linked_bag run_doubleNode clean
