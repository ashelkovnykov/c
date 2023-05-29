#include <stdio.h>

#include "../headers/alignment.h"

struct S1 {
  char c1; // Size = 1
  char c2; // Size = 1
}; // Size = 2, Alignment = 1

struct S2 {
  char c1; // Size = 1
  // Padding = 3
  int i1; // Size = 4
}; // Size = 8, Alignment = 4

struct S3 {
  char c1; // Size = 1
  // Padding = 1
  short s1; // Size = 2
  char c2; // Size = 1
  // Padding = 3
  int i1; // Size = 4
  int i2; // Size = 4
  char c3; // Size = 1
  // Padding = 7
  long l1; // Size = 8
}; // Size = 32, Alignment = 8

struct S4 {
  long l1; // Size = 8
  int i1; // Size = 4
  int i2; // Size = 4
  short s1; // Size = 2
  char c1; // Size = 1
  char c2; // Size = 1
  char c3; // Size = 1
  // Padding = 3
}; // Size = 24, Alignment = 8

void printAlignment() {
  printf("S1: Size = %d, Alignment = %d\n", (int)sizeof(struct S1), (int)_Alignof(struct S1));
  printf("S2: Size = %d, Alignment = %d\n", (int)sizeof(struct S2), (int)_Alignof(struct S2));
  printf("S3: Size = %d, Alignment = %d\n", (int)sizeof(struct S3), (int)_Alignof(struct S3));
  printf("S4: Size = %d, Alignment = %d\n", (int)sizeof(struct S4), (int)_Alignof(struct S4));
}
