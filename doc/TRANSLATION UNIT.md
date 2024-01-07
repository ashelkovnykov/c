# Translation Unit

During translation, C compilers operate on discrete units of data for the first eight phases: these are the translation
units. The final phase of translation links the machine code generated from the units into a single executable.

A translation unit is all the code in a single source file, after pre-processing. Therefore, it is all the code in a
single source file after:
* `#include` directives have imported code;
* `ifdef`/`ifndef` directives have included or excluded code; and
* All macros have been expanded

Clearly, during translation there will be one translation unit per source file.
