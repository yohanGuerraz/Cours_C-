#include "Aleatoire.h"

/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 16/11/2021
* Description : Ce fichier contient la fonction 'nbAleatoire'. L'ex�cution du programme commence et se termine � cet endroit.
*/

using namespace std;

//Provoque l'al�atoire
int nbAleatoire(int min, int max) {
    int nbAl;
    nbAl = rand() % (max + 1) + min;
    return nbAl;
}

