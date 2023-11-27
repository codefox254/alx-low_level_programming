#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @num_letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed; 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t num_letters)
{
    int file_descriptor;
    ssize_t num_read, num_written;
    char *buffer;

    if (!filename)
        return (0);

    file_descriptor = open(filename, O_RDONLY);

    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * num_letters);
    if (!buffer)
    {
        close(file_descriptor);
        return (0);
    }

    num_read = read(file_descriptor, buffer, num_letters);
    num_written = write(STDOUT_FILENO, buffer, num_read);

    close(file_descriptor);
    free(buffer);

    return (num_written);
}
