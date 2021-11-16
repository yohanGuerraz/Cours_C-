#include "JeuPendu.h"

int main() {
    char liste[][30] = { "abolir","ablution","bachot","balise","cabine","camphre","debit","decorum","echoir","egouts","famine","fantoche","gazeux","granite","hiatus","hideux","ignoble","iguane","rejouir","jongler","kaolin","kiosque","lezard","linotype","malice","mastiquer","nymphe","nickel","orage","optique","oraison","parution","pendu","quartz","quater","rayon","rapide","scenario","scolaire","tacher","terminus","univers","urbanisme","vestibule","violent","wagon","water-polo","xelophone","yard","yen","zenith","zephyr" };
    char mask[][30] = { "ab____","a______n","b__h__","b__i__","c_b___","___ph__","d____","d_____m","_c___r","_go___","f_i__","f____c__","g____x","g___i__","h_a___","h____x","i_____e","ig____","__j___r","j__g___","k___i_","k_____e","l____d","l____y__","m__i__","m____q___","n___h_","n__k__","o__g_","_p__q__","o_a____","p______n","p___u","q_a___","q____r","r_y__","r_p___","_c__a___","s___a___","t__h__","t_r_____","u__v___","_rb______","v__t_____","v__l__","w____","_a___-p___","x_____o__","_ar_","___","z__i__","z___y_" };
    char c, nom[20];
    int i, cpt, mot, essai, cpt1;
    srand(time(NULL));
    mot = nbAleatoire(0, 51);
    printf("Donnez votre nom tout d'abord\n");
    scanf_s("%s", &nom);
    system("CLS");
    c = strlen(liste[mot]);
    //Calcul du nombre de lettres cachées dans le mot 
    for (i = 0, cpt = 1; mask[mot][i] != '\0'; i++) {
        if (mask[mot][i] == '_') {
            cpt++;
        }
    }
    //Debut du jeu
    printf("\t\tBIENVENUE << %s >> dans le jeu le PENDU !!\n\tVous avez droit a 6 erreurs pour trouver le mot cach\x82 \n\t\t\tBONNE CHANCE...\n\n", nom);
    puts(mask[mot]);
    essai = 0;
    do {
        if (cpt > 0 && essai <= 5) {
            printf("Donnez une lettre\t ");
            c = getch();
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
            if (cpt1 == cpt && essai != 6) {
                essai = essai + 1;
                printf("\n\nAttention : La lettre \"%c\" n'existe pas parmi les lettres cach\x82s\nIl vous reste %d erreurs : Profitez en bien ...\n\n", c, 6 - essai);
                switch (essai) {
                case 1: pendu1(); break;
                case 2: pendu2(); break;
                case 3: pendu3(); break;
                case 4: pendu4(); break;
                case 5: pendu5(); break;
                case 6: pendu6(); break;
                default:;
                }
            }
            puts(mask[mot]);
        }
    } while (cpt > 1 && essai <= 5);
    // Si le mot est trouvé
    if (cpt && essai <= 5) {
        printf("\n\nBravo !!! Maintenant vous meritez votre vie %s !!! Fantastique...\nLe mot \x82tait bien \"%s\"", nom, liste[mot]);
    }
    // Sinon
    else if (cpt = 0 || essai >= 6) {
        printf("\nD\x82sol\x82 %s ... Faites vos dernieres prieres... Vous serez pendu hahahahaha!!!", nom);
    }

    getch();
    return 0;
}



//Provoque l'aléatoire
int nbAleatoire(int min, int max) {
    int nbAl;
    nbAl = rand() % (max + 1) + min;
    return nbAl;
}


void pendu1() {
    printf(" _\n");
    printf("|_|\n\n");
}

void pendu2() {
    printf(" _\n");
    printf("|_|\n");
    printf(" |\n\n");
}

void pendu3() {
    printf(" _\n");
    printf("|_|\n");
    printf(" |\n |\n\n");
}

void pendu4() {
    printf(" _\n");
    printf("|_|\n");
    printf("_|_\n");
    printf(" |\n\n");
}

void pendu5() {
    printf(" _\n");
    printf("|_|\n");
    printf("_|_\n");
    printf(" |\n");
    printf("/ \n");
}

void pendu6() {
    printf(" _\n");
    printf("|_|\n");
    printf("_|_\n");
    printf(" |\n");
    printf("/ \\\n");
}










