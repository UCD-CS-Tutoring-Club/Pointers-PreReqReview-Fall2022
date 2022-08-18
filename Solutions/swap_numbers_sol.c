#include <stdio.h>
#include <stdlib.h>

void cyclicSwap(int* a, int* b, int* c) {
    if (a == NULL || b == NULL || c == NULL) {
        fprintf(stderr,
                "\x1B[31mError\x1B[0m: None of the numbers should be NULL.");
        return;
    }

    int val_a = *a;
    int val_b = *b;
    int val_c = *c;
    *b = val_a;
    *c = val_b;
    *a = val_c;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    cyclicSwap(&a, &b, &c);

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);

    return 0;
}