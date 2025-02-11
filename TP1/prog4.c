#include <stdio.h>

void f(){
    int nchiffre[20];
    int i = 1010;
    printf("i=%d\n", nchiffre[-1]);
}

void g() {
    int i = 1010;
    int nchiffre[20];
    printf("i=%d\n", nchiffre[-1]);
}

int main(void) {
    f();
    g();
    printf("␣ fini\n");
    return 0;
}
