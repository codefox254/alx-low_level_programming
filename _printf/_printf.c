#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char ch;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr != '%')
        {
            write(1, ptr, 1);
            count++;
        }
        else
        {
            ptr++;

            switch (*ptr)
            {
            case 'c':
                ch = va_arg(args, int);
                write(1, &ch, 1);
                count++;
                break;
            case 's':
                count += _print_str(va_arg(args, char *));
                break;
            case '%':
                write(1, "%", 1);
                count++;
                break;
            default:
                write(1, "%", 1);
                write(1, &(*ptr), 1);
                count += 2;
                break;
            }
        }
    }

    va_end(args);

    return count;
}
