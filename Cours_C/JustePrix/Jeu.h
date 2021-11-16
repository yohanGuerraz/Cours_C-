#pragma once
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