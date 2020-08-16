# Objects

A C object is a region of data storage in the execution environment which contains binary data representing a value. C programs create, access, manipulate, and destroy objects.

Every C object has the following properties:
* Size
* Alignment
* Storage duration
* Lifetime
* Effective type
* Value
* Identifier (optional)

Some of the above properties (e.g. storage duration, lifetime, identifier) are documented elsewhere. The remainder (e.g. size, alignment, effective type) are documented below.

## Size

The size of an object is the number of contiguous bytes used to store its value.

**Note:** This does not mean that all of the bits are necessary for storing the value, nor that they are all used to interpret its value.

## Effective Type

The effective type of an object determines which l-value accesses are valid. For an object that was created by a declaration, the explicitly declared type is its effective type.

Objects created by allocation functions have no declared type, and therefore acquire an effective type through one of three methods:
1. From the first write to the object address by a l-value expression with a non-character type
2. From another object whose value is copied to it by `memcpy` or `memmove`
3. From any other l-value expression which accesses the object

Explicitly attempting to treat an object of effective type T1 as of effective type T2 is undefined, unless:
* T1 and T2 are compatible
* T2 is a signed/unsigned variant T1
* T2 is an aggregate/union type which includes a compatible or signed/unsigned variant of T1
* T2 is a character type

## Alignment

Alignment is the minimum number of bytes that must occur between successive addresses of the same type. The alignment of a complete type is related to its size and is used by the processor to speed up access to values of known types. For example, an `int` uses 4 bytes of memory for storage. Therefore, any `int` value should be located at a memory address divisible by 4.

Every complete type has an alignment. Compound entities (i.e. `struct` and `union`) derive their alignment from the types of their members: they use the maximal alignment value. For example, a `struct` with only `char` members will have alignment 1. A `struct` with `char` and `int` members will have alignment 4.