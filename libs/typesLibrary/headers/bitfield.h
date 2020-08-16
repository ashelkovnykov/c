#ifndef TYPES_BITFIELD_H
#define TYPES_BITFIELD_H

/**
 * A bit field is an integer value with a explicit, user-defined width in bits. Bit fields must be members of a struct or union.
 *
 * Bit fields can only have one of the following three types:
 * - _Bool
 * - signed int
 * - unsigned int
 *
 * Adjacent bit fields can be packed together to share bytes.
 */
struct BitField {
  unsigned b1 : 5;    // 5 bits used for b1
  signed int b2 : 6;  // 6 bits used for b2
  unsigned : 0;       // Special syntax to break up adjacent bit fields - 21 unused bits
  unsigned b3 : 15;   // 15 bits used for b3
  _Bool b4 : 1;       // 1 bit used for b4
                      // 16 bits unused
};

#endif //TYPES_BITFIELD_H
