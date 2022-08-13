#ifndef TYPES_ARRAY_H
#define TYPES_ARRAY_H

/**
 * An array is a block of contiguously allocated memory storing one or more objects of the same type in sequence.
 */
struct arrays {
  int a1[3]; // Array of 3 integers
  int *a2[3]; // Array of 3 pointers to integers
  const int *a3[3]; // Array of 3 pointers to constant integers
  int * const a4[3]; // Array of 3 constant pointers to integers
  int a5[2][5]; // Multi-dimensional array: size is 10 contiguous integers
};

void exampleArrayFunc(
    const int a[5],
    const int b[const 5],
    int c[static 5]);

#endif //TYPES_ARRAY_H
