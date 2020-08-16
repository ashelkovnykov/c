#ifndef TYPES_ENUMERATION_H
#define TYPES_ENUMERATION_H

/**
 * Enumerations are user-defined, named, integer constants with type 'int' used as an alternative to preprocessor macros. They can be used wherever
 * integer input is required. The integer values of an enumeration constant can be explicitly initialized. Otherwise, it will be one more than the
 * previous enumeration constant (if it's the first constant, its value will be 0).
 */
enum colours {
  RED, // 0
  ORANGE, // 1
  YELLOW = 10, // 10
  GREEN, // 11
  BLUE = 100, // 100
  INDIGO = 1, // 1
  VIOLET = BLUE + YELLOW + ORANGE // 111
};

#endif //TYPES_ENUMERATION_H
