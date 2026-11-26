#include "variadic_functions.h"

/**
 * main - tests print_strings
 *
 * Return: Always 0.
 */
int main(void)
{
	print_strings(", ", 2, "Jay", "Django");
	print_strings(" | ", 3, "Hello", NULL, "World");
	print_strings(NULL, 3, "One", "Two", "Three");
	print_strings(", ", 0);

	return (0);
}
