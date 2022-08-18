/**
 * Pointers: Example 3
 *
 * Given an array int* arr with values in it, insert a number at the end of the
 * array using realloc()
 *
 * Topics: using realloc safely, reference to pointers, dereferencing
 * */

#include <stdio.h>
#include "helpers.h"

STATUS pushBack(int** array_ref, int* length_ref, int new_value) {
    if (array_ref == NULL) {
        return BAD;
    }

    int* new_array = realloc(*array_ref, sizeof(int) * (*length_ref + 1));

    if (new_array != NULL) {
        *array_ref = new_array;
        (*array_ref)[*length_ref] = new_value;
        *length_ref += 1;
        return SAFE;
    }

    return BAD;
}

int main() {
    // Driver code
    int length = 10;
    int lock_randomizer = 0;  // change this to 1 if you want a fixed matrix
    int* arr = randomMatrix(1, length, lock_randomizer, 0)[0];

    for (int i = 0; i < 100; i++) {
        pushBack(&arr, &length, i + 1);
    }

    prettyPrintArray(arr, length);

    return 0;
}
