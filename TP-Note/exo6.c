#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int numero;
    char caractere;
    double decimale;
} MaStructure;

typedef long long int tresLongInt;

void afficher_taille_des_donnees()
{
    printf("Taille d'un int : %d\n", sizeof(int));
    printf("Taille d'un float : %d\n", sizeof(float));
    printf("Taille d'un double : %d\n", sizeof(double));
    printf("Taille d'un char : %d\n", sizeof(char));
    printf("Taille de tresLongInt : %d\n", sizeof(tresLongInt));
    printf("Taille de MaStructure : %d\n", sizeof(MaStructure));
    printf("Taille de MaStructure* : %d\n", sizeof(MaStructure*));
}

int main(int argc, char** argv) 
{
    afficher_taille_des_donnees();
    printf("\nIl y a une difference entre la taille de MaStructure et MaStructure* car MaStructure represente la classe avec ses attributs tandis que MaStructure* represente l'adresse memoire ou se situe notre structure, la taille est donc juste celle de l'adresse");
    return 0;
}