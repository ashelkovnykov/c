# POSIX

A lot of the most important / frequently used functions in C are defined by the
POSIX standard. POSIX compliant operating systems make available a known set of
functions that all function in the exact same way, regardless of the underlying
OS.

This section documents some of those functions.

## `sigsetjmp` / `siglongjmp`

The `setjmp` and `longjmp` functions are often used by signal handlers to
set up a return point within the main loop of a program and return to it via
non-local branching.

The default behaviour of a signal handler is to add a signal to the "signal
mask" when it's caught. This prevents subsequent occurrences of the same signal
from interrupting the signal handler.

The above two functionalities introduce a bug: what happens to the signal mask
when you `longjmp` out of the signal handler? `setjmp` and `longjmp` do not
define a standard for this. On FreeBSD and macOS, these functions save and
restore the signal mask. On Linux and Solaris, they do not. In order to not
disturb the long-standing functionality of these functions, POSIX instead
introduced two new functions which explicitly define a standard around saving
and restoring the signal mask: `sigsetjmp` and `siglongjmp`.

NOTE: FreeBSD and macOS also define versions of `setjmp` and `longjmp` that do
not save / restore the signal mask, in case such functions are needed: `_setjmp`
and `_longjmp`.

## `mmap`

The `mmap` function is responsible for creating "memory mappings" (direct
mappings of virtual address space to memory), using either "memory mapped files"
or "anonymous mappings".

Each `mmap` memory mapping must specify whether it is a `SHARED` vs. `PRIVATE`
mapping, and whether it is a `FILE` vs. `ANONYMOUS` mapping. Combined, you get
the following matrix of possible mappings:
1. PRIVATE FILE MAPPING
2. SHARED FILE MAPPING
3. PRIVATE ANONYMOUS MAPPING
4. SHARED ANONYMOUS MAPPING

### FILE

Specifies that a file on disk is to be used for loading the data into memory.
The typical process of using `mmap` to create a memory-backed file is:
1. `open(2)` file to get a file descriptor
2. `fstat(2)` the file to get the size of the file from the file descriptor
3. `mmap(2)` the file using the file descriptor and size
4. `close(2)` the file descriptor
5. Use the file-backed memory as necessary

### ANONYMOUS

Anonymous mappings don't use a backing file on disk; instead, they come as a
zero-filled block of memory (though they can be pictured as a zeroed virtual
file with very quick access times). Anonymous mappings exist outside the heap,
and therefore don't contribute to data segment fragmentation, however
(de)allocations of anonymous mappings are slower than `malloc` / `free` calls.
When unmapped, the memory is returned to the system immediately. When evicted,
anonymous 

### SHARED

Changes to shared mappings happen in-place. If a file-backed page with changes
is evicted from memory, the changes are written to the backing file on disk.

### PRIVATE

Changes to private mappings happen using copy-on-write semantics: a copy of
the page is made and the changes are applied to the copy. If a file-backed
page with changes is evicted from memory, it goes into `swap` until synced
to the file manually.

### Use Cases

1. PRIVATE FILE MAPPING: IPC mechanism; data comes from file but changes
   require second-order processing to make it into the file
2. SHARED FILE MAPPING: data recovery; the most-recent "good" state of the
   process can be recovered from disk
3. PRIVATE ANONYMOUS MAPPING: Zeroed memory; quick allocation of all-0
   memory block
4. SHARED ANONYMOUS MAPPING: IPC mechanism; alternative to shared memory for
   related processes (parents, siblings, and children)
