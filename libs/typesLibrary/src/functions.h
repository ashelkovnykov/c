#ifndef TYPES_FUNCTIONS_H
#define TYPES_FUNCTIONS_H

// Function return types are not qualified
const int functionOne(int x);
int (*functionTwo)(int x) = functionOne;
const int (*functionThree)(int x) = functionOne;

// Function declarators can be combined with other declarators
const int myConst, functionFour(int x);

// Function declarators do not need to give names to function parameters
int functionFive(int);

// The only storage class specifier allowed for function parameters is register
int functionSix(register int x);

// void parameter type and no parameter type are not identical
int functionSeven(void);  // Takes no parameters
int functionEight();      // Takes unknown number of parameters

// Functions can have variable number of inputs, using the stdarg.h library
void functionNine(char c, int x, ...);

/**
 * Inline is a keyword which hints to the compiler that calls to the function can be replaced by a copy of the code instead of a execution jump. The
 * compiler often ignores the inline keyword when it's present, and applies it when it's not. It also requires very high expertise to know when to
 * apply the inline keyword for performance gain.
 */
inline int functionTen(int);

#endif //TYPES_FUNCTIONS_H
