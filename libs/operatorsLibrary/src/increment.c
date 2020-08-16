#include "../headers/increment.h"

void printIncrement() {
  int a = 1;
  
  ++a; // Equivalent to {a = (a + 1); a}
  --a; // Equivalent to {a = (a - 1); a}
  a++; // Equivalent to {i = a; a = (a + 1); i}
  a--; // Equivalent to {i = a; a = (a - 1); i}
}
