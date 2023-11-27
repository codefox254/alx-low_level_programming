#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_exit(int code, const char *message, const char *arg) {
    dprintf(STDERR_FILENO, message, arg);
    exit(code);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        error_exit(97, "Usage: cp file_from file_to\n", "");
    }

    char *file_from = argv[1];
    char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        error_exit(98, "Error: Can't read from file %s\n", file_from);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (fd_to == -1) {
        close(fd_from);
        error_exit(99, "Error: Can't write to file %s\n", file_to);
    }

    char buffer[BUFFER_SIZE];
    ssize_t read_bytes, write_bytes;

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes == -1 || write_bytes != read_bytes) {
            close(fd_from);
            close(fd_to);
            error_exit(99, "Error: Can't write to file %s\n", file_to);
        }
    }

    if (read_bytes == -1) {
        close(fd_from);
        close(fd_to);
        error_exit(98, "Error: Can't read from file %s\n", file_from);
    }

    if (close(fd_from) == -1) {
        error_exit(100, "Error: Can't close fd %d\n", fd_from);
    }

    if (close(fd_to) == -1) {
        error_exit(100, "Error: Can't close fd %d\n", fd_to);
    }

    return 0;
}
