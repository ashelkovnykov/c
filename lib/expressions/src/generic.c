#include <stdio.h>

#include "../headers/generic.h"

static void pInt(int i) {
  printf("%d", i);
}

static void pFloat(float f) {
  printf("%f", f);
}

/**
 * The _Generic command acts like a switch statement that operates on type instead of value and has no fall-through.
 */
#define genericPrint(X) _Generic((X), int : pInt, float : pFloat)(X)

void printGeneric() {
  int i = 1;
  float f = 2.0F;
  
  // Combine generic command with preprocessor to create syntactic sugar for generic functions
  genericPrint(i);
  genericPrint(f);
  
  // The two lines above are replaced by the two lines in the comment block below
  /*
  _Generic(i, int : pInt, float : pFloat)(i);
  _Generic(f, int : pInt, float : pFloat)(f);
   */
}
