//
// Created by Alexis on 07/02/2025.
//
#include "ChainedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

List* creer_liste(int val)
{
    List* chaine;
    chaine = (List*) malloc(sizeof(int) + 2*sizeof(Node));
    Node n = {val, NULL};
    chaine->first = &n;
    chaine->curr = chaine->first;
    return chaine;
}

void afficher_liste(List *c)
{
    printf("[");
    Node* suivant = c->first;
    while(suivant->next != NULL)
    {
        if(suivant->next->next == NULL)
        {
            printf(" %d ]", suivant->val);
        }
        printf(" %d,", suivant->val);
        suivant = suivant->next;
    }
}

int liste_est_vide(List *c)
{
    return c->first == NULL;
}

void ajouter_debut(List *c, int val)
{
    Node n = {val, c->first};
    if(c->first == c->curr)
    {
        c->curr = &n;
    }
    c->first = &n;
}

void supprimer_debut(List *c)
{
    Node* n = c->first;
    if(!liste_est_vide(c))
    {
        c->first = c->first->next;
    }
}

void ajouter_fin(List *c, int val)
{
    Node n = {val, NULL};
    Node *end = c->first;
    while(end->next != NULL)
    {
        end = end->next;
    }
    end->next = &n;
}

void supprimer_fin(List *c)
{
    Node *end = c->first;
    while(end->next != NULL)
    {
        end = end->next;
    }
    end = NULL;
}