# Cours_C-
exemple de code fait en cours pour vérifier nos compétence en C++

#### Dans cette solution sont regroupés les projet suivant:
	- Cours_C (justePrix)
	- MonPendu
	- reference
	- JeuxVideo

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

On peut y voir 6 fichier différents 3 dans le dossier d'en-tête (Jeu.h / Menu.h / Solution.h) et 3 dans le dossier Fichier sources (Jeu.cpp / Menu.cpp / Solution.cpp).


Description: Dans ce fichier on retrouve toutes les bibliothèques et constantes servant au bon fonctionnement du jeux 
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
Description: Dans ce fichier on retrouve toutes les déclarations des différentes fonctions servant à lance les différentes parties du jeux

#### Fichier Jeu.h

```c
#include "Solution.h"


#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

enum class Score
{
    Score_JOUER = 0,
    Score_JOUER_FACILE = 0,
    Score_JOUER_TROIS_PARTIES = 0,
  
};

using TableauScore = std::array<int, NOMBRE_SCORE>;

using namespace std;
/**
*
 */
void jouerTroisParties();
int jouerPartie(int leJustePrix, int max);
void demanderProposition(int &proposition);
void AfficherScore(TableauScore &score);


#endif // JEU_H_INCLUDED
```
Description: Dans ce fichier on retrouve toutes les definitions des différentes fonctions servant à obtenir la proposition du joueur, le type de partie qu'il a décidé de jouer (partie simple ou partie en 3 fois) ainsi qu'une fonction (non terminer) permettant de récupérer les scores des différentes parties. 

#### Fichier Jeu.cpp

```c
#include "Jeu.h"
void demanderProposition(int &proposition)
{

    cin >> proposition;
}

int jouerPartie(int leJustePrix, int max)
{
    auto proposition{ 0 };
    auto nombreTentatives{ 0 };
    int ScorePartie = 0;
    do
    {
        cout << "Proposition? ";
        demanderProposition(proposition);

        cout << proposition;

        if (proposition >= BORNE_MIN && proposition < max)
        {
            nombreTentatives++;
            if (proposition == leJustePrix)
            {
                cout << "Bravo! " << endl;
                //ScorePartie = ScorePartie + 1;
            }
            else if (proposition > leJustePrix)
            {
                cout << "C'est moins ! " << endl;
            }
            else
            {
                cout << "C'est plus ! " << endl;
            }
        }
    } while (proposition != leJustePrix && proposition >= BORNE_MIN);

    if (proposition == leJustePrix)
    {
        cout << "partie terminée! "
            << "en " << nombreTentatives << " tentatives" << endl;
    }
    else
    {
        cout << "partie abandonnée ";
        ScorePartie = 0;
    }

    return;
}

void jouerTroisParties()
{
    cout << "C'est parti ! " << endl;
    for (auto aDeviner : { 208, 42, 1984 })
    {
        jouerPartie(aDeviner, BORNE_MAX);
    }

}

void AfficherScore(TableauScore& score)
{
    auto Score = TableauScore{ 0, 0, 0 };

}
```
Description: Dans ce fichier on retrouve toutes les déclarations des différentes fonctions servant à afficher le menu du jeux

#### Fichier Menu.h

```c
#pragma once
#include "Solution.h"

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

enum class ChoixMenu
{
    JOUER = 'a',
    JOUER_FACILE = 'b',
    JOUER_TROIS_PARTIES = 'c',
    QUITTER = 'q',
    INCORRECT
};

using namespace std;

/**
*
 */

ChoixMenu demanderChoixMenu();
void afficherMenu();

#endif // MENU_H_INCLUDED
```
Description: Dans ce fichier on retrouve toutes les definitions des différentes fonctions servant à afficher le menu du jeux et a faire un choix dans le menu

#### Fichier Menu.cpp
```c
#include "Menu.h"

ChoixMenu demanderChoixMenu()
{
    char saisieChoix;
    cin >> saisieChoix;
    if (saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_FACILE) || saisieChoix == static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }
    else
    {
        return ChoixMenu::INCORRECT;
    }
}


void afficherMenu()
{
    cout << static_cast<char>(ChoixMenu::JOUER) << ": jouer" << endl;
    // on ajoute les choix possible à l'affichage
    cout << static_cast<char>(ChoixMenu::JOUER_FACILE) << ": jouer en facile" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) << ": jouer en trois parties" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << ": quitter" << endl;
}
```

## Dans le projet MonPendu

Description : le but de ce jeux est de deviner le mot proposer avant que notre bonhomme soit pendu.
On peut y voir 6 fichier différents 3 dans le dossier d'en-tête (AffichagePendu.h / Aleatoire.h / main.h) et 3 dans le dossier Fichier sources (AffichagePendu.cpp / Aleatoire.cpp / main.cpp).

**************************************************************************************
## Sources
- Lien ressources pour [C++](https://isocpp.org/)
- Lien ressources pour installer [SFML](https://www.sfml-dev.org/tutorials/2.3/start-vc-fr.php) sur Visual studio 2019
