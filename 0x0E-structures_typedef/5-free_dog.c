#include <stdlib.h>
#include "dog.h"

/**
 * Free_dog - This frees memory allocated a struct dog
 * @d: This will struct dog to free
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

