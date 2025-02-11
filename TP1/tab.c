#include <stdio.h>
#include <stdlib.h>

int* add(int *tab, int n)
{
    int* t = (int*) malloc(2 * n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        t[i] = tab[i];
        t[2*n -i] = tab[i];
    }
    return tab;
}

int main(void)
{
    int n = 10;
    int tab[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* newTab = add(tab, n);
    return 0;
}