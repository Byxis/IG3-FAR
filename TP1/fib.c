#include <stdio.h>
#include <stdlib.h>

int* allFib(int n)
{
    int *tab = malloc(n * sizeof(int));

    tab[0] = 0;
    tab[1] = 1;

    for(int i = 2; i < n; i++)
    {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab;
}

int main()
{
    int n = 10;    
    int *tab = allFib(n);

    for(int i = 0; i < n; i++)
    {
        printf("Value : %d\n", tab[i]);
    }

    free(tab);
    return 0;
}