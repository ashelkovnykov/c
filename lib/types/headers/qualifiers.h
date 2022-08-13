#ifndef TYPES_QUALIFIERS_H
#define TYPES_QUALIFIERS_H

struct alpha {
  int i1;
};

/**
 * A type qualifier is a keyword applied to a type during declaration as a way of expressing additional information about a value to ensure its
 * correct usage. There are 4 type qualifiers in C:
 *
 * const: A constant value is one which will not be changed after initialization. In addition, the const qualifier signals to the compiler that it can
 *        put the value into read-only memory.
 *
 * volatile: A volatile value has every access to it treated as an observable side effect for the purposes of compiler optimization. Therefore, within
 *           a single execution thread, access to a volatile value cannot be reordered or optimized out.
 *
 * restrict: A restricted pointer hints to the compiler that for the lifetime of the pointer, the value stored at its memory address will not be
 *           accessed through any other means (i.e. this pointer is the only reference to the value). This allows the compiler to optimize memory
 *           accesses.
 *
 * atomic: An atomic value has a guaranteed modification order for read/write accesses. Accesses are guaranteed to not interrupt each other, meaning
 *         that one access is guaranteed to finish completely before another takes place. However, the modification order is not guaranteed to be
 *         consistent across multiple threads - only that an order exists.
 */
struct qualifiers {
  const int i1; // Constant integer type
  int * restrict p1; // Restricted pointer type
  _Atomic double d1; // Atomic double type
  const volatile struct alpha a1; // i1 in alpha is not constant or volatile, but a1 is constant and volatile, so a1.i1 inherits its qualifications
  const volatile int ar1[2]; // The qualifiers here apply to the elements of the array, not the array itself
};

#endif //TYPES_QUALIFIERS_H
