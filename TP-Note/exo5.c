#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void echanger(float* x, float* y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}

void normaliser_vecteur(float* x, float* y)
{
    float norm = sqrtf((*x) * (*x) + (*y) * (*y));
    *x /= norm;
    *y /= norm;
}

int main(int argc, char** argv) 
{
    float x = 4.5;
    float y = 1.3;
    printf("Valeur initiale : \nx = %f, y = %f\n", x, y);
    echanger(&x, &y);
    printf("\nApres echange : \nx = %f, y = %f\n", x, y);
    normaliser_vecteur(&x, &y);
    printf("\nApres normalisation : \nx = %f, y = %f\n", x, y);
    printf("x^2 + y^2 = %f", (x*x + y*y));

    return 0;
}