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
     * you can assume that inputs are sanitized
     * */

    return NULL;
}

int main() {
    // rand() initialization
    // remove this line if you want constant inputs
    srand(time(NULL));
    int row = 3;
    int col = 4;

    int** matrix = randomMatrix(row, col, 1);
    if (matrix != NULL) {
        prettyPrintMatrix(matrix, row, col);
        printf("Try to transpose...\n");
        int** tranposed_matrix = transpose(matrix, row, col);
        prettyPrintMatrix(tranposed_matrix, col, row);
    }

    // Clean everything up
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}