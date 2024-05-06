#ifndef SEARCH_ALGOS_H_UNIQUE_COMMENTS
#define SEARCH_ALGOS_H_UNIQUE_COMMENTS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_ALGOS_H_UNIQUE_COMMENTS */

