#include "main.h"
#include <unistd.h>

int _print_str(char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return count;
}
