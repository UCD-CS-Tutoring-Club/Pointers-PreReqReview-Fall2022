#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Pretty prints a matrix, 1 row per line
 * @param  {int**} matrix : the matrix to print
 * @param  {int} num_rows : number of rows
 * @param  {int} num_cols : number of columns
 */
void prettyPrintMatrix(int** matrix, int num_rows, int num_cols) {
    if (matrix == NULL) {
        printf("there's no matrix");
        return;
    }
    if (num_rows <= 0) {
        printf("row must be positive");
        return;
    }
    if (num_cols <= 0) {
        printf("col must be positive");
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
                printf(", ");
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
 * @param  {int} row   : number of rows, must be positive
 * @param  {int} col   : number of columns, must be positive
 * @param  {int} fixed : if true, generate the same matrix every time
 * @return {int**}     : pointer to the matrix on the heap
 */
int** randomMatrix(int row, int col, int fixed) {
    if (!fixed) {
        srand(time(NULL));
    }
    if (row <= 0) {
        printf("row must be positive");
        return NULL;
    }
    if (col <= 0) {
        printf("col must be positive");
        return NULL;
    }

    int** matrix = (int**)malloc(sizeof(int*) * row);
    if (matrix == NULL) {
        printf("Cannot allocate any more memory");
        return NULL;
    }

    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            // random number in [0, 19]
            matrix[i][j] = rand() % 20;
        }
    }

    return matrix;
}