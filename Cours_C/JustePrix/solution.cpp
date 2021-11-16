#include "Solution.h"
#include "Jeu.h"
#include "Menu.h"

/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 16/11/2021
* Description : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
*/

//array<int, cte> scores{ 1, 2, 3 };

int main()
{
    
    cout << "Bienvenue au juste prix" << endl;

    // on créé un booléen continuer
    bool continuer(true);
    // ici on insert la boucle while
    while (continuer)
    {

        afficherMenu();

        auto choix = demanderChoixMenu();

        switch (choix)
        {
            // on met à jour le switch aussi
        case ChoixMenu::JOUER:
            jouerPartie(3000, BORNE_MAX);
            break;
        case ChoixMenu::JOUER_FACILE:
            jouerPartie(250, BORNE_MAX_FACILE);
            break;
        case ChoixMenu::JOUER_TROIS_PARTIES:
            jouerTroisParties();
            break;
        case ChoixMenu::QUITTER:
            cout << "Au revoir " << endl;
            continuer = false;
            break;
        case ChoixMenu::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

