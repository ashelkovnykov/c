#include "../headers/logical.h"

void printLogical() {
  int a = 1;
  int b = 0;
  
  !a;     // Logical NOT - equals 0 (!b would be 1)
  a && b; // Logical AND - equals 0 (a && a would be 1)
  a || b; // Logical OR - equals 1 (b || b would be 0)
}
