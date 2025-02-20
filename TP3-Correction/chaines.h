#ifndef CHAINES_H
#define CHAINES_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compterCaractere(char* chaine);
char* affichageEnDecimal(char* chaine);
char* mettreEnMajuscule(char* chaine);
char* mettreEnMinuscule(char* chaine);
char* transformerMinMaj(char* chaine);
char* retournerMot(char* chaine);
char* supprimeCaractere(char* chaine, char caractere);
bool estPalindrome(char* chaine);
int comparerChaine(char* chaine1, char* chaine2);
void conjuguer(char* chaine);



#endif