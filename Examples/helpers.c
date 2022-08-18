#include "helpers.h"
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
        fprintf(stderr, "\x1B[31mError\x1B[0m: num_rows must be positive\n");
        return;
    }
    if (num_cols <= 0) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: num_cols must be positive\n");
        return;
    }

    if (num_rows > 1) {
        printf("[");
    }
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
    if (num_rows > 1) {
        printf("]\n");
    }
}

/**
 * Generates a random matrix
 * @param array: the array to print
 * @param length: length of the array, must be positive
 * */
void prettyPrintArray(int* array, int length) {
    if (array == NULL) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: There's no array\n");
        return;
    }
    prettyPrintMatrix(&array, 1, length);
    printf("\n");
}

/**
 * Pretty prints a linked list
 * @param head: head of the list, should not be NULL
 * */
void prettyPrintLinkedList(Node* head) {
    if (head == NULL) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: There's no list\n");
        return;
    }

    printf("[");
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) {
            printf(", ");
        }
        head = head->next;
    }
    printf("]\n");
}

/**
 * Generates a random matrix
 * @param row: number of rows, must be positive
 * @param col: number of columns, must be positive
 * @param fixed: if true, generate the same matrix every time
 * @return pointer to the matrix on the heap
 * */
int** randomMatrix(int row, int col, int fixed, int seed_offset) {
    if (!fixed) {
        srand(time(NULL) + seed_offset);
    }
    if (row <= 0) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: row must be positive\n");
        return NULL;
    }
    if (col <= 0) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: col must be positive\n");
        return NULL;
    }

    int** matrix = (int**)malloc(sizeof(int*) * row);
    if (matrix == NULL) {
        fprintf(stderr,
                "\x1B[31mError\x1B[0m: Cannot allocate any more memory");
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

/**
 * Generates a random linked list
 * @param length: length of the list
 * @param seed_offset: offset for srand(), use different integers if calling
 * this repeatedly
 * */
Node* randomLinkedList(int length, int seed_offset) {
    srand(time(NULL) + seed_offset);

    if (length <= 0) {
        fprintf(stderr, "\x1B[31mError\x1B[0m: length must be positive");
        return NULL;
    }

    Node* head = (Node*)malloc(sizeof(Node));
    Node* traversing_ptr = head;

    // Generate random inputs
    for (int i = 0; i < length; i++) {
        traversing_ptr->value = ((int)pow(-1, rand() % 2)) * (rand() % 20);
        if (i != length - 1) {
            traversing_ptr->next = (Node*)malloc(sizeof(Node));
            traversing_ptr = traversing_ptr->next;
        } else {
            traversing_ptr->next = NULL;
        }
    }

    return head;
}

/**
 * Frees a linked list on the heap
 * @param head: pointer to the list to free
 * */
void freeLinkedList(Node* head) {
    while (head != NULL) {
        Node* curr = head;
        head = head->next;
        free(curr);
    }
}
