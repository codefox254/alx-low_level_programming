#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_elf_header(const char *filename);
int read_elf_header(int fd, Elf64_Ehdr *elf_header);

#endif
