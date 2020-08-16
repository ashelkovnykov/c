#include <stdio.h>

#include "../headers/scope.h"

/**
 * Object 'abc' has default scope/linkage for object declared outside of block/parameter list without an explicit linkage specifier:
 * - File scope
 * - External linkage
 */
int abc = 1;

/**
 * Object 'def' has an explicit linkage specifier, but still the same scope/linkage as if it didn't:
 * - File scope
 * - External linkage
 */
extern int def = 2;

/**
 * Object 'xyz' has an explicit, non-default linkage specifier. However, it has the same scope as all objects declared outside of a block or parameter
 * list:
 * - File scope
 * - Internal linkage
 */
static int xyz = 3;

/**
 * Object 'abc' has the same identifier as an object defined above and they are both in the same name space. Therefore, the scopes are nested, and
 * all references to the identifier 'abc' within the function body will refer to the object in the function parameter list. It has:
 * - Block scope
 * - No linkage
 */
void printScope(int abc) {

  if (abc > 10) {
    /**
     * Object 'abc' again has the same identifier as an object defined above and again all of the identifiers are in the same name space. The scopes
     * are nested again: all references to the identifier 'abc' will now refer to the object defined below.
     */
    int abc = 10;
    
    printf("%d\n", abc);
    
    goto end;
  }

  /**
   * The labels 'increment' and 'end' both have function scope, and therefore are valid throughout the entire function body, even before their own
   * definition.
   */
increment:
  abc += def;
  
  if (abc < 0) goto increment;
  
end:
  return;
}

/**
 * Object 'ghi' has function prototype scope, meaning that it is in scope from definition to the end of the declarator. The function prototype for
 * 'neverUsed' is valid, but if the orders of the two parameters were reversed, then it would not be so.
 */
static void neverUsed(int ghi, int array[ghi]);
