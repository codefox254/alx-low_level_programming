#!/bin/bash

# Compile the C code into a dynamic library
gcc -Wall -Werror -fPIC -shared -o 100-operations.so 100-operations.c

