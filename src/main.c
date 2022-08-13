#include <assert.h>       // The 'assert' macro which aborts the program if an expression does not evaluate to 'true' = 1
#include <complex.h>      // Functions for complex number arithmetic
#include <ctype.h>        // Functions for determining the type of character contained in a char object
#include <errno.h>        // Macros for reporting POSIX style error messages via numbered constants
#include <fenv.h>         // Macros and functions used to control the floating point environment of the compiler
#include <float.h>        // Macros containing various useful constants for floating point numbers
#include <inttypes.h>     // Format macros for integers for the fprintf family of functions
#include <iso646.h>       // Trigraphs and alternative macros for logical/bitwise operators
#include <limits.h>       // Macros containing various useful constants for integers
#include <locale.h>       // Macros and functions used to control the locale environment (e.g. UK, DE, CA, FR, etc.)
#include <math.h>         // Functions for common arithmetic
#include <setjmp.h>       // Utility functions for controlling program execution through non-local jumps
#include <signal.h>       // Utility functions for sending/receiving signals
#include <stdalign.h>     // Convenience macros for _Alignas and _Alignof
#include <stdarg.h>       // Functions for managing variadic input to functions
#include <stdatomic.h>    // Macros, functions, and types for dealing with atomic objects
#include <stdbool.h>      // Convenience macros for _Bool
#include <stddef.h>       //
#include <stdint.h>       // Macros and types for fixed-width integers
#include <stdio.h>        // Macros, functions, and types for I/O
#include <stdlib.h>       // Convenience functions for dynamic memory allocation, program termination, resource clean-up, random numbers, and strings
#include <stdnoreturn.h>  // Convenience macros for _Noreturn
#include <string.h>       // Functions for string inspection and manipulation
#include <tgmath.h>       // Generic macros which wrap around mathematical functions for real and complex floating point math
#include <threads.h>      // Functions for multi-threading
#include <time.h>         // Functions for time and date calculations
#include <uchar.h>        // Functions for UTF-16 and UTF-32 characters
#include <wchar.h>        // Functions for multi-byte and wide characters
#include <wctype.h>       // Functions for determining the type of character contained in a wchar object

#include "../libs/concepts/concepts.h"
#include "../libs/expressions/expressions.h"
#include "../libs/operators/operators.h"
#include "../libs/preprocessor/preprocessor.h"
#include "../libs/statements/statements.h"
#include "../libs/types/types.h"

int main(int argc, char *argv[]) {
  
  for (int i = 1; i < argc; ++i) {
    printf("Command line argument #%d: %s\n", i, argv[i]);
  }
  
  return 0;
}
