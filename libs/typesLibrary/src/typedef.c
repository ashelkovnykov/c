#include "../headers/typedef.h"

/**
 * The typedef command allows the user to create an alias for an existing type. This allows complex types to be referred to with much simpler
 * identifiers.
 */
typedef char char_t, * char_p;  // char_t is an alias for type char, char_p is an alias for pointer to char
typedef char (*fp)(int);        // fp is an alias for type "function taking an in as input and returning a pointer to a char"

void exampleTypedefFunc(int i) {
  typedef int arr1[i];  // Typedef aliases for VLAs can only exist in block scope - the length of the array is evaluated each time flow enters the block
  typedef int arr2[];   // Typedef aliases can be incomplete, and can be completed like that type that they alias
  arr2 arr21 = {1, 2, 3, 4};
}
