#!/bin/bash

# Compile each .c file into a .o file
gcc -c *.c

# Create the static library liball.a
ar -rc liball.a *.o

# Index the library for quicker access
ranlib liball.a

# Clean up by removing the .o files
rm *.o
