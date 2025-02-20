#ifndef LISTES_H
#define LISTES_H

#include <stddef.h>
#include <stdbool.h>


// Exo 1

typedef struct NoeudStruct {
    int valeur;
    struct NoeudStruct* precedent;
    struct NoeudStruct* suivant;
} Noeud;

typedef struct {
    Noeud* racine;
    Noeud* courant;
} Liste;


Liste* creer_liste();
bool liste_est_vide(Liste* liste);
void ajouter_debut(Liste* liste, int valeur);
Noeud* suivant(Liste* liste);
void supprimer_debut(Liste* liste);
void ajouter_fin(Liste* liste, int valeur);
void supprimer_fin(Liste* liste);
void afficher_liste(Liste* liste);



// Exo 2
void map(Liste* liste, int (*fonction)(int));





// Exo 3

typedef struct NoeudCharStruct {
    char* valeur;
    struct NoeudCharStruct* precedent;
    struct NoeudCharStruct* suivant;
} NoeudChar;

typedef struct {
    NoeudChar* racine;
    NoeudChar* courant;
} ListeChar;


ListeChar* creer_liste_char();
bool liste_est_vide_char(ListeChar* liste);
void ajouter_debut_char(ListeChar* liste, char* valeur);
NoeudChar* suivant_char(ListeChar* liste);
NoeudChar* precedent_char(ListeChar* liste);
void supprimer_debut_char(ListeChar* liste);
void ajouter_fin_char(ListeChar* liste, char* valeur);
void supprimer_fin_char(ListeChar* liste);
void afficher_liste_char(ListeChar* liste);
void map_char_char(ListeChar* liste, char* (*fonction)(char*));

#endif