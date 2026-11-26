#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints different types of arguments
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	char *str;
	const char *separator = "";

	va_start(args, format);

	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(args, int));
			separator = ", ";
			break;
		case 'i':
			printf("%s%d", separator, va_arg(args, int));
			separator = ", ";
			break;
		case 'f':
			printf("%s%f", separator, va_arg(args, double));
			separator = ", ";
			break;
		case 's':
			printf("%s", separator);
			str = va_arg(args, char *);
			if (str != NULL)
				printf("%s", str);
			if (str == NULL)
				printf("(nil)");
			separator = ", ";
			break;
		default:
			break;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
