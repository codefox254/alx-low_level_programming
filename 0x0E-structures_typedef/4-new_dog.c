#include <stdlib.h>
#include "dog.h"
        /**
         * _Strlen - returns the length of the string
         * @s: the string to evaluate
         *
         * Return: The length Of The String
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
         * *_strcpy then- copies the string pointed to by src
         * This includes the term null byte (\0)
         * to buffer pointed to by dest
         * @dest: the pointer to the buffer in which we will copy the string
         * @src: is the string that will be copied
         *
         * Return: the pointer to dest
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
         * New_dog - this will create a new dog
         * @name: and name of the dog
         * @age: will be age of the dog
         * @owner: and the owner of the dog
         *
         * Return: pointer to the new dog if (Success) and NULL if  otherwise
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
