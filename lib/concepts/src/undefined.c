#include <stdlib.h>

#include "../headers/undefined.h"

/**
 * The C language standard defines five classes of behaviour:
 *
 * 1. Specified behaviour: The behaviour of the command has a precise behaviour specified by the C standard. Almost all valid C code falls into this
 * category.
 * 2. Unspecified behaviour: Two or more valid behaviours are permitted for a single command/expression and the implementation is not required to
 * document which one occurs under what circumstances. Each behaviour results in one of a set of valid results, but may produce a different result
 * each time.
 * 3. Implementation-specific behaviour: Unspecified behaviour where the implementation explicitly documents how and when one of the behaviours is
 * chosen.
 * 4. Locale-specific behaviour: Implementation-specific behaviour which depends on the locale in which the program is operating.
 * 5. Undefined behaviour: The behaviour of the command/expression has no precise specification, no restrictions, and no requirement to do anything
 * meaningful.
 *
 * All of the code contained within the blocks below results in undefined behaviour.
 */
void undefinedDoNothing() {
  // Signed integer overflow
  /*
  int foo (int x) {
    return (x + 1) > x; // Either true or UB
  }
  foo(2147483647);
   */
  
  // Out of bounds access
  /*
  int array[2] = {0};
  bool positive = array[1] > 0; // Either true or UB
   */
  
  // Uninitialized value access
  /*
  _Bool b1;
  int i1 = b1 ? 1 : -1; // UB
   */
  
  // Invalid value write
  /*
  int i1 = 0;
  double *p1 = &i1;
  *p1 = 2.2; // Reading i1 after this is UB
  return i1;
   */
  
  // Null pointer dereference
  /*
  int *p1 = 0;
  int i1 = *p1; // UB
   */
  
  // Access to pointer passed to realloc
  /*
  int *p1 = malloc(sizeof(int));
  int *p2 = realloc(p1, sizeof(int));
  *p1 = 1; // UB
  */
  
  // Infinite loop without side effects
  /*
  int i1 = 1;
  int i2 = 2;
  // This loop is UB
  while (1) {
    if ((i1 + i2) == 100) {
      return;
    } else {
      ++i1;
      ++i2;
    }
  }
   */
}
