#include "Aleatoire.h"

/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 16/11/2021
* Description : Ce fichier contient la fonction 'nbAleatoire'. L'exécution du programme commence et se termine à cet endroit.
*/

using namespace std;

//Provoque l'aléatoire
int nbAleatoire(int min, int max) {
    int nbAl;
    nbAl = rand() % (max + 1) + min;
    return nbAl;
}

