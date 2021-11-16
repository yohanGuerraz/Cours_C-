# Cours_C-
exemple de code fait en cours pour vérifier nos compétence en C++

#### Dans cette solution sont regroupés les projet suivant:
	- Cours_C
	- JeuPendu
	- JustePrix

## Dans le projet reference

#### Création d'une réference


Qu'est ce qu'une référence ?

Une référence peut être vue comme un alias d'une variable. C'est-à-dire qu'utiliser la variable, ou une référence à cette variable est équivalent. Ce qui signifie que l'on peut modifier le contenu de la variable en utilisant une référence.

Une référence ne peut être initialisée qu'une seule fois : à la déclaration. Toute autre affectation modifie en fait la variable référencée. Une référence ne peut donc référencer qu'une seule variable tout au long de sa durée de vie.



```c
int main()
{
auto maVariable(42), maVariable2(43), maVariable3(44);
auto maVariable4(45);

	int &maReference(maVariable3);

	#renvoie la valeur de la variable (equivalent à cout)
	printf_s("%i\n", maReference);
	maReference = 2;
	printf_s("%i\n", maVariable3);
}
```
#### Création d'un pointeur


Qu'est ce qu'un pointeur ?

Une variable correspond à un emplacement en mémoire (adresse) où se trouve une valeur.
Un pointeur désigne un type particulier de variable dont la valeur est une adresse. Un pointeur permet donc de contourner la restriction sur le choix de l'adresse d'une variable, et permet essentiellement d'utiliser la mémoire allouée dynamiquement.
Il est utilisé lorsque l'on veut manipuler les données stockées à cette adresse. C'est donc un moyen indirect de construire et de manipuler des données souvent très complexes.

```c
int main()
{
auto maVariable(42), maVariable2(43), maVariable3(44);
auto maVariable4(45);

  int *monPointeur(&maVariable);
	int *monPointeur2(&maVariable2);
	int *monPointeur3(&maVariable3);
	int *monPointeur4(&maVariable4);


	printf_s("%i\n", *monPointeur);
	printf_s("%i\n", *monPointeur2);
	printf_s("%i\n", *monPointeur3);
	printf_s("%i\n", *monPointeur4);
}
```

**************************************************************************************
