#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints information about the struct dog
 * @d: struct dog to print
 *
 * Description: If the struct dog is NULL, nothing is printed. If the name
 * or owner of the struct dog is NULL, it is printed as "(nil)".
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
