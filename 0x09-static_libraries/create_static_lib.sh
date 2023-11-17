#!/bin/bash

# Compile each .c file to a .o file
gcc -Wall -pedantic -Werror -Wextra -c *.c

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

# Create the static library liball.a
ar -rc liball.a *.o

# Check if library creation was successful
if [ $? -ne 0 ]; then
    echo "Library creation failed. Exiting."
    exit 1
fi

# Index the library
ranlib liball.a

# Check if indexing was successful
if [ $? -ne 0 ]; then
    echo "Library indexing failed. Exiting."
    exit 1
fi

echo "Script executed successfully."
