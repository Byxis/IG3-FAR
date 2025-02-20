//
// Created by Alexis on 07/02/2025.
//

#ifndef CHAINEDLIST_H
#define CHAINEDLIST_H

typedef struct node
{
    int val;
    struct node *next;
} Node;

typedef struct List
{
    int size;
    Node *first;
    Node *curr;
} List;


List* creer_liste(int val);
int liste_est_vide(List *c);
void ajouter_debut(List *c, int val);
void afficher_liste(List *c);
//Node* suivant(Node *c);
void supprimer_debut(List *c);
void ajouter_fin(List *c, int val);
void supprimer_fin(List *c);

#endif //CHAINEDLIST_H
