#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: string to print
 */
void puts2(char *str)
{
	int length;
	int i;

	length = 0;
	i = 0;

	while (str[length] != '\0')
		length++;

	while (i < length)
	{
		_putchar(str[i]);
		i += 2;
	}

	_putchar('\n');
}
