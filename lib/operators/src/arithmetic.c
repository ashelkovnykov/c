#include "../headers/arithmetic.h"

void printArithmetic() {
  unsigned char a = 5;
  unsigned char b = 9;
  
  +a;     // Unary addition operator - only exists to promote lower mathematical types to int type
  -a;     // Unary subtraction operator - effective to (a * -1)
  a + b;  // Addition - results in 14
  a - b;  // Subtraction - results in -4
  a * b;  // Multiplication - results in 45
  a / b;  // Division - results in 0 (since they're int values - real value is 0.555)
  a % b;  // Modulo - results in 5
  ~a;     // Bitwise NOT - results in (1111 1010) = 250
  a & b;  // Bitwise AND - results in 1
  a | b;  // Bitwise OR - results in 13
  a ^ b;  // Bitwise XOR - results in 12
  a << 1; // Left shift - results in 10
  a >> 1; // Right shift - results in 2
}
