#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/**
 * create_file - Creates a file with specified content
 * @filename: The name of the file to create
 * @text_content: The text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd;
    int nletters;
    int rwr;

    if (!filename)
    {
        perror("Error: Invalid filename");
        return (-1);
    }

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (fd == -1)
    {
        perror("Error opening file");
        return (-1);
    }

    if (!text_content)
        text_content = "";

    for (nletters = 0; text_content[nletters]; nletters++)
        ;

    rwr = write(fd, text_content, nletters);

    if (rwr == -1)
    {
        perror("Error writing to file");
        close(fd);
        return (-1);
    }

    close(fd);

    return (1);
}
