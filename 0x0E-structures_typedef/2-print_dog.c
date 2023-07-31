#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - brings a dog's delightful details to life
 * @d: the majestic struct dog to be showcased
 *
 * Description: This function prints a dog's delightful details,
 *              including their name, age, and owner.
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
