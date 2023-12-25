<h1 align="center">
	ft_printf
</h1>
<p align="center"><b><i>A boiled down printf implementation</i></b></p>
---
## Overview:

This project involves the creation of a custom implementation of the `printf` function in the C programming language. `printf` is a standard output formatting function that is widely used in C and other programming languages. The goal of this project is to create a simplified version of `printf`, supporting a subset of format specifiers and providing essential functionality for formatting and printing output.

## Files:

1. **ft_printf.c**: The main file containing the implementation of the `printf` function.
2. **ft_printf.h**: The header file declaring function prototypes and any necessary data structures or constants.
3. **ft_printf_utils.c**: Utility functions used by the `printf` implementation for various tasks.
4. **ft_flag_utils.c**: Utility functions for handling format flags in the `printf` function.
5. **ft_flags.c**: Implementation of handling various format flags.
6. **ft_generic_utils.c**: Generic utility functions that support the `printf` implementation.
7. **ft_hex_format_utils.c**: Utilities for handling hexadecimal format specifiers.
8. **ft_int_format_utils.c**: Utilities for handling integer format specifiers.
9. **ft_ldtoa.c**: Functions for converting long doubles to ASCII strings.
10. **ft_print_char.c**: Implementation for printing characters.
11. **ft_print_hex.c**: Implementation for printing hexadecimal values.
12. **ft_print_hex_utils.c**: Utilities for printing hexadecimal values.
13. **ft_print_int.c**: Implementation for printing integers.
14. **ft_print_int_utils.c**: Utilities for printing integers.
15. **ft_print_percent.c**: Implementation for printing the '%' character.
16. **ft_print_pointer.c**: Implementation for printing pointer addresses.
17. **ft_print_string.c**: Implementation for printing strings.
18. **ft_print_uint.c**: Implementation for printing unsigned integers.
19. **ft_print_uint_utils.c**: Utilities for printing unsigned integers.
20. **ft_ptoa.c**: Functions for converting pointers to ASCII strings.
21. **ft_uint_format_utils.c**: Utilities for handling unsigned integer format specifiers.
22. **ft_xtoa.c**: Functions for converting integers to hexadecimal ASCII strings.

## Project Goals:

1. Implement a simplified version of the `printf` function that supports basic format specifiers.
2. Handle various format flags, such as width, precision, and alignment.
3. Support a subset of conversion specifiers, including characters, strings, integers, hexadecimal, and pointers.
4. Create utility functions to enhance code modularity and maintainability.
5. Test the `printf` implementation with a variety of input cases to ensure correctness and reliability.

## Usage:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/kbly538/ft_printf.git
   cd ft_printf
2. **Build the Project**
   ```bash
   make
To use the custom `printf` implementation, include the "ft_printf.h" header file in your C source code and call the `ft_printf` function with the desired format string and arguments.
