#include "../headers/pointers.h"

void examplePointerFunc(int *p0, int a0[1], struct pointers *s0) {
  //
  // ALL POINTERS
  //
  
  int **p1 = &p0; // Pointers can be initialized using the "address-of" operator on a object
  int *p2 = s0->p1; // Members of a struct/union can be read through the "member access through pointer" operator
  int i1 = *p0; // The value stored at a pointer can be read the "de-reference" operator
  void *p3 = p2; // Pointers to void are used to pass objects of unknown type; any pointer can be cast to/from a pointer to void
  double *p4 = 0; // All types of pointers have a special NULL value 0, which means that the pointer is either invalid or uninitialized
  
  //
  // ARRAY POINTERS
  //
  
  int i2 = *a0; // Arrays are implicitly converted to pointers of the array type, pointing to the first element of the array
  int i3 = *(a0 + 1); // Array pointers have special addition, subtraction, increment, and decrement operators which take the type size into account
  
  //
  // FUNCTION POINTERS
  //
  
  void (*f1)(int *, int[], struct pointers *) = examplePointerFunc; // Pointer to a function
  void (*f2)(int *, int[], struct pointers *) = &examplePointerFunc; // Equivalent to the above
  
  if (0) {
    (*f1)(p2, p2, s0); // Call function through pointer
    f2(p2, p2, s0); // Equivalent to above
  }
};
