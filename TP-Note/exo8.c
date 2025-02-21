#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

char caractereVersMajuscule(char c)
{
    return toupper(c);
}

char* texteEnMajuscule(char* c)
{
    char* result = malloc(sizeof(char) * strlen(c)+1);
    int i = 0;
    while (c[i] != '\0')
    {
        result[i] = c[i];
        i++;
    }
    result[i] = '\0';
    return result;
}

char* couperAuPremierEspace(char* c)
{
    int count = 0;
    while (c[count] != ' ' && c[count] != '\0')
    {
        count++;
    }
    char* result = malloc(sizeof(char) * count+1);
    for (int i = 0; i < count; i++)
    {
        result[i] = c[i];
    }
    result[count] = '\0';
    return result;
}

int main(int argc, char** argv) 
{
    printf("a -> %c\n", caractereVersMajuscule('a'));
    printf("G -> %c\n", caractereVersMajuscule('G'));
    printf("! -> %c\n", caractereVersMajuscule('!'));
    printf("\n");
    printf("'Hello' -> %s\n", texteEnMajuscule("Hello"));
    printf("'World!' -> %s\n", texteEnMajuscule("World!"));
    printf("'Hello World' -> %s\n", texteEnMajuscule("Hello World"));
    printf("\n");
    printf("'Hello World' -> %s\n", couperAuPremierEspace("Hello World"));
    printf("'Polytech' -> %s\n", couperAuPremierEspace("Polytech"));
    printf("'4-3*2 = 5' -> %s\n", couperAuPremierEspace("4-3*2 = 5"));
    return 0;
}