#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>


int main(int argc, char** argv) 
{
    int x = 42;
    printf("x : %d \n", x);
    float y = 3.1415;
    printf("y : %f\n", y);
    float z = x * y;
    printf("z : %f\n", z);
    printf("\nUn des problemes de faire 'char ma_variable = x*y;' est que x*y ne renvoie pas un char mais un float, donc ce n'est pas compatible.");

    return 0;
}