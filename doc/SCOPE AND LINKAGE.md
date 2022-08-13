# Scope & Linkage

Scope and Linkage are two related (but often confused) aspects of C. This document defines both and clarifies the
differences between them.

## Context

Prior to reading this document, reading the following documents is recommended to understand the exact meaning of the
following terms:
* Translation unit
* Statement
* Label
* Name space

## Scope

The "scope" of an identifier in C is the region of the program in which it is valid (i.e. where it can be used to
directly refer to the entity to which it is bound). Outside of its scope, the same identifier may be invalid, or may
refer to another entity.

C uses "lexical" scoping, meaning that the scope of an identifier is determined by where it is defined.

### Types of Scope

There are four types of scope in C:
* File Scope
* Block Scope
* Function Scope
* Function Prototype Scope

#### File Scope

The scope of any identifier that is declared outside of a block or parameter list begins at its declaration and ends at
the end of the translation unit.

#### Block Scope

The scope of an identifier declared inside of a statement or function parameter list begins at its declaration and ends
at the end of the statement.

#### Function Scope

The scope of all labels (and only labels) declared within a function body is the entire function body: before its own
declaration, after its own declaration, and within all nested block scopes.

#### Function Prototype Scope

The scope of an identifier in the parameter list of a function declaration which is not also a function definition
begins at its declaration and ends at the end of the function declarator.

### Exact Point of Declaration

For identifiers referring to `enum`, `struct`, and `union` types, the exact point of declaration is as soon as the
identifier appears.

For identifiers referring to `enum` constants, the exact point of declaration is after the appearance of its defining
enumeration value (if one exists).

For all other identifiers, the exact point of declaration is after the end of the declarator and before the initializer
(if one exists).

### Nested Scopes

If an identifier is in more than one scope in the same name space at the same time, the scopes are automatically nested.
The innermost scope is given priority and hides the entity referred to by any other scopes.

## Linkage

"Linkage" refers to how identical identifiers from different translation units are or are not "linked" to the same
entity. It is an extension of scope necessary for the creation of function libraries and code reuse.

### Types of Linkage

There are two types of linkage: internal and external.

#### Internal Linkage

An identifier with internal linkage has regular file scope. Uses of the identifier in multiple translation units refer
to distinct entities, even if the declaration of the identifier is imported into each translation unit from the same
header file.

An identifier can be declared with explicit internal linkage using the keyword `static` (when declaring an identifier
with file scope; the `static` keyword has a different meaning when used in block scope). Identifiers for constant
entities have internal linkage by default.

#### External Linkage

An identifier with external linkage has file scope which extends beyond a single translation unit. All references to the
identifier throughout the program are assumed to refer to the same entity. Therefore, the object files linked together
into a single program during phase nine of translation must contain exactly one definition for the entity.

An identifier can be declared with explicit external linkage using the `extern` keyword. Note that doing so does not
actually declare a variable: it just declares that it will be available during linking.

Identifiers for non-constant variables have external linkage by default.
