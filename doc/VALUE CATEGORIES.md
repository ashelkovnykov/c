# Value Categories

Every expression in C has two independent properties: type and value category.

There are three value categories:
1. L-Value
2. R-Value (a.k.a. Non-L-Value)
3. Function Designator

## L-Value

Any expression which has type other than `void` and potentially designates an object (i.e. identifies a memory address containing a value).

The following operators work only on l-value expressions:
- address-of (`&`)
- de-reference (`*`)
- member access (`.`)
- member access through pointer (`->`)
- subscription (`[]`)
- increment (`++`)
- decrement (`--`)
- assignment (`=`)

When a l-value expression in used in any context aside from the operators above (or the functions `sizeof` and `_Alignof`), it undergoes "l-value conversion". This is the process of loading the value from memory, to be used in a non-l-value setting.

The following is an exhaustive list of l-value expressions:
- identifiers
- string literals
- compound literals
- the object returned by the de-reference operator (`*`)
- the object returned by the member access operator (`.`)
- the object returned by the member access through pointer operator (`->`)
- the object returned by the subscription operator (`[]`)
- any l-value expression wrapped by parentheses

## R-Value

Any expression which does not designate an object, but instead designates a value without storage location.

The following is an exhaustive list of r-value expressions:
- character constants
- integer constants
- floating point constants
- function call expressions
- cast expressions
- member access expressions on non-l-value expressions
- arithmetic operations
- relational operations
- logical operations
- bitwise operations
- increment/decrement operations
- assignment operations
- address-of operations

## Function Designator

A special case with properties of both l-value and r-value expressions. The identifier introduced by a function declaration. A function designator is valid input to the address-of operator (`&`), but in all other cases is converted to a r-value pointer to a function.
