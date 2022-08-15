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
    if (v1 == NULL || v2 == NULL) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: Neither array should be NULL\n");
        return NULL;
    }

    if (v1_len <= 0 || v2_len <= 0) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: Invalid lengths\n");
        return NULL;
    }

    if (v1_len != v2_len) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: Arrays must have the same size\n");
        return NULL;
    }

    int* output = (int*)malloc(sizeof(int) * v1_len);

    for (int i = 0; i < v1_len; i++) {
        output[i] = v1[i] * v2[i];
    }

    return output;
}

int main() {
    int length = 10;
    int lock_randomizer = 0;  // change this to 1 if you want fixed arrays

    int* a = randomMatrix(1, length, lock_randomizer, 0)[0];
    int* b = randomMatrix(1, length, lock_randomizer, 1000000)[0];
    int* dot_product = dotProduct(a, length, b, length);

    if (dot_product != NULL) {
        printf("Generated a = ");
        prettyPrintArray(a, length);

        printf("Generated b = ");
        prettyPrintArray(b, length);
        
        printf("Dot product = ");
        prettyPrintArray(dot_product, length);
    }

    return 0;
}