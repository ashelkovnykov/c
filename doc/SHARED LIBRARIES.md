# Shared Libraries

Projects and developers naturally attempt to reuse quality code whenever possible, instead of rewriting their own from
scratch. The way this is done in `C` is using "shared libraries". Each operating function handles shared libraries
differently.

## Linux

Shared libraries are implemented in linux using either "archive" `.a` files, or "shared object" `.o` files. Both types
of shared library follow the convention that the file name must start with "lib", followed by the library name, and then
the file suffix (e.g. "libc.so", "libpaint.a", etc.).

Users can import shared libraries into their project by including the header file for the library into their source
files, and linking the library at compile time. In GCC, this is done using the `-l` flag (e.g. `-lpaint` will attempt to
link "libpaint.so" or "libpaint.a").

### Archive Files

Archive (`.a`) files are typically included with a project's source code. They typically live in `./lib/`, under the
project root. They are the output of the Linux `ar` utility.

### Shared Object Files

Shared object files (`.so`) are typically distributed as a product or development dependency to be "installed". In
addition to the aforementioned file name conventions, `.so` files also typically include an additional suffix to denote
the version (e.g. `libc.so.6`).

Typically, Linux stores "installed" shared object files in one of the following locations:
- `/usr/lib`
- `/usr/lib64`
- `/usr/local/lib`
- `/usr/local/lib64`

## MacOS

TODO

## Windows

TODO
