#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor;
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    /* Open the file for reading */
    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    /* Allocate memory for the buffer */
    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(file_descriptor);
        return (0);
    }

    /* Read from the file */
    bytes_read = read(file_descriptor, buffer, letters);
    if (bytes_read == -1)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    /* Write to the standard output */
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    /* Clean up and return the actual number of letters read and printed */
    free(buffer);
    close(file_descriptor);
    return (bytes_read);
}
