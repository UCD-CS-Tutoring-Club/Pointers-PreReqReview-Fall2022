#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

typedef enum { SAFE = 0, BAD = 1 } STATUS;

STATUS findMax(int* array, int length, int* output) {
    /**
     * Given an array of integers, find the maximum value
     *
     * you can assume that @param array will not have numbers less than
     * -99999999
     * - or better, use the INT_MIN equivalent on your system
     * return BAD as the status if something is wrong with the params
     * Put the result in @param output
     * */

    if (array == NULL || length <= 0) {
        return BAD;
    }

    int curr_max = INT32_MIN;
    for (int i = 0; i < length; i++) {
        if (array[i] > curr_max) {
            curr_max = array[i];
        }
    }

    *output = curr_max;
    return SAFE;
}

int main() {
    int length = 10;
    int lock_randomizer = 0; // change this to 1 if you want a fixed matrix
    int* arr = randomMatrix(1, length, lock_randomizer, 0)[0];
    int output;

    printf("Generated Array:\n");
    prettyPrintArray(arr, length);

    if (findMax(arr, length, &output) == SAFE) {
        printf("%d\n", output);
    } else {
        printf("Something bad happened.\n");
    }

    return 0;
}
