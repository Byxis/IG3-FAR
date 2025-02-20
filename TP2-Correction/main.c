#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

int doubler(int x) { return x * 2; }
int div2(int x) { return x / 2; }

int main() {

    Liste* liste = creer_liste();
    ajouter_debut(liste, 3);
    ajouter_debut(liste, 15);
    ajouter_fin(liste, 42);
    ajouter_fin(liste, 13);
    map(liste, doubler);
    //map(liste, div2);

    supprimer_fin(liste);

    afficher_liste(liste);



    ListeChar* liste_char = creer_liste_char();
    for (int i = 0; i < 10; i++) {
        char* nom = (char*) malloc(10 * sizeof(char));
        sprintf(nom, "Menu %d", i);
        ajouter_fin_char(liste_char, nom);
    }
    //supprimer_fin(liste_char);

    char c;
    do {
        afficher_liste_char(liste_char);
        printf("Appuyez sur + pour selectionner le prochain, ou - pour précédent. q pour quitter : ");
        scanf(" %c", &c);
        if (c == '+') {
            suivant_char(liste_char);
        } else if (c == '-') {
            precedent_char(liste_char);
        }
    } while(c != 'q');

    return 0;
}