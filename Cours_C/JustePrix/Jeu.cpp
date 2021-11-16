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
