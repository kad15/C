
#include <stdio.h>
int voyelle(int c) ;

int  main()
{
char c;

printf("ENTRER UN CARACTERE: ");
/* ajouter une instruction pour saisir au clavier un caractère */

/*
on appelle ici la fonction "voyellle" :
*/
if (voyelle(c))
    printf("CE CARACTERE EST UNE VOYELLE\n");
else
    printf("CE CARACTERE N'EST PAS UNE VOYELLE\n");

printf("POUR CONTINUER FRAPPER UNE TOUCHE ");
getchar();
return 0 ;
}

/* ajouter ici la définition de la fonction voyelle déclarée au dessus : */
