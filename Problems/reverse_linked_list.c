#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helpers.h"

Node* reverseLinkedList(Node* head) {
    /**
     * Given the head to a singly linked list,
     * return a new list with reversed order
     *
     * EX.1:    4 -> 3 -> 5 -> NULL returns 5 -> 3 -> 4 -> NULL
     * EX.2:    3 -> NULL returns 3 -> NULL
     * EX.3:    NULL returns NULL
     * */

    return NULL;
}

int main() {
    int list_length = 10;

    Node* input_head = randomLinkedList(list_length, 0);
    printf("Original list:\n");
    prettyPrintLinkedList(input_head);

    Node* reversed_head = reverseLinkedList(input_head);
    printf("Reversed list:\n");
    prettyPrintLinkedList(reversed_head);

    freeLinkedList(reversed_head);

    return 0;
}