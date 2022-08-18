#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

/**
 * Represents a execution status
 * */
typedef enum { SAFE = 0, BAD = 1 } STATUS;

/**
 * Pretty prints a matrix, 1 row per line
 * @param matrix: the matrix to print
 * @param num_rows: number of rows
 * @param num_cols: number of columns
 * */
void prettyPrintMatrix(int** matrix, int num_rows, int num_cols);

/**
 * Generates a random matrix
 * @param array: the array to print
 * @param length: length of the array, must be positive
 * */
void prettyPrintArray(int* array, int length);

/**
 * Pretty prints a linked list
 * @param head: head of the list, should not be NULL
 * */
void prettyPrintLinkedList(Node* head);

/**
 * Generates a random matrix
 * @param row: number of rows, must be positive
 * @param col: number of columns, must be positive
 * @param fixed: if true, generate the same matrix every time
 * @return pointer to the matrix on the heap
 * */
int** randomMatrix(int row, int col, int fixed, int seed_offset);

/**
 * Generates a random linked list
 * @param length: length of the list
 * @param seed_offset: offset for srand(), use different integers if calling
 * this repeatedly
 * */
Node* randomLinkedList(int length, int seed_offset);

/**
 * Frees a linked list on the heap
 * @param head: pointer to the list to free
 * */
void freeLinkedList(Node* head);