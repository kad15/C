
#include <stdio.h>
#include <stdlib.h>
int main()
{
int *pti;
char *ptc;
int tab[5] = {1,2,3,4,5};
char chaine[4] = {'a','b','c','\0'};

// parcours du tableau "tab" avec le pointeur sur entier "pti" :
for (pti= tab; pti < (tab+5) ; pti++ )
    printf(" adresse = %p   valeur = %d\n",pti,*pti);

// On va écrire la boucle précédente en utilisant une notation basée sur la notion de tableau ([]) :
 for (pti= &tab[0]; pti < (&tab[0] + sizeof(tab)/sizeof(int)) ; pti++ )
    printf(" adresse = %p   valeur = %d\n",pti, pti[0]);

// écrire ici de la même façon que précédemment les deux boucles
// qui affichent le contenu du tableau "chaine" :

printf("\nPOUR CONTINUER FRAPPER UNE TOUCHE ");
getchar();
return 0 ;
}

