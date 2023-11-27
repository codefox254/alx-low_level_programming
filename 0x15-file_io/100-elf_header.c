#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_elf_header - Display information from ELF header
 * @elf_header: Pointer to the ELF header
 */
void display_elf_header(Elf64_Ehdr *elf_header) {
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf(" %02x", elf_header->e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             ");
    switch (elf_header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  Data:                              ");
    switch (elf_header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("UNIX - AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Novell - Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("UNIX - OpenBSD\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (elf_header->e_type) {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("  Entry point address:               %#lx\n", (unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point for the program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error");
        return 98;
    }

    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        perror("Error");
        close(fd);
        return 98;
    }

    if (lseek(fd, (off_t)elf_header.e_phoff, SEEK_SET) == (off_t)-1) {
        perror("Error");
        close(fd);
        return 98;
    }

    display_elf_header(&elf_header);

    close(fd);

    return 0;
}
