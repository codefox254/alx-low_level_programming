#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed; 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor, read_result;
    char buffer[1024];

    if (filename == NULL)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    read_result = read(file_descriptor, buffer, sizeof(buffer));
    close(file_descriptor);

    if (read_result == -1)
        return (0);

    write(STDOUT_FILENO, buffer, read_result);

    return (read_result);
}
