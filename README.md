# ft_printf
The ft_printf function prints formatted output to the standard output according to the format specifier in the input string.
It supports only the following format specifiers.

Format Specifiers:

* %c: Print a single character.
* %s: Print a null-terminated string.
* %d or %i: Print a signed integer.
* %X or %x: Print an unsigned integer in hexadecimal format.
* %p: Print the address of a pointer in hexadecimal format.
* *%u: Print an unsigned integer in decimal format.
* %%: Print a percent sign ‘%’.

# 🛠️ Usage
Requirements

This program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Instructions

Compiling the program

$ make

After compilation you will get an archive file with  .a  extention (which is a static library archive) to link and compile it with your other programs, you need to follow these steps:

1. Compilation: Compile your main program files (*.c) along with any necessary header files using the clang compiler.

  $ clang -c main.c -o main.o

2. Linking: Link your main program with the static library file (.a file) using the -l option followed by the name of the library, and optionally specify the path to the library using the -L option.

  $ clang main.o -o my_program -L/path/to/library -lmylibrary

# 📑 Index
@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.
