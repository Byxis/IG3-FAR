#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

float doubler(float x)
{
    return 2 * x;
}

float puissance(float x, float y)
{
    return powf(x, y);
}

float puissanceI(float x, int n)
{
    float result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

int main(int argc, char** argv) 
{
    printf("Doubler :\n");
    printf("100 : %f\n", doubler(100));
    printf("89 : %f\n", doubler(89));
    printf("-25.8 : %f\n", doubler(-25.8));
    printf("0 : %f\n", doubler(0));

    
    printf("\nPuissance :\n");
    printf("2^5 : %f\n", puissance(2, 5));
    printf("74^2 : %f\n", puissance(74, 2));
    printf("2.7182^7 : %f\n", puissance(2.7182, 7));
    return 0;
}