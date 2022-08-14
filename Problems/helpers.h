#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Pretty prints a matrix, 1 row per line
 * @param matrix: the matrix to print
 * @param num_rows: number of rows
 * @param num_cols: number of columns
 * */
void prettyPrintMatrix(int** matrix, int num_rows, int num_cols) {
    if (matrix == NULL) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: There's no matrix\n");
        return;
    }
    if (num_rows <= 0) {
        printf("\x1B[31mError\x1B[0m: num_rows must be positive\n");
        return;
    }
    if (num_cols <= 0) {
        printf("\x1B[31mError\x1B[0m: num_cols must be positive\n");
        return;
    }

    printf("[");
    for (int row = 0; row < num_rows; row++) {
        if (row != 0) {
            printf(" ");
        }
        printf("[");
        for (int col = 0; col < num_cols; col++) {
            printf("%d", matrix[row][col]);
            if (col != num_cols - 1) {
                printf(",\t");
            }
        }
        printf("]");
        if (row != num_rows - 1) {
            printf(",\n");
        }
    }
    printf("]\n");
}

/**
 * Generates a random matrix
 * @param array: the array to print
 * @param length: length of the array, must be positive
 * */
void prettyPrintArray(int* array, int length) {
    if (array == NULL) {
        printf("\x1B[31mError\x1B[0m: There's no array\n");
        return;
    }
    prettyPrintMatrix(&array, 1, length);
}
/**
 * Generates a random matrix
 * @param  row: number of rows, must be positive
 * @param  col: number of columns, must be positive
 * @param  fixed: if true, generate the same matrix every time
 * @return pointer to the matrix on the heap
 * */
int** randomMatrix(int row, int col, int fixed, int seed_offset) {
    if (!fixed) {
        srand(time(NULL) + seed_offset);
    }
    if (row <= 0) {
        printf("\x1B[31mError\x1B[0m: row must be positive\n");
        return NULL;
    }
    if (col <= 0) {
        printf("\x1B[31mError\x1B[0m: col must be positive\n");
        return NULL;
    }

    int** matrix = (int**)malloc(sizeof(int*) * row);
    if (matrix == NULL) {
        printf("\x1B[31mError\x1B[0m: Cannot allocate any more memory");
        return NULL;
    }

    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            // random number in [-19, 19]
            matrix[i][j] = ((int)pow(-1, rand() % 2)) * (rand() % 20);
        }
    }

    return matrix;
}