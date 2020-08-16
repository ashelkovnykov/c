#include <stdio.h>

#include "../headers/compound.h"

/**
 * Compound literals are unnamed objects which refer to a memory location like any named object. They are used in situations when an array, struct, or
 * union object would be needed only once. Like named objects, compound literals are valid l-values.
 */
void printCompound() {
  struct S *ps = &((struct S){123});
  
  printf("Compound literal value: %d\n", ps->member);
}
