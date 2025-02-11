#ifndef UTILS_H
#define UTILS_H

int compterCaractere(const char *chaine);
void affichageEnDecimal(const char *mot);
char* mettreEnMajuscule(const char* mot);
char* mettreEnMinuscule(const char* mot);
char* transformerMinMaj(const char* mot);
char* revertWord(const char* mot);
char* deleteChar(const char* mot, const char* c);
int isPalindrome(const char* mot);
int compareChar(const char* first, const char* second);
void conjugate();

#endif