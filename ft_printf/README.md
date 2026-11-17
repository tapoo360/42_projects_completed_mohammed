_This project has been created as part of the 42 curriculum by mabd-al-_

## Description:
ft_printf is a replica of the standard function known to c programmer `printf()`, the function, not only print a bunch of characters onto your monitor, but it provides a format with which you can print whatever value you want to be emitted in your screen, as long as it's supported by the function's format modifiers, which are ascii character that should represent the standard primitive data types that comes with the language like int, char, floot and so on, or a string of ascii characters, or pointers' values, the format modifier that the function supports: %u, %s, %i, %d, %p %z %c. the function is variadic function, meaning it accepts variable number of arguments, and it is defined so by simply typing `...` after the first parameter, it's important to know that the compiler won't accept your variadic functions as long as there is no initial parameter that comes before them, as it consider it as undefined and gives you an error, so you need to provide an initial parameter before `...`, now you may ask yourself for a sec "we know that the compiler need to know how many parameter in the function it compiles to know how to store them and where on the stack, but with variable number of arguments, how can it know where to store the arguments?" well we have a very useful library in our standard C libraries called `<stdarg.h>`, which has a set of interfaces and macros that interfaces the implementation of how we can do that, but you need to first start initiating a stack using `va_start()`, which is a macro, after declaring a variable of type `va_list()`, then fill the stack with arguments that you have provided during the function call, loop over stack to pick your data with `va_args()` and destroy the stack with `va_end()`.

## Instructions:
just type:
```bash
make
```
and it will first compile the libft library, compiles the source code of the ft_printf and the adds the object file with the libft into a single static library, that you can link it into your project execution code at a compile-time.
## Resources: 
man stdio

