#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int length;
	int i;
	char temp;

	length = 0;
	i = 0;

	while (s[length] != '\0')
		length++;

	while (i < length / 2)
	{
		temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
		i++;
	}
}
