#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

int main()
{
    // d�claration des variables :
    // on utilise un tableau de MAX coureurs pour stocker les coureurs :
    .................................;
    // n : nombre de coureurs arriv�s :
    .................................;
    // nom du fichier de sauvegarde :
    .................................;
    // variable choix :
    .................................;

    // boucle de traitement :
    while (choix !=0)
        {
            printf(" ********* Menu **********\n");
            printf(" 0 : quitter.\n");
            printf(" 1 : saisir une arriv�e.\n");
            printf(" 2 : afficher les coureurs arriv�s.\n");
            printf(" 3 : sauvegarder tous les coureurs arriv�s.\n");
            printf(" 4 : trier les arriv�es.\n");
            printf("\n");
            scanf("%d",&choix);
            getchar();
            switch(choix)
            {
                case 0 : break;
                case 1 : saisircoureur(...........................);
                    break;
                case 2 : affichercourse(..........................);
                    break;
                case 3 : sauvegardercourse(........................);
                    break;
                case 4 : trier(...............................);
                    break;
                default : printf("\n choix invalide, recommencez.");
            }
        }
    return 0;
}


