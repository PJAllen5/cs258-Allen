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
# a command.  `all`, `run` and `clean` are like that.  Those are
# called phony targets, and you list them at the bottom of the file so that
# make never mistakes them for filenames.
#
# WHY THE PREREQUISITES MATTER
#
# If you leave a prerequisite out, make will not notice when that file changes.
# You would edit utils.cpp, run make, and be told there is nothing to do -
# then wonder why your change had no effect.  If you add files to this project,
# add them to the prerequisite lists too.
# =============================================================================

# -----------------------------------------------------------------------------
# Your turn.  Write the rules below - type them, do not copy and paste.
#
# This folder contains:
#     main.cpp      uses utils.h, math.h and container.h
#     utils.cpp     with utils.h
#     math.cpp      with math.h
#     container.h   a TEMPLATE class - never compiled on its own, but any
#                   .cpp that includes it must list it as a prerequisite
#
# Build main.o, utils.o and math.o, link them into a program, and add a clean
# target.  Then run `make` twice and watch it skip the work the second time.
# -----------------------------------------------------------------------------

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
