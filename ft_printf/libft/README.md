### *This project has been created as part of the 42 curriculum by `mabd-al-`*
## Description:  
libft.a is the equivalent of the usual user-space library which contains string-handling functions, memory manipulation functions, and linked-list handling function, in addition to this, the `libft.h` contains interfaces of these functions, plus the definition of the linked-list node structure, which has two pointers one that points to the actual data that's to be allocated on the heap, then other is the address of the new node that's also allocated on the heap using the well-known user space function `malloc()`. all of the implementation of the whole project is being compiled then add to the `libft.a` library with the command `ar` with option `rcs`.  
## instruction:
all what you have to do is to type:
```bash
make
```
and [maybe] it will take time until the library is built; they type of the library we are going to build is **static library**, a piece of software that that can be linked at a compile time without a dynamic linker at the runtime of the program. once it's finished compiling the source files and load their object files into the static library `libft.a`, the code is ready to be used in any of your program.
## resources:  
- the linux programming interface: p834
- system programming in linux: appendix A, p946, section 'creating libraries'.
