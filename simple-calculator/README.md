# Simple Calculator

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run Instructions
./calculator

## Supported Operations
- Addition
- Subtraction
- Multiplication
- Division
- Quit using option 0

## Numeric Behavior
- Menu choices use integers.
- Arithmetic operands use double precision floating-point numbers.
- Results support decimal values.
- Results are displayed using %g to avoid unnecessary trailing zeros.

## Known Limitations
- Non-numeric input validation is not supported.
