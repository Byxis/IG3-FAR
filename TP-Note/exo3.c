#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>


int main(int argc, char** argv) 
{
    printf("'argc' signifie argument count, donc le nombre d'arguments qui a utilise l'utilisateur pour sa commande.\n");
    printf("'argv' signifie argument vector, donc une liste des différents arguments.\n");
    
    printf("Taille de l'argument actuel : %d\n\n", argc);
    printf("Les differents arguments :\n");
    for(int i = 0; i < argc; i++)
    {
        printf(argv[i]);
        printf("\n");
    }
    return 0;
}