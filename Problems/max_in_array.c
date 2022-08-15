#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

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

    return BAD;
}

int main() {
    // Driver code
    int length = 10;
    int lock_randomizer = 0;  // change this to 1 if you want a fixed matrix
    int* arr = randomMatrix(1, length, lock_randomizer, 0)[0];
    int* output = NULL;

    if (findMax(arr, 3, &output) == SAFE && output != NULL) {
        printf("%d\n", output);
    }

    return 0;
}
