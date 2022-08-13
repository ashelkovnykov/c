# C

This project serves the following purposes:
1. Document and demonstrate C language features
2. Document and demonstrate the best C programming practices
3. Document and demonstrate the best C project layout practices

If you see a mistake, please do not hesitate to leave a comment. I did my best to find and organize as much information
regarding professional C development as I could, but I am not a full-time C developer. This project was a stepping-stone
to re-familiarizing myself with C after 6 years of working in Scala.

## Project Directory Layout

Unlike other languages, C doesn't have a standardized project directory layout. The closest thing to "standard" would be
the example 'libabc' library hosted by LWN.net (Linux Weekly News). By applying some common practices from other
languages and browsing various discussions online, I've arrived at the following baseline project structure for a modern
C project:
```text
/                   (project root)
|
|-- bin/            (final executable files)
|
|-- deb/            (makefile dependency files)
|
|-- doc/            (project documentation)
|  |
|  |-- html/        (HTML documentation)
|  |
|  |-- latex/       (Latex documentation)
|
|-- src/            (all sources files, `.c` and `.h`)
|  |
|  |-- test/        (unit testing files)
|
|-- obj/            (generated `.o` files)
|
|-- lib/            (external library dependencies)
|
|-- CHANGELOG.md    (list of changes for each version)
|
|-- Doxyfile        (Doxygen instructions)
|
|-- LICENSE         (license and warranty information)
|
|-- makefile        (make instructions)
|
|-- README.md       (project info: installation instructions, usage instructions, bugs, todos, etc.)
```

Note that this repo itself only loosely follows this project structure, as it is more of a wiki than an actual project.
