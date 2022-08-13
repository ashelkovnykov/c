#include "../headers/comparison.h"

void printComparison() {
  int a = 1;
  int b = 2;
  
  a == b; // Equality comparison - equals false (0)
  a != b; // Inequality comparison - equals true (1)
  a < b;  // Less than comparison - equals true (1)
  a > b;  // Greater than comparison - equals false (0)
  a <= a; // Less than or equal to comparison - equals true (1)
  a >= a; // Greater than or equal to comparison - equals true (1)
}
