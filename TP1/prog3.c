#include <stdio.h>

void f() {
    int nchiffre[20];
    for (int i = 0 ; i < 21 ; ++i) {
        printf("nchiffre[%d]=%d\n", i, nchiffre[i]);
        nchiffre[i] = 0;
    }
}

int main (void) {
    f();
    printf("␣fini\n");
    return 0;
}