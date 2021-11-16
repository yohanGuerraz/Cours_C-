# Cours_C-
exemple de code fait en cours pour vérifier nos compétence en C++

#### Dans cette solution sont regroupés les projet suivant:
	- Cours_C
	- JeuPendu
	- JustePrix

## Dans le projet reference

#### Création d'une réference


Qu'est ce qu'une référence ?

Une référence peut être vue comme un alias d'une variable. C'est-à-dire qu'utiliser la variable, ou une référence à cette variable est équivalent. Ce qui signifie que l'on peut modifier le contenu de la variable en utilisant une référence.

Une référence ne peut être initialisée qu'une seule fois : à la déclaration. Toute autre affectation modifie en fait la variable référencée. Une référence ne peut donc référencer qu'une seule variable tout au long de sa durée de vie.



```c
int main()
{
auto maVariable(42), maVariable2(43), maVariable3(44);
auto maVariable4(45);

	int &maReference(maVariable3);

	#renvoie la valeur de la variable (equivalent à cout)
	printf_s("%i\n", maReference);
	maReference = 2;
	printf_s("%i\n", maVariable3);
}
```
#### Création d'un pointeur


Qu'est ce qu'un pointeur ?

Une variable correspond à un emplacement en mémoire (adresse) où se trouve une valeur.
Un pointeur désigne un type particulier de variable dont la valeur est une adresse. Un pointeur permet donc de contourner la restriction sur le choix de l'adresse d'une variable, et permet essentiellement d'utiliser la mémoire allouée dynamiquement.
Il est utilisé lorsque l'on veut manipuler les données stockées à cette adresse. C'est donc un moyen indirect de construire et de manipuler des données souvent très complexes.

```c
int main()
{
auto maVariable(42), maVariable2(43), maVariable3(44);
auto maVariable4(45);

  int *monPointeur(&maVariable);
	int *monPointeur2(&maVariable2);
	int *monPointeur3(&maVariable3);
	int *monPointeur4(&maVariable4);


	printf_s("%i\n", *monPointeur);
	printf_s("%i\n", *monPointeur2);
	printf_s("%i\n", *monPointeur3);
	printf_s("%i\n", *monPointeur4);
}
```
## Dans le projet JustePrix

Description : le but de ce jeux est de proposer le juste prix suivant les différentes proposition le programme affichera "c'est plus" ou "c'est moin". Il y a 3 mode de jeu le mode normal / facile et en 3 parties.
Par la suite des fonctionnalitées seront ajouté tels qu'un chronomètre et un tableaux des scores.

On peut y voir 6 fichier différents 3 dans le dossier d'en-tête (Jeu.h / Menu.h / Solution.h) et 3 dans le dossier Fichier sources (Jeu.h / Menu.h / Solution.h).

#### Fichier Solution.h

```c
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <array>

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

const auto BORNE_MIN{ 0 };
const auto BORNE_MAX{ 10'000 };
const auto BORNE_MAX_FACILE{ 1'000 };

using namespace std;

/**
* Declaration des procedures/fonctions du programme 
 */


#endif // HEADER_H_INCLUDED
```
#### Fichier Solution.cpp

Description : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

```c
#include "Solution.h"
#include "Jeu.h"
#include "Menu.h"

/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 16/11/2021
* Description : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
*/


int main()
{
    
    cout << "Bienvenue au juste prix" << endl;

    // on créé un booléen continuer
    bool continuer(true);
    // ici on insert la boucle while
    while (continuer)
    {

        afficherMenu();

        auto choix = demanderChoixMenu();

        switch (choix)
        {
            // on met à jour le switch aussi
        case ChoixMenu::JOUER:
            jouerPartie(3000, BORNE_MAX);
            break;
        case ChoixMenu::JOUER_FACILE:
            jouerPartie(250, BORNE_MAX_FACILE);
            break;
        case ChoixMenu::JOUER_TROIS_PARTIES:
            jouerTroisParties();
            break;
        case ChoixMenu::QUITTER:
            cout << "Au revoir " << endl;
            continuer = false;
            break;
        case ChoixMenu::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
```
**************************************************************************************
## Sources
Lien ressources : [C++](https://isocpp.org/)
