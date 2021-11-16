#include "main.h"
#include "Aleatoire.h"
#include "AffichagePendu.h"


/*
* Nom : Guerraz
* Prenom : Yohan
* Date : 16/11/2021
* Description : Ce fichier contient la fonction 'main' c'est ici que le jeux se lancera. 
* L'exécution du programme commence et se termine à cet endroit.
* Sources utilisées : 
        -   https://isocpp.org/  
        -   https://docs.microsoft.com/fr-fr/cpp/standard-library/chrono?view=msvc-170
        -   https://www.cplusplus.com/reference/

*/

using namespace std;

int main() 
{
   //Déclaration des différentes variables
    char mask[][30] = { "ab____","a______n","b__h__","b__i__","c_b___","___ph__","d____","d_____m","_c___r","_go___","f_i__","f____c__","g____x","g___i__","h_a___","h____x","i_____e","ig____","__j___r","j__g___","k___i_","k_____e","l____d","l____y__","m__i__","m____q___","n___h_","n__k__","o__g_","_p__q__","o_a____","p______n","p___u","q_a___","q____r","r_y__","r_p___","_c__a___","s___a___","t__h__","t_r_____","u__v___","_rb______","v__t_____","v__l__","w____","_a___-p___","x_____o__","_ar_","___","z__i__","z___y_" };
    char c, nom[20];
    int i, cpt, mot, essai, cpt1;

    //Mise en place de l'aléatoire qui permet de piocher un mot au hazard dans la liste
    srand(time(NULL));
    mot = nbAleatoire(0, 51);

    printf("Donnez votre nom tout d'abord\n");
    scanf_s("%p", &nom);
    system("CLS");
    c = strlen(liste[mot]);

    //Calcul du nombre de lettres cachées dans le mot 
    for (i = 0, cpt = 1; mask[mot][i] != '\0'; i++) {
        if (mask[mot][i] == '_') {
            cpt++;
        }
    }
    //Debut du jeu
    printf("\t\tBIENVENUE << %s >> dans le jeu le PENDU !!\n\tVous avez droit a 14 erreurs pour trouver le mot cach\x82 \n\t\t\tBONNE CHANCE...\n\n", nom);
    puts(mask[mot]);
    essai = 0;
    do {
        if (cpt > 0 && essai <= 15) {
            printf("Donnez une lettre\t ");
            c = _getch();
            printf("%c\n", c);

            // cpt1 : Variable a partir de laquelle on pourra savoir si la lettre est valide ( si cpt est decrementé ou pas )  
            cpt1 = cpt;
            for (i = 0; liste[mot][i] != '\0'; i++) {
                if (liste[mot][i] == c && mask[mot][i] == '_') {
                    mask[mot][i] = c;
                    cpt--;
                }

            }
            // Si la variable cpt à varier alors : selon le nombre d'essais restant
            if (cpt1 == cpt && essai != 15) {
                essai = essai + 1;
                printf("\n\nAttention : La lettre \"%c\" n'existe pas parmi les lettres cach\x82s\nIl vous reste %d erreurs : Profitez en bien ...\n\n", c, 15 - essai);
                switch (essai) {
                case 1: pendu1(); break;
                case 2: pendu2(); break;
                case 3: pendu3(); break;
                case 4: pendu4(); break;
                case 5: pendu5(); break;
                case 6: pendu6(); break;
                case 7: pendu7(); break;
                case 8: pendu8(); break;
                case 9: pendu9(); break;
                case 10: pendu10(); break;
                case 11: pendu11(); break;
                case 12: pendu12(); break;
                case 13: pendu13(); break;
                case 14: pendu14(); break;
                default:;
                }
            }
            puts(mask[mot]);
        }
    } while (cpt > 1 && essai <= 14);
    // Si le mot est trouvé
    if (cpt && essai <= 14) {
        printf("\n\nBravo !!! Maintenant vous meritez votre vie %s !!! Fantastique...\nLe mot \x82tait bien \"%s\"", nom, liste[mot]);
    }
    // Sinon
    else if (cpt = 0 || essai >= 15) {
        printf("\nD\x82sol\x82 %s ... Faites vos dernieres prieres... Vous serez pendu hahahahaha!!!", nom);
    }

    _getch();
    return 0;

}