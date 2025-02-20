#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chaines.h"

int main() {
    char chaine[] = "Hello World!";

    printf("---- %s ----\n\n", chaine);
    printf("%s                   : %d caracteres\n", chaine, compterCaractere(chaine));

    char* chaineEnDecimal = affichageEnDecimal(chaine);
    printf("%s en décimales      : %s\n", chaine, chaineEnDecimal);

    char* chaineEnMajuscules = mettreEnMajuscule(chaine);
    printf("%s en majuscules     : %s\n", chaine, chaineEnMajuscules);
    char* chaineEnMinuscules = mettreEnMinuscule(chaine);
    printf("%s en minuscules     : %s\n", chaine, chaineEnMinuscules);
    char* chaineEnMinMaj = transformerMinMaj(chaine);
    printf("%s inversant min/maj : %s\n", chaine, chaineEnMinMaj);

    char* chaineRetournee = retournerMot(chaine);
    printf("%s retourné          : %s\n", chaine, chaineRetournee);

    char* chaineSupprimee = supprimeCaractere(chaine, 'l');
    printf("%s sans 'l'          : %s\n", chaine, chaineSupprimee);
    if (estPalindrome(chaine)) {
        printf("%s est un palindrome\n", chaine);
    } else {
        printf("%s n'est pas un palindrome\n", chaine);
    }

    char chainePalindrome[] = "kayak";
    if (estPalindrome(chainePalindrome)) {
        printf("%s est un palindrome\n", chainePalindrome);
    } else {
        printf("%s n'est pas un palindrome\n", chainePalindrome);
    }


    char chaine1[] = "AAA!";
    char chaine2[] = "ZZZ!";
    char chaine3[] = "hello world!";

    int comparaison = comparerChaine(chaine, chaine1);
    if (comparaison == 0) {
        printf("%s et %s sont identiques\n", chaine, chaine1);
    } else if (comparaison < 0) {
        printf("%s < %s\n", chaine, chaine1);
    } else  {
        printf("%s > %s\n", chaine, chaine1);
    }

    comparaison = comparerChaine(chaine, chaine2);
    if (comparaison == 0) {
        printf("%s et %s sont identiques\n", chaine, chaine2);
    } else if (comparaison < 0) {
        printf("%s < %s\n", chaine, chaine2);
    } else  {
        printf("%s > %s\n", chaine, chaine2);
    }

    comparaison = comparerChaine(chaine, chaine3);
    if (comparaison == 0) {
        printf("%s et %s sont identiques\n", chaine, chaine3);
    } else if (comparaison < 0) {
        printf("%s < %s\n", chaine, chaine3);
    } else  {
        printf("%s > %s\n", chaine, chaine3);
    }

    char verbe[] = "chanter";

    conjuguer(verbe);

    // Ici, toutes les libérations de mémoire !!
    free(chaineEnDecimal);
    free(chaineEnMajuscules);
    free(chaineEnMinuscules);
    free(chaineEnMinMaj);
    free(chaineRetournee);
    free(chaineSupprimee);

    return 0;
}