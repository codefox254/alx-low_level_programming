#include <stdlib.h>
        #include "dog.h"
        /**
         * init_dog - this will initialize the variable of type struct dog
         * @d: then the pointer to struct dog to initialize
         * @name: the name to initialize
         * @age: and age to initialize
         * @owner: finally the owner to initialize
         */
        void init_dog(struct dog *d, char *name, float age, char *owner)
        {
                if (d == NULL)
                        d = malloc(sizeof(struct dog));
                d->name = name;
                d->age = age;
                d->owner = owner;
        }
