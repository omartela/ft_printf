# ft_printf

A custom implementation of the `printf` function in C, recreating the behavior of the standard library's `printf` with support for various format specifiers.

## About

This project is part of the 42 School curriculum, designed to deepen understanding of variadic functions, memory management, and formatted output in C programming. The goal is to recode the `printf` function from scratch, handling multiple data types and format specifiers.

## Features

### Supported Format Specifiers

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a signed decimal integer
- `%i` - Print a signed decimal integer (same as %d)
- `%u` - Print an unsigned decimal integer
- `%x` - Print an unsigned integer in lowercase hexadecimal
- `%X` - Print an unsigned integer in uppercase hexadecimal
- `%%` - Print a literal percent sign

### Key Features

- Handles all major data types
- Proper error handling with return values
- Memory-safe implementation
- Compatible with standard `printf` behavior
- No buffer overflow vulnerabilities

## Installation

### Prerequisites

- GCC or Clang compiler
- Make utility
- Unix-like operating system (Linux, macOS)

### Building the Library

```bash
# Clone the repository
git clone https://github.com/omartela/ft_printf.git
cd ft_printf

# Compile the library
make

# This creates libftprintf.a static library
```

### Available Make Commands

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild everything from scratch
```

## Usage

### Including in Your Project

1. Include the header file in your C source:
```c
#include "ft_printf.h"
```

2. Compile your project with the library:
```bash
gcc your_file.c -L. -lftprintf -o your_program
```

### Function Prototype

```c
int ft_printf(const char *format, ...);
```

### Basic Examples

```c
#include "ft_printf.h"

int main(void)
{
    // Print different data types
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Integer: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42U);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Uppercase hex: %X\n", 255);
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Percentage: %%\n");
    
    return (0);
}
```

Output:
```
Character: A
String: Hello, World!
Integer: 42
Unsigned: 42
Hexadecimal: ff
Uppercase hex: FF
Pointer: 0x7fff5fbff728
Percentage: %
```

### Advanced Examples

```c
#include "ft_printf.h"

int main(void)
{
    int number = -42;
    unsigned int positive = 42;
    char *str = "ft_printf";
    void *ptr = &number;
    
    // Mixed format specifiers
    ft_printf("Number: %d, Positive: %u, String: %s\n", number, positive, str);
    
    // Hexadecimal representations
    ft_printf("Hex (lower): %x, Hex (upper): %X\n", 255, 255);
    
    // Pointer and special cases
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("NULL string: %s\n", NULL);
    
    return (0);
}
```

## Return Value

The `ft_printf` function returns:
- **Positive integer**: Number of characters printed (excluding the null terminator)
- **-1**: If an error occurs during output

## Implementation Details

### File Structure

- `ft_printf.c` - Main function implementation and format parsing
- `ft_printf.h` - Header file with function prototypes
- `ft_printf_utils.c` - Utility functions for basic data types (char, string, int)
- `ft_print_ptr.c` - Pointer printing functionality
- `ft_print_unsnbr.c` - Unsigned number printing
- `ft_print_hex.c` - Hexadecimal number printing
- `Makefile` - Build configuration

### Error Handling

The function handles various edge cases:
- NULL string pointers (prints "(null)")
- Write operation failures
- Invalid format specifiers
- Memory allocation errors

## Compliance

This implementation follows:
- 42 School Norm coding standards
- C99 standard compatibility
- POSIX compliance for system calls

## Author

**omartela** - *42 School Student*
- GitHub: [@omartela](https://github.com/omartela)

## License

This project is created for educational purposes as part of the 42 School curriculum.

---

*Part of the 42 School Common Core curriculum*