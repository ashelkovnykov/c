# Operators Library

This C library contains examples for the C language operators. Below, there is also an explanation for how operators take precedence over one another when an expression is not adequately grouped using parentheses.

## Operator Precedence

- Group 1 (left-to-right)
  - `++` (postfix)
  - `--` (postfix)
  - `()`
  - `[]`
  - `.`
  - `->`
- Group 2 (right-to-left)
  - `++` (prefix)
  - `--` (prefix)
  - `+` (unary)
  - '-' (unary)
  - `!`
  - `~`
  - `(cast)`
  - `*` (de-reference)
  - `&` (address-of)
  - `sizeof`
  - `_Alignof`
- Group 3 (left-to-right)
  - `*` (multiplication)
  - `/`
  - `%`
- Group 4 (left-to-right)
  - `+` (addition)
  - `-` (subtraction)
- Group 5 (left-to-right)
  - `>>`
  - `<<`
- Group 6 (left-to-right)
  - `<`
  - `>`
  - `<=`
  - `>=`
- Group 7 (left-to-right)
  - `==`
  - `!=`
- Group 8 (left-to-right)
  - `&` (bitwise AND)
- Group 9 (left-to-right)
  - `^`
- Group 10 (left-to-right)
  - `|`
- Group 11 (left-to-right)
  - `&&`
- Group 12 (left-to-right)
  - `||`
- Group 13 (right-to-left)
  - `?:`
- Group 14 (right-to-left)
  - `=`
  - `+=`
  - `-=`
  - `*=`
  - `/=`
  - `%=`
  - `<<=`
  - `>>=`
  - `&=`
  - `^=`
  - `|=`
- Group 15 (left-to-right)
  - `,`
  
Operators which are on the same line are treated as if they were bounded by parentheses (i.e. tightly coupled).