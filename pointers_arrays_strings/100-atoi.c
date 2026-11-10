#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int found;
	unsigned int number;

	i = 0;
	sign = 1;
	found = 0;
	number = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			number = number * 10 + (unsigned int)(s[i] - '0');
		}
		else if (found == 1)
			break;

		i++;
	}

	if (found == 0)
		return (0);

	return ((int)(number * sign));
}
