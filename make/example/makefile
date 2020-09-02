#
# MACROS
#

# This is a simple macro
PACKAGE = example
# This is a shell command macro
DATE    = `date "+%Y-%m-%d"`
# This is a macro combining macros
NAME    = $(PACKAGE)-$(DATE)
# This is a shell command macro which forces evaluation at definition time and uses the 'shell' command
FILES  = $(shell ls *.c | sed -e 's/\.c/\.o/')

#
# RULES
#

# Best/common practice dictates that the first rule in a makefile be called 'all' and reference each build target as a component
#
# target: all - Default target, builds all other targets
all : $(EXECUTABLE)

# Helpful rule to have, as it lists all other rules and encourages documentation. Note the `@` character at the beginning of the command, meaning that
# the command itself will not be printed.
#
# target: help - Display all targets
help :
	@egrep "^# target:" makefile

# Example rule which uses a macro. Note that the USER macro is not defined in the makefile: it's available as an environment variable
#
# target: hello - "Hello world" rule
hello :
	@echo "Hello, $(USER). Hello, world."

# This version of the 'list' rule doesn't work, because each command runs in a separate shell
#
# target: bad-list - Attempts to list all files in the user home dir, but instead lists all files in the PWD
bad-list :
	cd ~
	ls

# Correct implementation of 'bad-list'
#
# target: good-list - Lists all files in the user home dir
good-list :
	cd ~; \
	ls

# Common command to clean up files produced by the makefile. Any invocation of clean needs to execute, so it needs a way to run regardless of file
# modification date
#
# target: clean - Remove all target files produced by this makefile
clean : FRC
	rm -rf *.o $(NAME)

#
# HIDDEN RULES
#

# These rules are generic rules used to build a C executable. As such, they don't need to be listed by the help command. Note that to work, they
# require the macros CC, CFLAGS, EXECUTABLE, and FILES to be provided from the commandline.

# Suffix rule to convert converting c files to object files. Note the use of the predefined macros
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Execution rule to build an executable from
$(EXECUTABLE) : $(FILES)
	mkdir $(NAME)
	$(CC) $(CFLAGS) $(FILES) -o $(EXECUTABLE)
	mv $(EXECUTABLE) $(NAME)/

# Special pseudo target which always needs to be recomputed. If used as a component to a target, forces a full rebuild of the target every call
FRC :
