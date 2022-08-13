#ifndef TYPES_CHARACTER_H
#define TYPES_CHARACTER_H

struct characters {
  char c1; // Equivalent to either signed char or unsigned char, depending on the compiler. Used to represent ASCII characters.
  signed char c2; // Represents integers in the range [-128 - 127], or ASCII characters.
  unsigned char c3; // Represents raw memory contents, integers in the range [0 - 255], or ASCII characters.
};

#endif //TYPES_CHARACTER_H
