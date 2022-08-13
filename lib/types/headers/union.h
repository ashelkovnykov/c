#ifndef TYPES_UNION_H
#define TYPES_UNION_H

/**
 * A union is a user-defined type which stores one or more objects of any type in a single overlapping block of allocated memory. The size of a union
 * object is only as large as necessary to store the largest member (with additional padding possible).
 *
 * A pointer to a union can be safely cast to a pointer of any member type. However, if the most recently written data is not of the type being cast
 * to, then the representation may be malformed.
 *
 * Members of an anonymous union/structure which is itself a member of a union are considered members of the outermost union.
 */
union u {
  // i1 will be considered a member of unions
  struct {
    int i1; // Size = 4
  };
  double i2; // Size = 8
  char a1[12]; // Size = (12 * 1) = 12
  // 4 bytes padding
}; // Size = 16, Alignment = 8

#endif //TYPES_UNION_H
