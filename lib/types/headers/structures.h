#ifndef TYPES_STRUCTURES_H
#define TYPES_STRUCTURES_H

/**
 * A structure is a user-defined type which stores zero or more objects of any type in a sequence of contiguously allocated memory.
 *
 * A pointer to a struct can be safely cast to a pointer to the first member of that struct.
 *
 * Members of an anonymous union/structure which is itself a member of a structure are considered members of the outermost structure.
 */
struct structure {
  struct {
    int i1; // i1 will be considered a member of structure
  };
  int i2;
  int a1[];
};

/**
 * The final member of a struct can be an array with incomplete size. In such a case, any extra size used to allocate an instance of this structure
 * will be used for the array.s
 */
struct structure s1 = {{1}, 2}; // a1 has size 0 and 0 bytes padding
// struct structure s2 = malloc(sizeof(struct structure) + 2) // a1 has size 0 and 2 bytes padding
// struct structure s2 = malloc(sizeof(struct structure) + 8) // a1 has size 2 and 0 bytes padding

#endif //TYPES_STRUCTURES_H
