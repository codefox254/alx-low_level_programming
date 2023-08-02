#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Calculates the length of the string.
 * @s: Pointer to the string to evaluate.
 *
 * Return: Length of the string.
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
 * _strcpy - Copies the string pointed to by src to the buffer pointed to by dest.
 * @dest: Pointer to the buffer where the string will be copied.
 * @src: Pointer to the string that will be copied.
 *
 * Return: Pointer to dest.
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
 * new_dog - Creates a new dog.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog if successful, otherwise NULL.
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
