
#include <stdio.h>
#include <stdlib.h>

typedef enum { SAFE = 0, BAD = 1 } STATUS;

STATUS findMax(int* array, int length, int* output) {
    /**
     * Given an array of integers, find the maximum value
     * 
     * you can assume that array will not have numbers less than -99999999
     * - or better, use the INT_MIN equivalent on your system
     * 
     * return BAD as the status if something is wrong with the params
     * */

    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }

    return BAD;
}

int main() {
    // Driver code
    int* a = (int[]){1, 2, 3};

    int output;

    if (findMax(a, 3, &output) == SAFE) {
        printf("%d\n", output);
    }

    return 0;
}
