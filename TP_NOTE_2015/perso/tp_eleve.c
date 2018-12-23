#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

int main()
{
    // declaration des variables :
    // on utilise un tableau de MAX coureurs pour stocker les coureurs :
    coureur t[MAX];
    // n : nombre de coureurs arrives :
    int n=0;
    // nom du fichier de sauvegarde :
    //char nomfic[]="coureurs.txt";
    // variable choix :
    int choix=1;

    // boucle de traitement :
    while (choix !=0)
    {
        printf(" ********* Menu **********\n");
        printf(" 0 : quitter.\n");
        printf(" 1 : saisir une arrivee.\n");
        printf(" 2 : afficher les coureurs arrives.\n");
        printf(" 3 : sauvegarder tous les coureurs arrives.\n");
        printf(" 4 : trier les arrivees.\n");
        printf("\n");
        scanf("%d",&choix);
        getchar();
        switch(choix)
        {
        case 0 :
            break;
        case 1 :
            saisircoureur(&n, t);
            break;
        case 2 :
            affichercourse(n, t);
            break;
        case 3 :
            sauvegardercourse(n,t);
            break;
        case 4 :
            trier();
            break;
        default :
            printf("\n choix invalide, recommencez.");
        }
    }
    return 0;
}


