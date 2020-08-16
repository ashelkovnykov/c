#ifndef TYPES_POINTERS_H
#define TYPES_POINTERS_H

/**
 * A pointer is a reference to a memory address containing an object of a chosen type, or a function.
 *
 * Qualifiers that appear after the '*' modify the pointer itself.
 */
struct pointers {
  int *p1; // pointer to int
  int **p2; // pointer to pointer to int
  const int *p3; // pointer to constant int
  int * const p4; // constant pointer to int
  const int * const p5; // constant pointer to constant int
  const int * const *p6; // pointer to constant pointer to constant int
};

void examplePointerFunc(
    int *p0,
    int a0[],
    struct pointers *s0);

#endif //TYPES_POINTERS_H
