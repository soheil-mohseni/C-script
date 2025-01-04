#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ITERATIONS 100000000 // Number of iterations for performance testing

int main() {
    // String literal example with pointer
    char *pointerStr = "example2.json";

    // String array example
    char arrayStr[] = "example2.json";

    // Memory size comparison
    printf("Size of pointer: %zu bytes\n", sizeof(pointerStr));
    printf("Size of array: %zu bytes\n", sizeof(arrayStr));
    printf("Actual string length: %zu bytes (excluding null terminator)\n", strlen(pointerStr));

    // Performance comparison
    clock_t start, end;

    // Pointer access performance
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        volatile char c = pointerStr[0]; // Access first character (prevent optimization)
    }
    end = clock();
    printf("Pointer access time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Array access performance
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        volatile char c = arrayStr[0]; // Access first character (prevent optimization)
    }
    end = clock();
    printf("Array access time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Array modification test (pointer cannot be modified)
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        arrayStr[0] = 'X'; // Modify first character
        arrayStr[0] = 'e'; // Restore original character
    }
    end = clock();
    printf("Array modification time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Attempting modification via pointer (commented because it's unsafe)
    // pointerStr[0] = 'X'; // Undefined behavior

    return 0;
}
