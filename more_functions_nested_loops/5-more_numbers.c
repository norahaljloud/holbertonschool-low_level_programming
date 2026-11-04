#include "main.h"

/**
 * more_numbers - Prints numbers from 0 to 14 ten times
 *
 * Return: Nothing
 */
void more_numbers(void)
{
	int row, n;

	for (row = 0; row < 10; row++)
	{
		for (n = 0; n <= 14; n++)
		{
			_putchar(n >= 10 ? n / 10 + '0' : n + '0');

			if (n >= 10)
				_putchar(n % 10 + '0');
		}

		_putchar('\n');
	}
}
