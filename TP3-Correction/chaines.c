#include "chaines.h"

#include <stddef.h>



int compterCaractere(char* chaine) {
    int i = 0;
    // J'ajoute une limite à 100000, dans le cas où on a jamais mis le '\0'... 
    while (chaine[i] != '\0') {
        i++;
        if (i > 100000) {
            return -1; // Une erreur, c'est beaucoup trop long!
        }
    }
    return i;
}

char* affichageEnDecimal(char* chaine) {
    /*
        Le code 'normal' est facile :
        for (int i = 0; i < n; i++) {
            printf("%d ", chaine[i]);
        }
        Mais ici, on va même retourner une chaine de caractère qui contient ce texte.
        (Mauvaise lecture de l'énoncé de ma part)
    */
    int n = compterCaractere(chaine);
    char* chaineFinale = (char*) malloc(sizeof(char) * (5 * n + 1)); // *5 pour être sûr d'etre suffisament grand
    char* buffer = (char*) malloc(sizeof(char) * (5 * n + 1));
    for (int i = 0; i < n; i++) {
        // On concatene 'chaineFinale' et '(int)chaine[i]' dans 'buffer'
        sprintf(buffer, "%s %d", chaineFinale, chaine[i]);
        // Puis on copie le contenu de 'buffer' dans 'chaineFinale'
        strcpy(chaineFinale, buffer);
    }
    free(buffer);
    return chaineFinale;
}

char* mettreEnMajuscule(char* chaine) {
    int n = compterCaractere(chaine);
    char* newChaine = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        // Les char sont des nombres (des entiers), donc on peut les comparer!
        if ('a' <= chaine[i] && chaine[i] <= 'z') {
            // On peut même faire de l'arithmétique, bien sûr
            newChaine[i] = chaine[i] + ('A' - 'a');
        } else {
            newChaine[i] = chaine[i];
        }
    }
    // Attention! Sans le caractère de fin '\0', on ne sera pas sûr de ce qui sera affiché à l'écran!!!
    newChaine[n] = '\0';
    return newChaine;
}

char* mettreEnMinuscule(char* chaine) {
    int n = compterCaractere(chaine);
    char* newChaine = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if ('A' <= chaine[i] && chaine[i] <= 'Z') {
            newChaine[i] = chaine[i] + 'a' - 'A';
        } else {
            newChaine[i] = chaine[i];
        }
    }
    // Attention! Sans le caractère de fin '\0', on ne sera pas sûr de ce qui sera affiché à l'écran!!!
    newChaine[n] = '\0';
    return newChaine;
}

char* transformerMinMaj(char* chaine) {
    int n = compterCaractere(chaine);
    char* newChaine = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if ('A' <= chaine[i] && chaine[i] <= 'Z') {
            newChaine[i] = chaine[i] + ('a' - 'A');
        } else if ('a' <= chaine[i] && chaine[i] <= 'z') {
            newChaine[i] = chaine[i] + ('A' - 'a');
        } else {
            newChaine[i] = chaine[i];
        }
    }
    // Attention! Sans le caractère de fin '\0', on ne sera pas sûr de ce qui sera affiché à l'écran!!!
    newChaine[n] = '\0';
    return newChaine;
}

char* retournerMot(char* chaine) {
    int n = compterCaractere(chaine);
    char* newChaine = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        newChaine[n - (i + 1)] = chaine[i];
    }
    // Attention! Sans le caractère de fin '\0', on ne sera pas sûr de ce qui sera affiché à l'écran!!!
    newChaine[n] = '\0';
    return newChaine;
}

char* supprimeCaractere(char* chaine, char caractere) {
    int n = compterCaractere(chaine);
    // Notre chaine finale sera probablement plus petite, mais dans le doute on "reserve" tout l'espace necessaire
    char* newChaine = (char*) malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++, j++) {
        if (chaine[i] == caractere) {
            j--;
        } else {
            newChaine[j] = chaine[i];
        }
    }
    // Attention! Sans le caractère de fin '\0', on ne sera pas sûr de ce qui sera affiché à l'écran!!!
    newChaine[j] = '\0';
    return newChaine;
}

bool estPalindrome(char* chaine) {
    int n = compterCaractere(chaine);
    for (int i = 0; i < n; i++) {
        if (chaine[n - (i + 1)] != chaine[i]) {
            return false;
        }
    }
    return true;
}

/* // Cette version est "casse-sensitive", c-à-d qu'elle considère 'a' != 'A'
int comparerChaine(char* chaine1, char* chaine2) {
    for (int i = 0; i < compterCaractere(chaine1) && i < compterCaractere(chaine2); i++) {
        if (chaine1[i] > chaine2[i]) {
            return 1;
        } else if (chaine1[i] < chaine2[i]) {
            return -1;
        }
    }
    if (compterCaractere(chaine1) < compterCaractere(chaine2)) {
        return -1;
    } else if (compterCaractere(chaine1) > compterCaractere(chaine2)) {
        return 1;
    } 
    return 0;
}
*/


int comparerChaine(char* chaine1, char* chaine2) {
    int n1 = compterCaractere(chaine1);
    int n2 = compterCaractere(chaine2);
    // Attention, je vais devoir libérer la mémoire des chaines en minuscules!
    char* chaine1Minuscules = mettreEnMinuscule(chaine1);
    char* chaine2Minuscules = mettreEnMinuscule(chaine2);

    int resultat = 0;
    for (int i = 0; i < n1 && i < n2; i++) {
        if (chaine1Minuscules[i] > chaine2Minuscules[i]) {
            resultat = 1;
            break;
        } else if (chaine1Minuscules[i] < chaine2Minuscules[i]) {
            resultat = -1;
            break;
        }
    }

    // Le début des chaines est identique, mais la longueur ne l'est peut-être pas...
    if (resultat == 0) {
        if (n1 < n2) {
            resultat = -1;
        } else if (n1 > n2) {
            resultat = 1;
        } 
    }
    // Libération
    free(chaine1Minuscules);
    free(chaine2Minuscules);

    // Seulement après, on retourne le résulat
    return resultat;
}

char* couper_char(char* chaine, int n, int debut) {
    char* nouvelle = (char*) malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        nouvelle[i] = chaine[debut + i];
    }
    nouvelle[n] = '\0';
    return nouvelle;
}

void conjuguer(char* chaine) {
    int n = compterCaractere(chaine);
    if (comparerChaine(couper_char(chaine, 2, n - 2), "er") != 0) {
        printf("Pas un verbe du premier groupe\n");
    }

    char* radical = couper_char(chaine, n - 2, 0);

    printf("Je %se\n", radical);
    printf("Tu %ses\n", radical);
    printf("Il/elle %se\n", radical);
    printf("Nous %sons\n", radical);
    printf("Vous %sez\n", radical);
    printf("Ils/elles %sent\n", radical);

    // On libère!
    free(radical);
}
