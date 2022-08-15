/**
 * Pointers: Example 2
 *
 * Suppose we want to have multiple streets.
 * Each street has some houses, and each house has multiple stories.
 *
 * How can we put the number 15 on a given floor of a given house on a given
 * street?
 * - Declare a 3D array and put number 15 in one of the locations.
 *
 * Topics: malloc in for loops
 * */

#include <stdio.h>

int*** malloc3DArray(int num_streets, int num_houses, int num_floors) {
    /**
     * Write your code below
     * */

    return NULL;
}

int main() {
    int*** street = malloc3DArray(2, 3, 4);
    if (street != NULL) {
        street[0][1][2] = 15;
    }

    return 0;
}
