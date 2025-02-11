#include <stdio.h>

void multiply(int *x) {
    *x *= 2;
}

int main(void) {
    int a = 5;
    printf("a = %d\n", a);
    multiply(&a);
    printf("a = %d\n", a);
    return 0;
}