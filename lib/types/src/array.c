#include "../headers/array.h"

//
// INITIALIZATION
//

static int a1[5] = {5, 4, 3}; // Declares array of five integers: [5, 4, 3, 0, 0]
static char a2[] = "abc"; // Declares array of 4 characters: ['a', 'b', 'c', '\0']

//
// FUNCTION PARAMETER LISTS
//

/**
 * Most usages of an array are implicitly converted to a pointer of the array's type, including in function parameter lists. Therefore, the size of
 * the array in a function parameter list is actually meaningless. For multidimensional arrays, this process is repeated: a reference 2D int array is
 * implicitly converted to a pointer to pointer to int.
 *
 * In a function parameter list, qualifiers can be added to the inside of the brackets used to denote array size to modify the pointer to the array.
 *
 * @param a Expects array, of any size, of constant integers
 * @param b Expects constant pointer to array, of any size, of constant integers
 * @param c Expects array, of size at least 5, of integers
 */
void exampleArrayFunc(
    const int a[5],
    const int b[const 5],
    int c[static 5]) {
  
  //
  // BLOCK SCOPE
  //
  
  /**
   * In block scope, an array can be declared with a variable length which must evaluate to a positive integer. The expression will be evaluated each
   * time the array is allocated (since the lifetime of the array will end once it goes out of scope).
   */
  int n = 1;
  label:;
  int d[n]; // Evaluates to length one the first time, then goes out of scope and evaluates to two the second time.
  if (n++ < 2) goto label;
}
