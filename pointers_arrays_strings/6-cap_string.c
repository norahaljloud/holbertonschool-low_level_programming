#include "main.h"

/**
 * cap_string - capitalizes the first letter of each word
 * @str: string to capitalize
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	int capitalize;

	i = 0;
	capitalize = 1;

	while (str[i] != '\0')
	{
		if (capitalize && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');

		capitalize = (str[i] == ' ' || str[i] == '\t' ||
			      str[i] == '\n' || str[i] == ',' ||
			      str[i] == ';' || str[i] == '.' ||
			      str[i] == '!' || str[i] == '?' ||
			      str[i] == '"' || str[i] == '(' ||
			      str[i] == ')' || str[i] == '{' ||
			      str[i] == '}');
		i++;
	}

	return (str);
}
