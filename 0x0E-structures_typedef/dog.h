#ifndef DOG_H
#define DOG_H

/**
 * struct dog - This is our dog's basic information
 * @name: The name of our dog
 * @age: The age of our dog
 * @owner: The owner of our dog
 *
 * Description: This structure represents basic information about a dog.
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
