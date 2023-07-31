#include <stdlib.h>
#include "dog.h"
/**
 * cosmic_freedom - releases the cosmic doggo's spirit from its earthly bonds
 * @d: the cosmic doggo whose memory needs to be set free
 *
 * Description: This cosmic function holds the key to liberate a doggo's spirit,
 *              releasing it from the shackles of earthly memory.
 *              When called, it gracefully frees the memory allocated for the
 *              cosmic doggo's name and owner, ensuring they return to the cosmic
 *              void from whence they came, ready to be reborn in the stars.
 *
 * So, bid farewell to the cosmic doggo, as it ascends to the celestial realms
 * where its memory becomes one with the cosmos, forever remembered in the fabric
 * of the universe.
 */
void cosmic_freedom(dog_t *d)
{
    if (d)
    {
        free(d->name);
        free(d->owner);
        free(d);
    }
}

