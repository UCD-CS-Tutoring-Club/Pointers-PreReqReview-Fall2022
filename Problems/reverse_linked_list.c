#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

Node* reverseLinkedList(Node* head) {
    /**
     * Given the head to a singly linked list,
     * return a new list with reversed order
     *
     * EX.1:    4 -> 3 -> 5 -> NULL returns 5 -> 3 -> 4 -> NULL
     * EX.2:    3 -> NULL returns 3
     * EX.3:    NULL returns NULL
     * */

    return head;
}

int main() {
    // initialize rand()
    srand(time(NULL));

    int list_length = 5;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* traversing_ptr = head;

    // Generate random inputs
    for (int i = 0; i < list_length; i++) {
        traversing_ptr->value = ((int)pow(-1, rand() % 2)) * (rand() % 20);
        if (i != list_length - 1) {
            traversing_ptr->next = (Node*)malloc(sizeof(Node));
            traversing_ptr = traversing_ptr->next;
        } else {
            traversing_ptr->next = NULL;
        }
    }

    // Reset traversing ptr
    traversing_ptr = head;

    printf("Original list:\n");
    while (traversing_ptr != NULL) {
        printf("%d\n", traversing_ptr->value);
        traversing_ptr = traversing_ptr->next;
    }

    printf("Reversed list:\n");
    Node* new_list = reverseLinkedList(head);

    // Reset traversing ptr
    traversing_ptr = new_list;
    while (traversing_ptr != NULL) {
        printf("%d\n", traversing_ptr->value);
        traversing_ptr = traversing_ptr->next;
    }

    return 0;
}