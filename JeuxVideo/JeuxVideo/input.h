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
