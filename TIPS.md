# Tips

This file is a collection of tips and best-practices that are unrelated to the core specification of the C language, and
instead come from the experience of those using C professionally.

## `strcpy`, `strcat`, `sprintf`, and Safety

`strcpy`, `strcat`, and `sprintf` are considered unsafe because they do not perform bounds checks, which can lead to
intentional or unintentional buffer overflows. But what qualities would we want the functions that replace these three
to have? We would want them to be safe, to work correctly for any input, to make no assumptions about input size, and to
never lose any input. Achieving these goals is not possible with constant-size buffers; dynamic buffers are a necessity.
Unfortunately, in C there are no standardized, portable functions for performing these actions on dynamically-sized
targets. Therefore, this leaves only the following alternatives:
1. Switch to another language in the C family
2. Use the platform-dependent functions available to you and wrap the differences in preprocessor directives to control
which code path is active
3. Make assumptions about the input and use constant-size buffers
4. Write your own specialized functions to read input dynamically
