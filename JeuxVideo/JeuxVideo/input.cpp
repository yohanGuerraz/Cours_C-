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