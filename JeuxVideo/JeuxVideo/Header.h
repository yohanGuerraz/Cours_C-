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