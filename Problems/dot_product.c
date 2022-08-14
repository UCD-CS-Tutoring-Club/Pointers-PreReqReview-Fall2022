/**
 * The dot product of 2 vectors v1, v2 is defined as:
 * v3[i] = v1[i] * v2[i]
 * where v3 is the result vector
 *
 * Write a C function that calculates the dot product of 2 vectors
 * Then provide the driver code that prints the output array
 * */

#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int* dotProduct(int* v1, int v1_len, int* v2, int v2_len) {
    /**
     * Provide the necessary checks here to ensure
     * that a dot product is computable between v1 and v2
     *
     * Write your implementation below
     * */

    return (int*)malloc(sizeof(int));
}

int main() {
    int length = 10;
    int lock_randomizer = 0;  // change this to 1 if you want fixed arrays

    int* a = randomMatrix(1, length, lock_randomizer, 0)[0];
    int* b = randomMatrix(1, length, lock_randomizer, 1000000)[0];

    prettyPrintArray(a, length);
    prettyPrintArray(b, length);

    // Delete this comment and write your driver code below

    return 0;
}