#ifndef TYPES_FLOATING_H
#define TYPES_FLOATING_H

struct floating {
  //
  // REAL
  //
  
  float f1; // 32-bit, represents floating point numbers, approx. min = 1.4 * 10^-45, approx. max = 3.4 * 10^38
  double d1; // 64-bit, represents floating point numbers, approx. min = 4.94 * 10^-324, approx. max = 1.79 * 10^308
  
  //
  // COMPLEX
  //
  
  /**
   * Represent floating point numbers with an imaginary component, under the hood it's an array of two float/double, the second of which is implicitly
   * multiplied by I (the imaginary number, sqrt(-1).
   */
  float complex cf1;
  double complex cd1;
};

#endif //TYPES_FLOATING_H
