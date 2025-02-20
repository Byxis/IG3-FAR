#include "listes.h"

#include <stdio.h>
#include <stdlib.h>


Liste* creer_liste() {
    Liste* nouvelle_liste = (Liste*) malloc(sizeof(Liste));
    nouvelle_liste->racine = NULL;
    nouvelle_liste->courant = NULL;
    return nouvelle_liste;
}
bool liste_est_vide(Liste* liste) {
    return liste->racine == NULL;
}
void ajouter_debut(Liste* liste, int valeur) {
    Noeud* noeud = (Noeud*) malloc(sizeof(Noeud));
    noeud->valeur = valeur;

    noeud->suivant = liste->racine;
    if (!liste_est_vide(liste)) {
        liste->racine->precedent = noeud;
    }
    liste->racine = noeud;
}
Noeud* suivant(Liste* liste) { 
    Noeud* noeudSuivant = liste->courant->suivant;
    liste->courant = noeudSuivant;
    return noeudSuivant;
}
void supprimer_debut(Liste* liste) {
    Noeud* racine = liste->racine;
    liste->racine = racine->suivant;
    free(racine);
}
void ajouter_fin(Liste* liste, int valeur) {
    Noeud* nouveau = (Noeud*) malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    Noeud* noeudFinal = liste->racine;

    while(noeudFinal->suivant != NULL) {
        noeudFinal = noeudFinal->suivant;
    }

    noeudFinal->suivant = nouveau;
    nouveau->precedent = noeudFinal;
}
void supprimer_fin(Liste* liste) {
    if (liste_est_vide(liste)) {
        return;
    }
    Noeud* noeudFinal = liste->racine;
    while(noeudFinal->suivant != NULL) {
        noeudFinal = noeudFinal->suivant;
    }
    noeudFinal->precedent->suivant = NULL;
    free(noeudFinal);
}

void afficher_liste(Liste* liste) {
    for (Noeud* n = liste->racine; n != NULL; n = n->suivant) {
        printf("%d\n", n->valeur);
    }
}

// Exo 2
void map(Liste* liste, int (*fonction)(int)) {
    Noeud* noeud = liste->racine;
    while (noeud != NULL) {
        noeud->valeur = fonction(noeud->valeur);
        noeud = noeud->suivant;
    }
}






// Exo 3



ListeChar* creer_liste_char() {
    ListeChar* nouvelle_liste = (ListeChar*) malloc(sizeof(ListeChar));
    nouvelle_liste->racine = NULL;
    nouvelle_liste->courant = NULL;
    return nouvelle_liste;
}
bool liste_est_vide_char(ListeChar* liste) {
    return liste->racine == NULL;
}
void ajouter_debut_char(ListeChar* liste, char* valeur) {
    NoeudChar* noeud = (NoeudChar*) malloc(sizeof(NoeudChar));
    noeud->valeur = valeur;

    noeud->suivant = liste->racine;
    if (!liste_est_vide_char(liste)) {
        liste->racine->precedent = noeud;
    }
    liste->racine = noeud;
}
NoeudChar* suivant_char(ListeChar* liste) { 
    if (liste->courant->suivant == NULL)
        return liste->courant;
    NoeudChar* noeudSuivant = liste->courant->suivant;
    liste->courant = noeudSuivant;
    return noeudSuivant;
}
NoeudChar* precedent_char(ListeChar* liste) { 
    if (liste->courant->precedent == NULL)
        return liste->courant;
    NoeudChar* noeudPrecedent = liste->courant->precedent;
    liste->courant = noeudPrecedent;
    return noeudPrecedent;
}
void supprimer_debut_char(ListeChar* liste) {
    NoeudChar* racine = liste->racine;
    liste->racine = racine->suivant;
    free(racine);
}
void ajouter_fin_char(ListeChar* liste, char* valeur) {
    NoeudChar* nouveau = (NoeudChar*) malloc(sizeof(NoeudChar));
    nouveau->valeur = valeur;
    if (liste->racine == NULL) {
        liste->racine = nouveau;
        return;
    }

    NoeudChar* noeudFinal = liste->racine;

    while(noeudFinal->suivant != NULL) {
        noeudFinal = noeudFinal->suivant;
    }

    noeudFinal->suivant = nouveau;
    nouveau->precedent = noeudFinal;
}
void supprimer_fin_char(ListeChar* liste) {
    if (liste_est_vide_char(liste)) {
        return;
    }
    NoeudChar* noeudFinal = liste->racine;
    while(noeudFinal->suivant != NULL) {
        noeudFinal = noeudFinal->suivant;
    }
    noeudFinal->precedent->suivant = NULL;
    free(noeudFinal);
}

void afficher_liste_char(ListeChar* liste) {
    if (liste->courant == NULL) {
        liste->courant = liste->racine;
    }
    for (NoeudChar* n = liste->racine; n != NULL; n = n->suivant) {
        if (n == liste->courant) {
            printf("-> %s\n", n->valeur);
        } else {
            printf("   %s\n", n->valeur);
        }
    }
}
void map_char(ListeChar* liste, char* (*fonction)(char*)) {
    NoeudChar* noeud = liste->racine;
    while (noeud != NULL) {
        noeud->valeur = fonction(noeud->valeur);
        noeud = noeud->suivant;
    }
}