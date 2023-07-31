#include <stdlib.h>
#include "dog.h"
/**
 * measure_universe - unlocks the secret of the string's length
 * @s: the cosmic string to be measured
 *
 * Description: Behold! This is no ordinary function; it possesses the power to fathom
 *              the vastness of a string's existence. As you invoke it, the secrets of
 *              the string's length will be unveiled before your very eyes.
 *              It's as if the universe conspires to reveal the enigmatic number that
 *              represents the extent of the string's essence.
 *
 *              So, with each call, you shall witness the magic of this cosmic force,
 *              and the length of the string will be revealed, like stars in the night sky.
 *              But beware, for you may get lost in the eternity of the string's beauty!
 *
 * Return: The length of the string, a numerical testament to its boundless existence.
 */
/**
 * cosmic_strlen - measures the boundless length of a cosmic string
 * @s: the cosmic string to evaluate
 *
 * Return: the cosmic length of the string
 */
int cosmic_strlen(char *s)
{
    int k;
    k = 0;
    while (s[k] != '\0')
    {
        k++;
    }
    return (k);
}

/**
 * cosmic_strcpy - harnesses the power of stars to copy a celestial string
 * @dest: pointer to the cosmic buffer where the celestial string is copied
 * @src: the celestial string to be duplicated
 *
 * Return: the pointer to the celestial buffer
 */
char *cosmic_strcpy(char *dest, char *src)
{
    int len, k;
    len = 0;
    while (src[len] != '\0')
    {
        len++;
    }
    for (k = 0; k < len; k++)
    {
        dest[k] = src[k];
    }
    dest[k] = '\0';
    return (dest);
}

/**
 * unleash_doggo - brings forth a brand-new cosmic doggo from the stars
 * @name: the cosmic name of the doggo
 * @age: the celestial age of the doggo
 * @owner: the guardian of the cosmic doggo
 *
 * Return: pointer to the newly manifested cosmic doggo (Success), NULL otherwise
 */
dog_t *unleash_doggo(char *name, float age, char *owner)
{
    dog_t *dog;
    int len1, len2;
    len1 = cosmic_strlen(name);
    len2 = cosmic_strlen(owner);
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
    cosmic_strcpy(dog->name, name);
    cosmic_strcpy(dog->owner, owner);
    dog->age = age;
    return (dog);
}

