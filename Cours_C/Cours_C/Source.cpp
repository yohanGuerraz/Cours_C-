/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 15/11/2021
* Description : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
*/

#include "Header.h"

using namespace std;

int main() {


	int ichoix = 0;

	printf_s("hello bienvenue dans mon jeux le juste prix\n");
	printf_s("Tape 1 Si vous souhaitez commencer à jouer\n");
	printf_s("Tape 2 Si vous souhaitez quitter le jeux\n");
	printf_s("\n");
	printf_s("Entrer un numéro :");
	scanf_s("%i", &ichoix);


	switch (ichoix)
	{
	case (1):
		printf_s("Vous entrez dans le jeux\n");
		JustePrix();
		break;
	case (2):
		printf_s("vous allez quitter le jeux\n");
		system("exit");
		break;

	}

	return 0;
}






void JustePrix() {
	
	/*Déclaration*/
	int aDevnire = 28;
	auto valeurPropose = 0;
	bool bNi = 0;
	int iBcl = 0;
	int iValue = 0;
	int iGagnant = 0;
	
	
	/*printf_s("hello bienvenue dans mon jeux le juste prix\n");
	printf_s("\n");
	printf_s("Entrer un numéro :");*/

	for (iBcl = 0; iBcl < 3; iBcl++) {

		printf_s("hello bienvenue dans mon jeux le juste prix\n");
		printf_s("\n");
		printf_s("Entrer un numéro :");

		do
		{
			scanf_s("%i", &valeurPropose);
			if (valeurPropose >= 0 && valeurPropose < 10'000) {

				iValue++;

				if (valeurPropose < 0) {
					bNi = 1;
				}

				if (iGagnant == 3) {
					bNi = 1;
				}


				else if (valeurPropose < aDevnire) {
					printf_s("c est plus \n");
					printf_s("Entrer un numéro :");

				}

				else if (valeurPropose > aDevnire) {
					printf_s("c est moin \n");
					printf_s("Entrer un numéro :");

				}

				else if (valeurPropose == aDevnire) {

					printf_s("bravo tu as trouvé le bon numero \n");
					printf_s("le numero est :%i\n", aDevnire);
					printf_s("Entrer un numéro encore un fois :");
					iGagnant++;
				}

			}

		} while (bNi == 0);
		printf_s("Bravo vous avez remporte cet manche en %i tours", iValue);
	}
}