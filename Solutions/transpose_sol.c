#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helpers.h"

int** transpose(int** A, int num_rows, int num_cols) {
    /**
     * The transpose, B, of a matrix A has the property:
     * A[i][j] == B[j][i] where i, j are positive integers
     *
     * Write a C program to find a transpose of a 2D matrix,
     * you can assume that inputs are sanitized
     * */

    int** transposed_A = (int**)malloc(sizeof(int*) * num_cols);

    for (int row = 0; row < num_cols; row++) {
        transposed_A[row] = (int*)malloc(sizeof(int) * num_rows);
        for (int col = 0; col < num_rows; col++) {
            transposed_A[row][col] = A[col][row];
        }
    }

    return transposed_A;
}

int main() {
    int row = 2;
    int col = 2;
    int lock_randomizer = 0;  // change this to 1 if you want a fixed matrix

    int** matrix = randomMatrix(row, col, lock_randomizer, 0);
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

    int num = 10;
    int* ptr = &num;
    int value = *ptr;

    return 0;
}