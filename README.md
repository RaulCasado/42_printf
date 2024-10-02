Welcome to the 42 **ft\_printf** project! This project is a custom implementation of the standard C library function `printf`, providing a deeper understanding of variadic functions, formatting, and buffer management.


### Supported Conversion Specifiers

*   `%c` - Character
*   `%s` - String
*   `%d` - Signed decimal integer
*   `%i` - Signed decimal integer
*   `%u` - Unsigned decimal integer
*   `%x` - Unsigned hexadecimal integer (lowercase)
*   `%X` - Unsigned hexadecimal integer (uppercase)
*   `%%` - Literal `%` character

Usage
-----

To use the custom `ft_printf` function in your project, include the header file `ft_printf.h` and link the library `libftprintf.a` after compiling the project.

### Example:

    #include "ft_printf.h"
    
    int main() {
        ft_printf("Hello, %s!\n", "world");
        ft_printf("The value of x is %d and in hex is %x\n", 42, 42);
        return 0;
    }
    

### Output:

    Hello, world!
    The value of x is 42 and in hex is 2a
    

Project Structure
-----------------

The project consists of several files, each with a specific responsibility:

*   **ft\_printf.h**: Header file containing function prototypes, necessary includes, and macros used throughout the project.
*   **ft\_printf.c**: The main implementation of the `ft_printf` function. It handles parsing the format string, calling the appropriate helper functions, and managing the variadic arguments.

Compilation
-----------

To compile the project, simply run:

    make

This command will generate the `libftprintf.a` static library. You can then link this library to your project as follows:

    gcc your_program.c libftprintf.a -o your_program

### Cleaning the Build

To remove object files and clean up the directory, run:

    make clean

To also remove the compiled library (`libftprintf.a`), run:

    make fclean


Key Features
------------

*   **Variadic Function Handling**: This project utilizes `stdarg.h` to handle an arbitrary number of arguments.

Limitations
-----------

This version does not include support for bonus features like flags (`-`, `+`, `0`, `#`, etc.), field width, or length modifiers (`hh`, `h`, `ll`, etc.).

Only the core conversion specifiers listed above are supported.

Testing
-------

You can test the functionality of `ft_printf` by creating a simple C program and using the provided conversion specifiers. Compare the output with the standard `printf` function to ensure accuracy.

### Example test:

    int main() {
        ft_printf("Testing character: %c\n", 'A');
        ft_printf("Testing string: %s\n", "Hello, World!");
        ft_printf("Testing integer: %d\n", 42);
        ft_printf("Testing unsigned: %u\n", 4294967295);
        ft_printf("Testing hex (lowercase): %x\n", 255);
        ft_printf("Testing hex (uppercase): %X\n", 255);
        ft_printf("Testing percentage: %%\n");
        return 0;
    }
    

### Expected Output:

    Testing character: A
    Testing string: Hello, World!
    Testing integer: 42
    Testing unsigned: 4294967295
    Testing hex (lowercase): ff
    Testing hex (uppercase): FF
    Testing percentage: %
    
