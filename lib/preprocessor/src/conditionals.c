#include <stdio.h>

#include "../headers/conditionals.h"

/**
 * The conditional preprocessor directives are:
 * - #if
 * - #ifdef
 * - #ifndef
 * - #elif
 * - #else
 * - #endif
 *
 * A valid conditional preprocessor directive has the following form:
 * 1. One of {'#if [expression]', '#ifdef [identifier]', '#ifndef [identifier]'}
 * 2. Zero or more '#elif [expression]' directives
 * 3. One or no '#else' directives
 * 4. '#endif' directive
 *
 * The expressions used by #if and #elif can be made up only of constants identifiers defined using the #define directive. Any identifier not defined
 * by the #define directive evaluates to 0. In addition, all of the C mathematical and logical operators are available, plus the 'defined' operator
 * which returns 1 if an identifier has been defined using the #define directive and 0 otherwise.
 */
 
#define B
#define TEN 10

void printConditionals() {
  puts("1. ");
#if (2 > 1)
  puts("correct");
#endif
  
  puts("2. ");
#if TEN < 10
  puts("incorrect");
#elif TEN == 10
  puts("correct");
#elif TEN > 10
  puts("incorrect");
#endif
  
  puts("3. ");
#ifndef A
  puts("correct");
#else
  puts("incorrect");
#endif
  
  puts("4: ");
#ifdef B
  puts("correct");
#else
  puts("incorrect");
#endif
}
