#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

int main()
{
    // déclaration des variables :
    // on utilise un tableau de MAX coureurs pour stocker les coureurs :
    coureur t[MAX];
    // n : nombre de coureurs arrivés :
   //int n = nb_arrives(t);
   int  n=0;

    // nom du fichier de sauvegarde :
    char nomfic[]="sauve.txt";
    // variable choix :
    int choix=5;

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
                case 0 : break;
                case 1 : saisircoureur(t,&n);
                    break;
                case 2 : affichercourse(t,n);
                    break;
                case 3 : sauvegardercourse(t,n,nomfic);
                    break;
                case 4 : trier(t,n);
                    break;
                default : printf("\n choix invalide, recommencez.");
            }
        }
    return 0;
}


