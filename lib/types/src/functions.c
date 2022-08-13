#include <stdlib.h>

#include "../headers/functions.h"

// Since function return types are unqualified, the const qualifier does nothing but is necessary to match the function declaration
const int functionOne(int x) {
  return x;
}

const int functionFour(int x) {
  return functionOne(x);
}

// Though the function declaration does not need to name function parameters, function definition does
int functionFive(int x) {
  return functionFour(x);
}

int functionSix(register int x) {
  return functionFive(x);
}

// The difference between these two functions is now visible by their definitions
int functionSeven(void) {
  return 0;
}
int functionEight(int x) {
  return x;
}

// _Noreturn is a special keyword which specifies that the function does not return by calling the return statement or reaching the end of function
// body
_Noreturn void functionNine(char c, int x, ...) {
  exit(x);
}

inline int functionTen(int x) {
  return x + 1;
}
