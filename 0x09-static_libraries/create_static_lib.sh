#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
else
    echo "Compilation successful"
fi

ar -rc liball.a *.o

# Check if ar was successful
if [ $? -ne 0 ]; then
    echo "Creating library failed"
    exit 1
else
    echo "Library created successfully"
fi

ranlib liball.a


