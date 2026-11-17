#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * array_range - creates an array containing values from min to max
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	unsigned int size;
	unsigned int i;

	if (min > max)
		return (NULL);

	size = (unsigned int)((unsigned int)max - (unsigned int)min) + 1;

	if (size > UINT_MAX / sizeof(int))
		return (NULL);

	array = malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = min + (int)i;

	return (array);
}
