#ifndef __MAIN_H__
#define __MAIN_H__

#include <elf.h>

void display_error_and_exit(const char *error_message);
void display_elf_header(const char *filename);

#endif
