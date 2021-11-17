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