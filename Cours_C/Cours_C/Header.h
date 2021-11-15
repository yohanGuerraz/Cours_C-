#pragma once
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

enum class ChoixMenu
{
    JOUER = 'j',
    QUITTER = 'q',
    INCORRECT
};


/**
*
 */
void JustePrix();
void JeuJustePrix();
ChoixMenu demanderChoixMenu();

#endif // HEADER_H_INCLUDED