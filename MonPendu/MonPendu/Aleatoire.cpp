#include "Aleatoire.h"

//Provoque l'aléatoire
int nbAleatoire(int min, int max) {
    int nbAl;
    nbAl = rand() % (max + 1) + min;
    return nbAl;
}

