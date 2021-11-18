#include "Header.h"
#include <algorithm>
using namespace std;

int main()
{

	////séquentiels
	//array<T, n>monarray;

	//// vector : est un tableau dynamique
	//vector<T>;


	vector<string> strings;

	strings.push_back("1");
	strings.push_back("2");
	strings.push_back("3");
	strings.push_back("4");
	


	//for (int i = 0; i < strings.size(); i++)
	//{
	//	printf("%s\n\n", strings[i]);

	//}

	printf("==================================== Utilisation vector ==========================================\n\n");
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}
	vector<string>::iterator it = strings.begin();
	it += 2;
	cout << *it << endl;

	printf("==================================== Fonctions de vector ==========================================\n\n");

	//front()
	//back()
	//data()
	cout << strings.front() << endl;
	cout << strings.back() << endl;
	cout << strings.data() << endl;
	
	printf("===================================== Instantie une list =========================================\n\n");

	list<int> my_list = { 12, 5, 10, 9 };

	for (int x : my_list) {
		cout << x << '\n';
	}

	printf("===================================== Fonctions une list =========================================\n\n");

	list<int>deschiffre;

	deschiffre.push_back(1);
	deschiffre.push_back(2);
	deschiffre.push_back(3);
	deschiffre.push_back(4);

	for (list<int>::iterator it2 = deschiffre.begin(); it2 != deschiffre.end(); it2++)
	{
		cout << *it2 << endl;
	}

	list<int>::iterator my_list2 = deschiffre.begin();
	my_list2 ++;
	deschiffre.insert(my_list2, 2021);
	cout << "monIterator :" << *my_list2 << '\n';
	printf("****************************************************************************************\n");

	for (list<int>::iterator it2 = deschiffre.begin(); it2 != deschiffre.end(); it2++)
	{
		cout << *it2 << endl;
	}

	list<int>::iterator efface = deschiffre.begin();
	efface++;
	efface++;
	efface = deschiffre.erase(efface);
	cout << "monEfface :" << *efface << '\n';
	printf("****************************************************************************************\n");

	for (list<int>::iterator it2 = deschiffre.begin(); it2 != deschiffre.end(); it2++)
	{
		cout << *it2 << endl;
	}


	printf("===================================== 2.Fonctions une list =========================================\n\n");

	list<int>deschiffre2;

	deschiffre2.push_back(1);
	deschiffre2.push_back(2);
	deschiffre2.push_back(3);
	deschiffre2.push_back(4);

	vector<int>Nbre;

	Nbre.push_back(1);
	Nbre.push_back(2);
	Nbre.push_back(3);
	Nbre.push_back(4);
	Nbre.push_back(5);
	Nbre.push_back(6);
	Nbre.push_back(7);
	Nbre.push_back(8);
	
	array<int, 4>monarray = {1,2,3,4};


	cout << "size vector :" << Nbre.capacity() << endl;
	cout << "capacity vector :" << Nbre.capacity() << endl;
	
	printf("===================================== clée valeur =========================================\n\n");

	map<string, int>NotreRPI;

	NotreRPI["Yohann"] = 6;
	NotreRPI["Naoufal"] = 16;
	NotreRPI["Gregoire"] = 14;
	NotreRPI["Yohann"] = 15;

	NotreRPI.insert(make_pair("Julien", 15));

	for (map<string, int>::iterator it = NotreRPI.begin(); it != NotreRPI.end(); it++)
	{
		pair<string, int> note = *it;
		cout << "La note de " << note.first << "est :" << note.second << endl;
	}



	printf("===================================== exo =========================================\n\n");

	vector<string>nom;
	nom.push_back("yohan");
	nom.push_back("adrien");
	nom.push_back("toto");
	nom.push_back("machin");
	nom.push_back("truc");
	nom.push_back("chouette");
	nom.push_back("totisuhvnisnviunsviofso");
	nom.push_back("macsldlvnosnvosnvonsovfnshin");
	nom.push_back("trskcvdbisciusviuoisvuc");
	nom.push_back("chouekbcvisbivbsivbisbviksbvtte");
		
	//cout << std::count_if(nom.begin(), nom.end(), test) << endl;


	return 0;
 
}

bool test(string nom2)
{
	return (nom2.length() > 6);
}