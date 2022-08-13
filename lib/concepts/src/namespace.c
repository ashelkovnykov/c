#include "../headers/namespace.h"

/**
 * All of the entities in 'namespaceDoNothing' have the same identifier, but there is no conflict since each one refers to a different name space:
 * - The user-defined structure registered identifier 'A' in the tag name space
 * - The int member of struct 'A' registered identifier 'A' in the name space for struct 'A'
 * - The label in 'namespaceDoNothing' registered identifier 'A' in the label name space
 * - The object in 'namespaceDoNothing' registered identifier 'A' in the general name space
 */
void namespaceDoNothing() {
A:
  struct A A = { .A = 1 };
}
