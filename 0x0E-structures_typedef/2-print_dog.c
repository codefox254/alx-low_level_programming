#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * unleash_happiness - sets pure joy free by printing a dog's information
 * @d: the majestic struct dog to be showcased
 *
 * Description: This function is like opening a treasure chest filled with happiness.
 *              When you call it, a dog's delightful details come to life on your screen.
 *              Witness the magic as their name, age, and owner are revealed in all their glory!
 *              It's not just any information; it's a symphony of wagging tails, floppy ears,
 *              and unconditional love, perfectly encapsulated in a struct.
 *
 * So go ahead, summon this function and let the world experience the sheer bliss of dogs!
 * But be warned, you might end up with an uncontrollable urge to pet every dog you see!
 */
void print_dog(struct dog *d)
    {
                if (d == NULL)
                        return;
                if (d->name == NULL)
                        d->name = "(nil)";
                if (d->owner == NULL)
                        d->owner = "(nil)";
                printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
   }
