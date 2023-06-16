#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between -100 and 100
    int n = rand() % 201 - 100;

    // Print the random number
    printf("The number: %d\n", n);

    // Check if the number is positive, negative, or zero
    if (n > 0) {
        printf("is positive\n");
    } else if (n < 0) {
        printf("is negative\n");
    } else {
        printf("is zero\n");
    }

    return 0;
}

