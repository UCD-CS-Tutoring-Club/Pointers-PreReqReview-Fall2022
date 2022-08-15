#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helpers.h"

int** transpose(int** A, int num_rows, int num_cols) {
    /**
     * The transpose, B, of a matrix A has the property:
     * A[i][j] == B[j][i]
     *
     * Write a C program to find a transpose of a 2D matrix,
     * You can assume that the inputs are valid
     * */

    return NULL;
}

STATUS deleteMatrix(int** matrix, int num_rows, int num_cols) {
    /**
     * Implement a function that correctly frees up space allocated for a matrix
     * You can assume that the inputs are valid
     * */

    return BAD;
}

int main() {
    int row = 3;
    int col = 4;

    int** matrix = randomMatrix(row, col, 1, 0);
    if (matrix != NULL) {
        prettyPrintMatrix(matrix, row, col);
        printf("Try to transpose...\n");
        int** tranposed_matrix = transpose(matrix, row, col);
        prettyPrintMatrix(tranposed_matrix, col, row);
    }

    if (deleteMatrix(matrix, row, col) == SAFE) {
        printf("Matrix deleted!\n");
    }

    return 0;
}