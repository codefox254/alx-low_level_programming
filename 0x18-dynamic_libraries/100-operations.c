#include <stdio.h>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int sub(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int mul(int a, int b) {
    return a * b;
}

// Function to divide two integers (integer division)
int div(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        return 0; // You may want to handle division by zero differently
    }
    return a / b;
}

// Function to calculate the remainder of the division of two integers
int mod(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Modulo by zero\n");
        return 0; // You may want to handle modulo by zero differently
    }
    return a % b;
}

