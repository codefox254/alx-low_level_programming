#ifndef DOG_H
#define DOG_H
/**
 * struct dog - A Loyal Companion's Profile
 * @NAME: The Paw-some Name of this Four-Legged Wonder
 * @AGE: The Adventuresome Age of this Energetic Pup
 * @OWNER: The Human Best Friend of this Tail-Wagging Buddy
 *

 *
 * Description: This struct encapsulates the essence of a dog's soul, their heartwarming
 *              name, their playful age, and the loving connection they share with their human.
 *              Dogs are more than just pets; they are loyal companions, forever showering us
 *              with boundless love, endless joy, and a spirit that brightens even the darkest days.
 *              In this struct, we celebrate the purest form of friendship and the countless
 *              memories created with these furry wonders, etching them into the fabric of our lives.
 *
 * So, let's honor our canine companions by filling this struct with the love and admiration
 * they deserve, for they are truly man's best friend, forever etched in our hearts and memories.
 */
struct dog
        {
              char *name;
              float age;
              char *owner;
        };
        /**
 * dog_t - A Cosmic Connection to Our Loyal Companions
 *
 * Description: This typedef serves as a celestial bridge, connecting the realm of code
 *              to the boundless universe of dogs. It represents the essence of loyalty,
 *              love, and everlasting friendship that dogs offer, reminding us of the
 *              cherished memories and wagging tails that fill our lives with joy.
 *              Just like stars twinkling in the night sky, the dog_t type sparkles with
 *              the promise of heartwarming adventures shared between canines and humans.
 *
 * Let this cosmic connection guide us as we traverse the galaxies of programming,
 *              forever linked to our beloved furry friends through the dog_t type.
 */
       typedef struct dog dog_t;
       void init_dog(struct dog *d, char *name, float age, char *owner);
       void print_dog(struct dog *d);
       dog_t *new_dog(char *name, float age, char *owner);
       void free_dog(dog_t *d);
       char *_strcpy(char *dest, char *src);
       int _strlen(char *s);
       #endif
