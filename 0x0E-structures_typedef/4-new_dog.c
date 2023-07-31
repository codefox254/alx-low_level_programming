#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - This will return the length of a string
 * @s: this string to evaluate
 *
 * Return: Will return the length of the string on success and NULL if otherwise
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * *_strcpy - will copy the string pointed to by src
 * this includes the terminating null byte (\0)
 * To the buffer pointed to by dest
 * @dest: Is the pointer to the buffer in which we copy the string
 * @src: Is the string to be copied
 *
 * Return: Will return the pointer to dest on succss
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * New_dog - This creates the new dog
 * @Name: name of the dog
 * @Age: age of the dog
 * @Owner: owner of the dog
 *
 * Returns: the pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1, len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}
