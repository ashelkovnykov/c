# Hardware

C was developed at a time when software engineers were expected to be much more
familiar with the workings of computer hardware in general, particularly the
hardware that they would be using to run their programs.

This section contains information that's relevant to C programming, but has
more to do with the hardware or system on which the C program is running.

## Unified Buffer Cache

It used to be the case that UNIX would reserve a portion of the available RAM
as a "buffer cache": a place to store blocks of data recently accessed from disk
(as opposed to the rest of the RAM, which would store process virtual memory:
code & data). The buffer cache was statically sized and treated like a regular
device (it had its own device and block numbers).

This design was inefficient for many use cases (consider a small program that
frequently opens large files). To improve the usability of this idea, OSes began
to use "unified buffer caches": the buffer cache and the virtual process memory
are unified. Thus, any RAM that's not actively being used by the running
processes is free to be filled with recently-accessed files from disk.

Another beneficial consequence of the unified buffer cache was that it reduced
and simplified the routines available / necessary for working with memory, as
all loaded data could be treated as arbitrary page in memory.

## Virtual Address Space Layout

Modern OSes support massive virtual address spaces with several memory areas
visible to the process. The addresses returned by certain POSIX functions like
`mmap` can come from multiple of these areas; which one is chosen depends on
the implementation of the compiler. Generally, this doesn't matter so long as
the areas don't overlap, but it can cause issues between implementations if the
code expects a specific virtual address to be used.

Areas of the virtual address space:
- stack: temporary storage used by code blocks and function calls; allocated
  automatically
- heap: persistent storage; allocated explicitly
- kernel: area to which the kernel image is mapped, so that it's always in the
  same place between processes
- .text: machine code instructions of the process
- .data: initialized static / global variables
- .rodata: initialized static / global constants
- .bss: uninitialized static / global variables
