#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NB_MAX 100

typedef struct {
	char nom[20];
	char prenom[20];
	char tel[12];
	} personne;

/* fonction affichant les options offertes par le menu à l'utilisateur */
void afficherMenu();

/* fonction de saisie des personnes */
...

/* fonction de suppression des personnes */
...

/*fonction d'édition de toutes les personnes */
...

int main()
{
    personne*  tab[NB_MAX];  // tableau de pointeurs
    int index=0; // nombre de personnes réelles dans le tableau

    char rep;
    do {
        afficherMenu();
        rep=toupper(getchar());
        getchar();   //pour lire le caractere de passage à la ligne
        switch(rep) {
            case 'A' : saisirPersonne(&index,tab);break; //passage par adresse car modification de index ds la fonction et allocation de chaque nouvelle structure personne
            case 'S' : supprimerPersonne(&index,tab);break;  // réduction du tableau par libération mémoire de la structure personne concernée
            case 'V' : editerAnnuaire(index,tab);break;
            case 'Q' : break;
		}
    }while (rep != 'Q');

    return 0;
}

/* ******************************** */
/* fonction affichant les options offertes par le menu à l'utilisateur */
void afficherMenu(){

    printf("\t\t\t\t MENU PRINCIPAL\n\n\n\n");
    printf("\t\t Saisir des personnes          A\n");
    printf("\t\t Supprimer des personnes       S\n");
    printf("\t\t Visualiser l'annuaire         V\n");
    printf("\t\t Quitter                       Q\n\n");
    printf("\t\t Votre choix :");
}


