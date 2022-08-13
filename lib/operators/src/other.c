#include "../headers/other.h"

void printOther() {
  int a = 1;
  int b = 2;
  
  (a, b);         // Evaluate the first expression, complete its side effects, disregard its return value, then evaluate the second expression
  (double)a;      // Cast object to specified type
  a ? a : b;      // Ternary operator - equivalent to {if (a) a else b}
  sizeof(a);      // Returns size of object
  _Alignof(int);  // Returns alignment of type
}
