# =============================================================================
# A Makefile is a list of RULES.  Every rule looks like this:
#
#     target: prerequisite1 prerequisite2 ...
#     <TAB>recipe line
#
#   target        the name of the thing this rule makes - normally the exact
#                 name of the FILE the recipe creates
#   prerequisites the things that must be ready before the recipe can run
#   recipe        the shell commands that do the work.  Every recipe line MUST
#                 start with a real TAB character, not spaces.
#
# HOW MAKE DECIDES WHETHER TO DO ANY WORK
#
# For each prerequisite, make asks two questions: is there a rule with that
# name, and is there a file with that name?  If there is a rule, make handles
# that rule first.  Then it compares timestamps.  It runs the recipe only if
# the target file is missing, or if some prerequisite is newer than it.  That
# is why `make` is fast the second time - it skips work that is already done.
#
# This is also why a target should be named after the file it creates.  If the
# name does not match any real file, make can never see it as finished, so it
# runs every single time.
#
# PHONY TARGETS
#
# Some targets do not create a file at all - they just group other rules or run
# a command.  `all`, `run_recursion` and `clean` are like that.  Those are
# called phony targets, and they are listed at the bottom of this file so that
# make never mistakes them for filenames.
#
# WHY THE PREREQUISITES MATTER
#
# If you leave a prerequisite out, make will not notice when that file changes.
# You would edit recursion.cpp, run make, and be told there is nothing to do -
# then wonder why your change had no effect.  If you add files to this project,
# add them to the prerequisite lists too.
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

# The default goal: what you get when you type `make` with no arguments.
# Update this so that it builds and runs ALL of your code and unit tests.
all: run_recursion

# If you want to test your code outside of the unit tests, create a new .cpp
# file with a main() function and add a rule for it here.


# ---- compiling ---------------------------------------------------------
# -c means "compile to an object file, do not link yet".  This creates
# recursion.o, which is why recursion.o is the target name.
recursion.o: recursion.cpp recursion.hpp
	g++ -std=c++11 -Wall -Wextra -c recursion.cpp

# TODO: add a rule to compile your fractions class into fractions.o.
#       It should look almost exactly like the rule above.


# ---- linking the test programs -----------------------------------------
# -o names the program that gets created, so the target is that same name.
# The unit test file is listed as a prerequisite too, so that editing a test
# rebuilds the program.
test_recursion: recursion.o recursion.hpp tests/catch.hpp tests/test.cpp
	g++ -std=c++11 -Wall -Wextra -o test_recursion recursion.o tests/test.cpp

# TODO: add a rule that builds test_fractions from fractions.o and
#       tests/testFrac.cpp.
#
#       This MUST be a separate program from test_recursion.  Both test files
#       begin with #define CATCH_CONFIG_MAIN, so each one contains its own
#       main() and its own copy of Catch2.  Linking them together produces
#       about 1600 lines of "multiple definition" errors.


# ---- running the tests -------------------------------------------------
# These targets create no file, so they run every time - which is what you
# want for something whose whole job is to run a program.
# The -s flag tells Catch2 to show the tests that passed, not just failures.
run_recursion: test_recursion
	./test_recursion -s

# TODO: add a run_fractions target, and add it to `all` above.


# ---- housekeeping ------------------------------------------------------
# -f means "do not complain if these do not exist".  Without it, `make clean`
# fails on a fresh copy where nothing has been built yet.
# Remember to add your own programs here as you create them.
clean:
	rm -f *.o test_recursion test_fractions

.PHONY: all run_recursion run_fractions clean
