#include <iostream>
#include "Header.h"
using namespace std;

const auto BORNE_MIN{ 0 };
const auto BORNE_MAX{ 10'000 };

int main()
{
    

    cout << "Bienvenue au juste prix" << endl;

    cout << static_cast<char>(ChoixMenu::JOUER)<<": jouer" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << ": quitter" << endl;

    auto choix{ ChoixMenu::JOUER }; // autre type, apostrophe simple caractère
    choix = demanderChoixMenu();
   
    switch (choix)
    {
    case ChoixMenu::JOUER:
        JeuJustePrix();
        break;
    case ChoixMenu::QUITTER:
        break;
    case ChoixMenu::INCORRECT:
        break;
    default:
        break;
    }
    return EXIT_SUCCESS;

}
ChoixMenu demanderChoixMenu()
{
    
    char saisieChoix;
    cin >> saisieChoix;
    if (saisieChoix = saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        choix = static_cast<ChoixMenu>(saisieChoix);

    }
    else
    {
        choix = ChoixMenu::INCORRECT;
    }
}

void JeuJustePrix()
{
    cout << "C'est parti ! " << endl;
    for (auto aDeviner : { 208, 42, 1984 })
    {
        auto proposition{ 0 };
        auto nombreTentatives{ 0 };
        do
        {
            cin >> proposition;
            if (proposition >= BORNE_MIN && proposition < BORNE_MAX)
            {
                nombreTentatives++;
                if (proposition == aDeviner)
                {
                    cout << "Bravo! " << endl;
                }
                else if (proposition > aDeviner)
                {
                    cout << "C'est moins ! " << endl;
                }
                else
                {
                    cout << "C'est plus ! " << endl;
                }
            }
        } while (proposition != aDeviner && proposition >= BORNE_MIN);

        if (proposition == aDeviner)
        {
            cout << "partie terminée! "
                << "en " << nombreTentatives << " tentatives" << endl;
        }
        else
        {
            cout << "partie abandonnée ";
        }
    }

}