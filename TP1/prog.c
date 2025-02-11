#include <stdio.h>
#include <limits.h>

int main (int argc, char** argv) {
    short x = 1;
    while (x >= 1){
        printf("x = %d\n", x);
        x = x + 1;
    }
    printf("max : %d, min : %d\n", SHRT_MAX, SHRT_MIN);
    printf("max : %d, min : %d\n", INT_MAX, INT_MIN);
    printf("max : %d, min : %d\n", CHAR_MAX, CHAR_MIN);
    return 0;
}