#include "Header.h"

int main()
{
	printf_s("**************************************************************************************\n");
	auto maVariable(42), maVariable2(43), maVariable3(44);
	auto maVariable4(45);

	//int &maReference(maVariable3);

	////renvoie la valeur de la variable (equivalent à cout)
	//printf_s("%i\n", maReference);
	//maReference = 2;
	//printf_s("%i\n", maVariable3);
	
	/**************************************************************************************/
	/*printf_s("**************************************************************************************\n");
	maReference = maVariable2;
	printf_s("%i\n", maVariable3); 
	printf_s("%i\n", maReference);*/

	/**************************************************************************************/
	//printf_s("**************************************************************************************\n");
	//int &maReference(maVariable3), &maReference2(maVariable3);

	//maReference2 = 57;
	//printf_s("%i\n", maVariable3);

	/**************************************************************************************/
	printf_s("**************************************************************************************\n");
	int *monPointeur(&maVariable);
	int *monPointeur2(&maVariable2);
	int *monPointeur3(&maVariable3);
	int *monPointeur4(&maVariable4);


	printf_s("%i\n", *monPointeur);
	printf_s("%i\n", *monPointeur2);
	printf_s("%i\n", *monPointeur3);
	printf_s("%i\n", *monPointeur4);


	//vérifie si le pointeur pointe vers une addresse null ou non 
	monPointeur = nullptr;

	if (monPointeur != nullptr)
	{

	}

	if (monPointeur)
	{

	}


	return 0;
}