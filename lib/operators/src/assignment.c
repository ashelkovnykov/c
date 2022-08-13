#include "../headers/assignment.h"

void printAssignment() {
  int a = 0;
  int b = 1;
  
  a = b;    // a becomes equal to b
  a += b;   // a becomes equal to a plus b
  a -= b;   // a becomes equal to a minus b
  a *= b;   // a becomes equal to the product of a and b
  a /= b;   // a becomes equal to the division of a by b
  a %= b;   // a becomes equal to the remainder of a by b
  a &= b;   // a becomes equal to the bitwise AND of a and b
  a |= b;   // a becomes equal to the bitwise OR of a and b
  a ^= b;   // a becomes equal to the bitwise XOR of a and b
  a <<= b;  // a becomes equal to a bitshift left by b
  a >>= b;  // a becomes equal to a bitshift right by b
}
