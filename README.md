# Cours_C-
exemple de code fait en cours pour vérifier nos compétence en C++

#### Dans cette solution sont regroupés les projet suivant:

- [Cours_C (justePrix)](#projet-JustePrix)
- [MonPendu](#projet-MonPendu)
- [reference](#projet-reference)
- [JeuxVideo](#projet-JeuxVideo)
- [Sources](#Sources)
	
**************************************************************************************	
	
<div id='projet-reference'/>

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
**************************************************************************************

<div id='projet-JustePrix'/>

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
**************************************************************************************

<div id='projet-MonPendu'/>

## Dans le projet MonPendu

Description : le but de ce jeux est de deviner le mot proposer avant que notre bonhomme soit pendu.
On peut y voir 6 fichier différents 3 dans le dossier d'en-tête (AffichagePendu.h / Aleatoire.h / main.h) et 3 dans le dossier Fichier sources (AffichagePendu.cpp / Aleatoire.cpp / main.cpp).

**************************************************************************************

<div id='projet-JeuxVideo'/>

## Dans le projet JeuxVideo
Description : ce projet contient le jeux pong avec un aspect graphique fait via la bibliothèque SFML. 
Dans ce projet (qui a nécessité beaucoup de recherche), on aborde plusieur sujet allant de la création graphique à la gestion des colision entre les différents objets.

Description: Dans ce fichier on y retrouve tous ce qui permettra de gérer les entées clavier (ici on gère les flèches et la barre espace du clavier).

#### Fichier input.h

```c
#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Input
{
	struct Button
	{
		bool left, right, up, down, escape;
	};

public:
	//proto du constructeur
	Input();
	//protos
	Button GetButton(void) const;
	void InputHandler(Event event, RenderWindow& window);

private:
	Button button;
};


#endif // !INPUT_H
```

Description: Dans ce fichier on y retrouve toutes les fonctions permettant de gérer les différentes touche du clavier (même si ici on gère seulement les flèches et la barre espace du clavier).

#### Fichier input.cpp

```c
#include "input.h"

//constructeur
Input::Input() 
{
	button.left = button.right = button.up = button.down = button.escape = false;

}

//Fonction qui accède à un button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const 
{
	return button;
}

//fonction de gestion des inputs
void Input::InputHandler(Event event, RenderWindow& window)
{
	//Fermer la fenetre si on clique sur la croix
	if (event.type == Event::Closed)
	{
		//on ferme la fenetre
		window.close();
	}

	// Gestion des input (appuyes)
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code) // code de la touche utilisee
		{
		case Keyboard::Escape:
			button.escape = true;
			break;

		case Keyboard::Left:
			button.left = true;
			break;

		case Keyboard::Right:
			button.right = true;
			break;

		case Keyboard::Down:
			button.down = true;
			break;

		case Keyboard::Up:
			button.up = true;
			break;
		}

	}
	// Gestion des input (relacher)
	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code) // code de la touche utilisee
		{
		case Keyboard::Escape:
			button.escape = false;
			break;

		case Keyboard::Left:
			button.left = false;
			break;

		case Keyboard::Right:
			button.right = false;
			break;

		case Keyboard::Down:
			button.down = false;
			break;

		case Keyboard::Up:
			button.up = false;
			break;
		}

	}
}
```
Description: Dans ce fichier on retrouve toutes les déclarations des différentes fonctions servant à Dessiner les différent éléments, à géréer les différentes colisions entre les élément dessiner, à positionner les différents éléments du jeux.

#### Fichier Header.h

```c
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"

#ifndef HEADER_H
#define HEADER_H


// Constantes du programme
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

// Namesapces
using namespace sf;
using namespace std;

// Prototypes 
void UpdateBall();
void SetText(Text& txt, String str);
void CheckBtn();
void RaquetteIA();

#endif // !HEADER_H
```

Description: Dans ce fichier on retrouve toutes les definitions des différentes fonctions servant à Dessiner les différent éléments, à géréer les différentes colisions entre les élément dessiner, à positionner les différents éléments du jeux.

#### Fichier Source.cpp

```c
#include "Header.h"

/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 17/11/2021
* Description : Ce fichier contient les fonctions permettant de lancer le jeu pong.
*/


// Variables
// La fenetre du jeu
RenderWindow window;
// Pour la gestion des inputs
Input input;
//pour stocker la fonte 
Font font;
// Pour stocker le texte
Text txt;

//Pos raquettes
float posRaquettesLeftX = 50;
float posRaquettesRightX = WIN_WIDTH - 70;
float posRaquettesLeftY = WIN_HEIGHT / 2;
float posRaquettesRightY = posRaquettesLeftY;
float posRaquettesSpeed = 0.25f;
int raquettesHeight = 150;
int raquettesWidth = 20;

//Info Balles
float ballSpeed = 0.055f;
Vector2f ballDir = Vector2f(1.5f, 2.0f);
float ballPosX = WIN_WIDTH / 2;
float ballPosY = WIN_HEIGHT / 2;

//Score 
int scoreJ1 = 0;
int scoreJ2 = 0;

// Astuce pour afficher un chiffre sous forme de string
char temp[256];

//debut du programme
int main()
{
	//Création d'une fenetre
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT , 32), "Pong" , Style::Default);
	//chargement fonte
	font.loadFromFile("res/Poppins-Regular.ttf");
	// On règle toutes les propriétés de celui-ci
	SetText(txt, std::to_string(scoreJ1) + "|" + std::to_string(scoreJ2));

	//Préparation des formes
	//Balle
	CircleShape circleShape(15);
	circleShape.setPosition(ballPosX, ballPosY);
	//Raquette gauche
	RectangleShape rectangleShape(Vector2f(raquettesWidth, raquettesHeight));
	rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
	//Raquette droit
	RectangleShape rectangleShape2(Vector2f(raquettesWidth, raquettesHeight));
	rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);

	//Boucle qui tourne tant que la fenetre est ouverte
	while (window.isOpen())
	{
		Event event; // Variable pour gérer l'événement
		//on boucle sur les événements
		while (window.pollEvent(event))
		{
			// Gestion des input / events
			input.InputHandler(event, window);
		}
		//Gestion clavier
		CheckBtn();
		RaquetteIA();
		// Position raquettes, balle
		rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
		rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);
		// Update Ball
		UpdateBall();
		circleShape.setPosition(ballPosX, ballPosY);
		//couleur de la fenetre en noir
		window.clear(Color::Black);
		//C'est ici que l'on dessine les éléments du jeu
		window.draw(txt);
		window.draw(circleShape);
		window.draw(rectangleShape);
		window.draw(rectangleShape2);

		// Dessiner à l'écran
		window.display();
	}

	return 0;
}

void SetText(Text& txt, String str)
{
	//indique quelle police utiliser
	txt.setFont(font);
	//indique la chaine de caractère à afficher 
	txt.setString(str);
	//indique la taille de la police
	txt.setCharacterSize(26);
	//donne la couleur 
	txt.setFillColor(Color::White);
	// Posistion
	txt.setPosition((WIN_WIDTH / 2) - 40, 10);

}

void CheckBtn()
{
	// Raquette gauche
	if (input.GetButton().up == true)
	{
		posRaquettesLeftY -= posRaquettesSpeed;
		if(posRaquettesLeftY < 0)
		{
			posRaquettesLeftY = 0;
		}
	}

	if (input.GetButton().down == true)
	{
		posRaquettesLeftY += posRaquettesSpeed;
		if (posRaquettesLeftY + raquettesHeight > WIN_HEIGHT)
		{
			posRaquettesLeftY = WIN_HEIGHT - raquettesHeight;
		}
	}

	// Raquette droite
	if (input.GetButton().left == true)
	{
		posRaquettesRightY -= posRaquettesSpeed;
		if (posRaquettesRightY < 0)
		{
			posRaquettesRightY = 0;
		}
	}

	if (input.GetButton().right == true)
	{
		posRaquettesRightY += posRaquettesSpeed;
		if (posRaquettesRightY + raquettesHeight > WIN_HEIGHT)
		{
			posRaquettesRightY = WIN_HEIGHT - raquettesHeight;
		}
	}

	if (input.GetButton().escape == true)
	{
		window.close();
	}
}

void UpdateBall()
{
	// Pos balle
	ballPosX += ballDir.x * ballSpeed;
	ballPosY += ballDir.y * ballSpeed;

	//colisions balle
	//raqutte gauche et droite touchée 
	if ((ballPosX < posRaquettesLeftX + raquettesWidth && ballPosX > posRaquettesLeftX && ballPosY+7 < posRaquettesLeftY + raquettesHeight && ballPosY+7 > posRaquettesLeftY) || (ballPosX < posRaquettesRightX + raquettesWidth && ballPosX > posRaquettesRightX && ballPosY+7 < posRaquettesRightY + raquettesHeight && ballPosY+7 > posRaquettesRightY))
	{
		ballDir.x *= -1;
	}

	// mur gauche
	if (ballPosX < 0)
	{
		scoreJ2++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = fabs(ballDir.x);
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + "|" + std::to_string(scoreJ2));

	}

	// mur droit
	if (ballPosX > WIN_WIDTH)
	{
		scoreJ1++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = -fabs(ballDir.x);
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + "|" + std::to_string(scoreJ2));

	}

	//mur haut ou bas 
	if (ballPosY > WIN_HEIGHT || ballPosY < 0)
	{
		ballDir.y *= -1;
	}

}

//IA intégrer à la raquette droite
void RaquetteIA()
{
	posRaquettesRightY = ballPosY;
}
```

**************************************************************************************

<div id='Sources'/>

## Sources
- Lien ressources pour [C++](https://isocpp.org/)
- Lien ressources pour la documentation [SFML](https://www.sfml-dev.org/tutorials/2.3/start-vc-fr.php)
- Lien ressources pour installer [SFML](https://www.sfml-dev.org/tutorials/2.3/start-vc-fr.php) sur Visual studio 2019
