# Make

`Make` is a build automation tool that is used to automatically build C and C++ executable programs/libraries from source code. It originated at Bell Labs as a solution to manually building and linking many individual files.

The `make` tool is applicable to any process which involves executing arbitrary commands to transform one or more source files into a target result. Therefore, `make` is not C/C++ specific.

The instructions for `make` are stored in plain-text files known as "makefiles".

Since the commands in a makefile are actually commandline functions, makefiles may not be compatible across systems. This has led to the development of platform-independent languages which generate platform-specific makefiles (e.g. `Autoconf`, `CMake`, `GYP`).

## Behaviour

The `make` tool is available as an OS command line tool. Most OSes have their own versions of the code, though the functionality is very close between versions.

Without arguments, `make` will build the default target from the first makefile it encounters. Each implementation of `make` has its own method to search for makefiles: for example, the GNU version of `make` will search for a file named `GNUmakefile`, `Makefile`, or `makefile`, non-recursively, in file order in the present working directory. If a makefile does not have an explicit default target, the first target is the default target.

`Make` determines which targets need to be recomputed using a combination of topological sorting over dependent targets and comparing file modification timestamps. As a result, modifications that change the file modification timestamp to an older one (e.g. reverting revisions) are not correctly picked up by "make" and require a full rebuild.

## Language

The `make` language is declarative, meaning that the results of commands are guaranteed but the order is not.

There are two types of declarations in the `make` language: rules and macros.

### Rules

Rules are the build instructions of a makefile. They have the following format:
```
target [target ...] : [component ...]
    [command 1]
    ...
    [command n]
```
- "target" is the name of the rule
- "component" is the name of another rule, upon which "target" depends
- Each "command" is a valid command for the shell/commandline interpreter of the OS
- Note that each command is preceded by a tab character, **not 4 spaces**

Targets are generally named after files, and the commands for a target generally generate the target.

Each command is executed by a separate shell/commandline interpreter. Commands can begin with one of three prefixes:
- `-`: ignore errors
- `@`: do not print the command to standard out before executing it
- `+`: execute the command even in "do not execute" mode

If there is only a single command for the rule, the following syntax is also acceptable:
```
target [target ...] : [component ...] ; command
```

#### Pattern Rules

"Pattern rules" are rules that target all files with a particular pattern, usually used for converting all files with a particular file extension. A pattern rule looks like an ordinary rule, except that the target (and possibly the component) uses a special character `%` to denote a file-matching pattern (`%` evaluates to any substring of 0 or more characters).

Pattern rules have access to three predefined macros:
- `$<`: Refers to the component in full. For example, if the rule has syntax `%.o : %.c`, then `$<` refers to `main.c`
- `$@`: Refers to the target in full. For example, if the rule has syntax `%.o : %.c`, then `$@` refers to `main.o`
- `$*`: Refers to the contents of `%`. For example, if the rule has syntax `%.o : %.c`, then `$*` refers to `main`

### Macros

Macros are named sequences of characters used to inject text without repetition. They have the following format:
```
name = definition
```
- "name" is the name of the macro; it can be any unbroken sequence of uppercase characters
- "definition" is the replacement text for the macro: it can be text, other macros, or the results of a shell/commandline interpreter command

Macros can be defined in the commandline arguments to `make` or in the makefile itself. If there is a conflict, the definition in the commandline arguments overwrites the makefile macro definition. Environment variables are available as macros in a makefile.

Default shell scripting macros (e.g. `?`, `@`, etc.) can be accessed by prefixing them with `$`.

Macro definitions are lazy evaluated.

### Comments

The `make` language allows single-line comments. Any text after a `#` symbol and before a newline will be ignored.

### Line Continuation

The `make` language allows component lists and commands to take up multiple lines using the `\ ` "line continuation" symbol. If a line ends with a backslash followed by a newline, `make` will concatenate it and the following line.
