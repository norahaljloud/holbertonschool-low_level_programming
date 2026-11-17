#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	unsigned int i, nlen = 0, olen = 0;

	if (name == NULL || owner == NULL)
		return (NULL);
	while (name[nlen])
		nlen++;
	while (owner[olen])
		olen++;
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	dog->name = malloc(nlen + 1);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(olen + 1);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	for (i = 0; i <= nlen; i++)
		dog->name[i] = name[i];
	for (i = 0; i <= olen; i++)
		dog->owner[i] = owner[i];
	dog->age = age;
	return (dog);
}
