# Conversion

It's possible to use an expression or value of one type in a context where another type is expected. Depending on the exact types, an implicit conversion may take place, or an explicit cast will be required.

Examples of situations in which a conversion may be necessary:
- Assignment
- Initialization
- Passing function arguments
- Function return statements

## Implicit Conversions

### Boolean Conversion

All values which compare equal to 0 are converted to 0. All other values are converted to 1.

### Integer Promotion

Integer promotion is the implicit conversion of values with type `_Bool`, `char`, `unsigned char`, `short`, and `unsigned short` to type `int`.

### Integer Ranks

All of the integer types have a "rank" which is used when processing some implicit conversions (see below). The ranks are as follows:
1. `_Bool`
2. `char`, `signed char`, `unsigned char`
3. `short`, `unsigned short`
4. `int`, `unsigned int`
5. `long`, `unsigned long`

### Integer Conversion

Integer promotion handles conversion "up" of integers. However, the following rules handle conversion "down":
1. If the target type can support the value, then the value is unchanged
2. If the target type is unsigned, the value is computed using modulo arithmatic
3. If the target type is signed, each compiler has its own implementation of what to do

### Floating Point to Integer Conversion

The value is first truncated. If it can fit into the target integer type, it does so. Otherwise, the behaviour is undefined.

### Arithmetic Conversions

When an arithmetic and comparison operators receive operands of two different types, they attempt to resolve the type in the following order:
- If one operand has type `double`, the other operand is converted to type `double`
- If one operand has type `float`, the other operand is converted to type `float`
- If both operands have integer type, then:
  - Perform integer promotion
  - If they have the same signed-ness, then the operand with lower type conversion rank is converted
  - If the operand with `unsigned` type has higher (or equal) type conversion rank, then the other operand is converted
  - If the operand with `signed` type can support all values of the `unsigned` type, the `unsigned` type is converted
  - Otherwise, both operands are converted to the `unsigned` counterpart of the `signed` operand
  
For floating point numbers, if one operand is complex and the other real, then the real number is converted to a complex number.

## Casting

The following rules govern valid usage of the cast operator to make explicit type conversions:
- Any integer type can be cast to any pointer type
- Any pointer type can be cast to any integer type
- Any pointer type can be cast to any pointer type
- Any pointer to a function can be cast to any other type of pointer to a function
- When casting `NULL` pointers from one type to another, the result is a `NULL` pointer of the appropriate type
