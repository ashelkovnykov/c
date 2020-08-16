# Name Space

The name space of an identifier is the category to which it belongs. C allows the same identifier to refer to multiple separate entities from within the same scope if, and only if, they are in different name spaces.

## Types

There are four types of name space:
1. Label
2. Tag
3. Member
4. Other

### Label

All identifiers referring to labels share a single name space.

### Tag

Identifiers which name a declared `enum`, `struct`, or `union` type all share a single name space.

### Member

Identifiers which refer to members of a single `struct` or `union` share a single namespace. Each `struct` and `union` has its own name space.

### Other

All other identifiers share a single name space.

## Lookup

The name space of an identifier is determined by the manner in which it is used at the time of lookup.
* An identifier appearing as the operand of a `goto` statement is checked for in the label name space
* An identifier that follows one of the keywords `enum`, `struct`, or `union` is checked for in the tag name space
* An identifier which refers to a member of a `struct` or `union` is checked for in the name space of that `struct`/`union`
* All other identifiers are checked for in the 'other' name space