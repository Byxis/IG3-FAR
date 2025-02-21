#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

void appliquer(int* array, int size, int (*func)(int))
{
    for(int i = 0; i < size; i++)
    {
        array[i] = func(array[i]);
    }
}

int doubler(int x)
{
    return 2 * x;
}

int auCarre(int x)
{
    return x * x;
}

int main(int argc, char** argv) 
{
    int nb;
    printf("Choisir la taille du tableau : ");
    scanf("%d", &nb);
    int* tab = malloc(sizeof(int) * nb);
    for (int i = 0; i < nb; i++)
    {
        tab[i] = (i+1);
    }

    printf("\nVoici le tableau cree :\n");
    for (int i = 0; i < nb; i++)
    {
        printf("%i, tab[i]=%i\n", i, tab[i]);
    }

    printf("\nAppliquons la fonction doubler a ce tableau :\n");
    appliquer(tab, nb, doubler);
    for (int i = 0; i < nb; i++)
    {
        printf("%i, tab[i]=%i\n", i, tab[i]);
    }
    printf("\nAppliquons la fonction auCarre a ce tableau :\n");
    appliquer(tab, nb, auCarre);
    for (int i = 0; i < nb; i++)
    {
        printf("%i, tab[i]=%i\n", i, tab[i]);
    }
        
    return 0;
}