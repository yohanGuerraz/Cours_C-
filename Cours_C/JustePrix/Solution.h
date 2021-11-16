#pragma once
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>



#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

enum class ChoixMenu
{
    JOUER = 'a',
    JOUER_FACILE = 'b',
    JOUER_TROIS_PARTIES = 'c',
    QUITTER = 'q',
    INCORRECT
};

const auto BORNE_MIN{ 0 };
const auto BORNE_MAX{ 10'000 };
const auto BORNE_MAX_FACILE{ 1'000 };

using namespace std;

/**
*
 */

ChoixMenu demanderChoixMenu();
void afficherMenu();
void jouerTroisParties();
void jouerPartie(int leJustePrix, int max);
void demanderProposition(int& proposition);

#endif // HEADER_H_INCLUDED