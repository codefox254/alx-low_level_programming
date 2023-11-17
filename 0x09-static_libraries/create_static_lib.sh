#!/bin/bash

# Compile each .c file to a .o file
gcc -Wall -pedantic -Werror -Wextra -c *.c

# Create the static library liball.a
ar -rc liball.a *.o

# Index the library
ranlib liball.a
