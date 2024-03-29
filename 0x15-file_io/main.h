#ifndef __MAIN_H__
#define __MAIN_H__

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void display_error_and_exit(const char *error_message);
void display_elf_header(const char *filename);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);

#endif
