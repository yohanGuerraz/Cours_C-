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