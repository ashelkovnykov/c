#ifndef TYPES_INTEGER_H
#define TYPES_INTEGER_H

struct integers {
  
  //
  // LINUX, UNIX, & MAC OS (IEEE standard LP64)
  //
  
  short s1; // 16-bit, represents integers in range [-32,768 - 32,767]
  short int s2;
  signed short s3;
  signed short int s4;
  unsigned short s5; // 16-bit, represents integers in range [0 - 65,535]
  unsigned short int s6;
  int i1; // 32-bit, represents integers in range [-2,147,483,648 - 2,147,483,647]
  signed i2;
  signed int i3;
  unsigned i4; // 32-bit, represents integers in range [0 - 4,294,967,295]
  unsigned int i5;
  long l1; // 64-bit, represents integers in range [-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807]
  long int l2;
  signed long l3;
  signed long int l4;
  unsigned long l5; // 64-bit, represents integers in range [0 - 18,446,744,073,709,551,615]
  unsigned long int l6;
  
  //
  // WINDOWS (IEEE standard LLP64)
  //
  
  long wl1; // Equivalent to 'int' above
  long int wl2;
  signed long wl3;
  signed long int wl4;
  unsigned long wl5; // Equivalent to 'unsigned int' above
  unsigned long int wl6;
  long long wll1; // Equivalent to 'long' above
};

#endif //TYPES_INTEGER_H
