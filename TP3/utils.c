#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compterCaractere(const char* chaine)
{
    int i = 0;
    while (chaine[i] != '\0')
    {
        i++;
    }
    return i;
}

void affichageEnDecimal(const char* mot)
{
    int i = 0;
    while (mot[i] != '\0')
    {
        printf("%i ", mot[i]);
        i++;
    }
    printf("\n");
}

char* mettreEnMajuscule(const char* mot)
{
    int i = 0;
    char* maj = (char*)malloc(sizeof(char)*compterCaractere(mot));
    while (mot[i] != '\0')
    {
        maj[i] = toupper(mot[i]);
        i++;
    }
    return maj;
}

char* mettreEnMinuscule(const char* mot)
{
    int i = 0;
    char* maj = (char*)malloc(sizeof(char)*compterCaractere(mot));
    while (mot[i] != '\0')
    {
        maj[i] = tolower(mot[i]);
        i++;
    }
    return maj;
}

char* transformerMinMaj(const char* mot)
{
    int i = 0;
    char* maj = (char*)malloc(sizeof(char)*compterCaractere(mot));
    while (mot[i] != '\0')
    {
        if(isupper(mot[i]))
            maj[i] = tolower(mot[i]);
        else
            maj[i] = toupper(mot[i]);
        i++;
    }
    return maj;
}

char* revertWord(const char* mot)
{
    int count = compterCaractere(mot);
    char* rev = (char*)malloc(sizeof(char)*count);
    for (int i = 0; i < count; i++)
    {
        rev[i] = mot[count-i-1];
    }
    return rev;
}

char* deleteChar(const char* mot, const char* c)
{
    int i = 0;
    int count = 0;

    while (mot[i] != '\0')
    {
        if(mot[i] != c[0])
            count++;
        i++;
    }

    char* new = (char*) malloc(sizeof(char) * count+1);
    i = 0;
    int j = 0;

    while (mot[i] != '\0')
    {
        if(mot[i] != c[0])
        {
            new[j] = mot[i];
            j++;
        }
        i++;
    }
    return new;
}

int isPalindrome(const char* mot)
{
    int i = 0;
    int res = 0;
    char* rev = revertWord(mot);

    while (mot[i] != '\0' && res != -1)
    {
        if (mot[i] != rev[i])
            res = -1;
        i++;
    }
    return res;
}


int compareChar(const char* first, const char* second)
{
    int count = 0;
    int i = 0;
    while (first[i] != '\0' && second[i] != '\0')
    {
        count += second[i]-first[i];
        i++;
    }
    return count;
}

void conjugate()
{
    char verbe[100]; 
    int count = 0;
    while(verbe[count-1] != 'r' && verbe[count-2] != 'e')
    {
        printf("Entrer un verbe du premier groupe : ");
        scanf("%99s", verbe);
        count = compterCaractere(verbe);
    }
    char* base =  (char*) malloc(sizeof(char) * count - 1);
    for (int i =0; i < count-2; i++)
    {
        base[i] = verbe[i];
    }

    printf(" \nJe %se\n",base);
    printf("Tu %ses\n",base);
    printf("Il/elle/on %se\n",base);
    printf("Nous %sons\n",base);
    printf("Vous %sez\n",base);
    printf("Ils/elles %sent\n",base);
}