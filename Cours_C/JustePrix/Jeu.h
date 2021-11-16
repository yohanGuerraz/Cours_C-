#pragma once
#include "Solution.h"


#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED



using namespace std;
/**
*
 */
void jouerTroisParties();
void jouerPartie(int leJustePrix, int max);
void demanderProposition(int &proposition);
void AfficherScore();
void CalculeScore();

#endif // JEU_H_INCLUDED