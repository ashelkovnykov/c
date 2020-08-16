# Order of Evaluation

Operators and functions can syntactically take expressions as input. However, these expressions must be evaluated before they can be valid input to the function/operator. There are two types of evaluation in C: value computation (i.e. resolving an equation to a singular value) and side effect realization (i.e. performing a non-value task, such as writing to a file).

Consider the following example expression:
```
f1(f2(f3() + f4()), f5())
```
There are several possible orders in which to evaluate the functions:
- `f5, f4, f3, f2, f1`
- `f5, f3, f4, f2, f1`
- `f4, f3, f5, f2, f1`
- `f3, f4, f5, f2, f1`
- `f4, f3, f2, f5, f1`
- `f3, f4, f2, f5, f1`

Depending on the side effects of each of these functions, the order of evaluation could affect the output of the program. However, C makes only limited guarantees about the order of evaluation using "sequence points".

## Sequence Points

Sequence points are points in the program at which unevaluated expressions which have appeared since the previous sequence point are evaluated. If an evaluation A is sequenced before an evaluation B, then the evaluation of A is guaranteed to be completed before the evaluation of B. However, if neither A nor B is sequenced before the other, then their order of evaluation is undetermined: either A may be evaluated before B or B before A, and this order can change between subsequent calls to the same expression.

### Rules

Below is the list of rules regarding sequence points.

1. There is a sequence point after the evaluation of all function arguments, but before the actual function call.
2. There is a sequence point between the evaluations of the first and second operands for the `&&`, `||`, and `,` operators.
3. There is a sequence point between each of the operands for the ternary operator.
4. There is a sequence point between each full expression (i.e. one ending in a semicolon).
5. There is a sequence point at the end of a full declarator.
6. There is a sequence point directly before the return statement of a library function.
7. There is a sequence point after each value injection using formatted I/O (e.g. `printf`).
8. There is a sequence point directly before and after each call to `qsort` and `bsearch`.
9. The value computations (but not side effects) of the operands to all operators are sequenced before the value computation of the operator (but not its side effects).
10. The value computation (but not side effects) of both arguments to all assignment operators is sequenced before the assignment.
11. The value computation of the postfix increment/decrement operators is sequenced before the assignment.
