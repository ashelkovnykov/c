# Storage Duration

All C functions and entities have a storage duration (time from allocation to de-allocation) which determines their lifetime (the portion of program execution over which the entity has a constant memory address and will retain its value).

There are four types of storage duration:

1. Automatic
2. Static
3. Thread
4. Allocated

## Lifetime

### Automatic

An entity with automatic storage duration has memory allocated when the block in which it is declared is entered (by any means) and de-allocated when the aforementioned block is exited (by any means). If the block is entered recursively, this process is repeated for each recursion level.

Thus, the lifetime of an entity with automatic storage duration is the entirety of the block in which it was declared.

### Static

A function/entity with static storage duration has memory allocated once, prior to the main function, and de-allocated after the main function ends.

Thus, the lifetime of an entity with static storage duration is the entirety of program execution.

### Thread

An entity with thread storage duration has memory allocated when the thread starts and de-allocated when the thread ends. Each thread has its own copy of the entity.

Thus, the lifetime of an entity with thread storage duration is the entirety of lifetime of the thread in which it was declared.

### Allocated

An entity with allocated storage duration has memory allocated whenever the memory allocation function is called and de-allocated whenever memory is re-allocated or the memory de-allocation function is called.

Thus, the lifetime of an entity with allocated storage duration is the portion of program execution from the first memory allocation call to the final (valid) memory de-allocation call.

### Temporary

Array members of non-lvalue `struct`/`union` entities have temporary lifetime. Temporary lifetime begins when the (sub-)expression containing the Array member begins and ends when the full expression/declaration does.

## Storage-Class Specifiers

There are five types of storage-class specifiers which can be used during entity declaration to determine storage duration:

1. `auto`
2. `register`
3. `static`
4. `extern`
5. `_Thread_local`

If no storage-class specifier is present at declaration, a default storage-class specifier is applied. The default is `extern` for functions and entities in the file scope. The default is `auto` for objects in block scope and function parameter lists.

### `auto`

The `auto` specifier is only allowed for entities in block scope, excluding function parameter lists. It indicates automatic storage duration.

### `register`

The `register` specifier is only allowed for entities in block scope. It indicates automatic storage duration, but also hints to the compiler that the value should be stored in a CPU register, as opposed to in memory.

Entities declared with the `register` specifier cannot have their address taken, cannot have their alignment modified, and cannot be converted to pointers when in an Array.

### `static`

The `static` specifier is allowed everywhere, excluding function parameter lists. It indicates static storage duration.

**Note:** The `static` specifier will also affect linkage. 

### `extern`

The `extern` specifier is allowed everywhere, excluding function parameter lists. It indicates static storage duration.

**Note:** The `extern` specifier will also affect linkage. 

### `_Thread_local`

The `_Thread_local` specifier is allowed only for value entities, in either file or block scope. It indicates thread storage duration.

**Note:** If used with an entity declared in block scope, it must be paired with either `static` or `extern` to determine linkage, as block scope identifiers by default have no linkage at all.