#include <stdio.h>

#include "../headers/replacement.h"

/**
 * The #define preprocessor directive defines text replacement macros. These macros function much like functions: they can take zero or more arguments
 * and may even take a non-specific number of arguments.
 *
 * The #undef preprocessor directive deletes an existing macro definition, thus ending macro text replacement in the successive code.
 */
#define FIVE 5
#define FUNCTION(name, n) int fun_##name(int x) { return (n) * x + FIVE; }
#define SHOW_LIST(...) puts(#__VA_ARGS__)

FUNCTION(quadruple, 4)

#undef FUNCTION
#define FIVE 555 // Redefine macro - old value is discarded

void printReplacement() {
  SHOW_LIST(0, "x", y, int);
  printf("%d", FIVE);
}

#undef SHOW_LIST
#undef FIVE
