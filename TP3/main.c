#include "utils.h"
#include <stdio.h>

int main()
{
    char* text = "Hello, World!";
    printf("The length of the string '%s' is %d\n", text, compterCaractere(text));
    printf("\nIn decimal, the word 'Hello' is :\n");
    affichageEnDecimal("Hello");
    printf("\nIn maj : %s\n", mettreEnMajuscule(text));
    printf("In min : %s\n", mettreEnMinuscule(text));
    printf("In min : %s\n", transformerMinMaj(text));

    printf("\nReverting the word 'perlinpinpin' : %s\n", revertWord("perlinpinpin"));;

    printf("\nDeleting the char 'i' from 'perlinpinpin' : %s\n", deleteChar("perlinpinpin", "i"));
    printf("\nIs 'kayak' a palindrome ? %d", isPalindrome("kayak"));
    printf("\nIs 'palindrome' a palindrome ? %d\n", isPalindrome("palindrome"));
    printf("\nComparing 'toto' with 'toto' : %d\n", compareChar("toto", "toto"));
    printf("Comparing 'titi' with 'toto' : %d\n", compareChar("titi", "toto"));
    printf("Comparing 'toto' with 'titi' : %d\n", compareChar("toto", "titi"));
    conjugate();
    return 0;
}