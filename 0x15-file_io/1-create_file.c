#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to be created.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 *
 * Description: The file is created with read and write permissions only
 * for the owner (0600). If filename is NULL or if an error occurs during
 * file creation or writing, -1 is returned.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
