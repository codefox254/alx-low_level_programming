#include <stdlib.h>
#include "dog.h"

/**
 * woof_init - brings a doggo to life!
 * @d: pointer to struct dog, the lucky doggo to be initialized
 * @name: the dog's unique and adorable name
 * @age: the age of the doggo in dog years (because regular years are boring!)
 * @owner: the human best friend of the doggo, who gets all the love and tail wags
 *
 * Description: This function magically brings a new doggo into existence and fills its heart with joy.
 *              Each doggo is special and deserves a unique name, so choose wisely!
 *              We measure their age in dog years because, let's face it, dogs are way cooler than humans.
 *              The owner is the one lucky human who will receive boundless love and loyalty from their new furry friend.
 *
 * So, what are you waiting for? Call this function and witness the birth of a brand new, tail-wagging companion!
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
        {
                if (d == NULL)
                        d = malloc(sizeof(struct dog));
                d->name = name;
                d->age = age;
                d->owner = owner;
        }
