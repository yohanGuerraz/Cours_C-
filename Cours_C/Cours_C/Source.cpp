/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 15/11/2021
* Description : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
*/

#include "Header.h"

using namespace std;

int main() {

	/*D�claration*/
	int aDevnire = 28;
	auto valeur = 0;
	bool bNi = 0;
	int iBcl = 0;
	int iValue = 0;

	printf_s("hello bienvenue dans mon jeux le juste prix\n");
	printf_s("\n");
	printf_s("Entrer un num�ro :");
	scanf_s("%i",&valeur);

	do  
	{
		iValue;

			if (valeur < 0) {
				bNi = 1;
			}

			if (iValue == 3 ) {
				bNi = 1;
			}

			else if (valeur < aDevnire) {
				printf_s("c est plus \n");
				printf_s("Entrer un num�ro :");
				scanf_s("%i", &valeur);
			}

			else if (valeur > aDevnire) {
				printf_s("c est moin \n");
				printf_s("Entrer un num�ro :");
				scanf_s("%i", &valeur);
			}

			else if (valeur == aDevnire) {

				printf_s("bravo tu as trouv� le bon numero \n");
				printf_s("le numero est :%i\n", aDevnire);
				printf_s("Entrer un num�ro encore un fois :");
				scanf_s("%i", &valeur);
				iValue = iValue + 1;
			}

	} while (bNi == 0);

	printf_s("Nombre de fois jouer :%i", iValue);

	return 0;
}