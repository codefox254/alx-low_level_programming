#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
    if (filename == NULL)
        return -1;

    int fd = open(filename, O_WRONLY | O_APPEND);

    if (fd == -1)
        return -1;  // Unable to open the file

    if (text_content == NULL)
    {
        close(fd);
        return 1;  // File exists, but no content to append
    }

    ssize_t nletters = 0;
    for (; text_content[nletters]; nletters++)
        ;

    ssize_t rwr = write(fd, text_content, nletters);

    close(fd);

    if (rwr == -1)
        return -1;  // Error writing to the file

    return 1;  // Success
}
