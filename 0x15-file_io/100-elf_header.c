#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUF_SIZE 64

/**
 * display_error_and_exit - Display an error message to stderr and exit with status code 98.
 * @error_message: The error message to display.
 */
void display_error_and_exit(const char *error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(98);
}

/**
 * display_elf_header - Display information from the ELF header of an ELF file.
 * @filename: The name of the ELF file.
 */
void display_elf_header(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        display_error_and_exit("Error opening file");

    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
        display_error_and_exit("Error reading ELF header");

    // Check if it's a valid ELF file
    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3)
        display_error_and_exit("Not an ELF file");

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", elf_header.e_ident[i]);
    printf("\n");
    
    printf("  Class:                             %s\n", (elf_header.e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", (elf_header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", elf_header.e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %d\n", elf_header.e_type);
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header.e_entry);

    close(fd);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    display_elf_header(argv[1]);

    return 0;
}
