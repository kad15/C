#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"


/*
void init_course(coureur t[MAX])
{

    for (int i = 0; i<MAX; i++) {
        t[i].dossard = -1;
    }

}


int nb_arrives(coureur t[MAX])
{
    int i=0;
    init_course(t);
    while(t[i].dossard != -1) i++;
    return i;
}
*/
/*
a) Fonction « saisircoureur » : fonction qui ajoute dans le tableau
de structures un coureur arrivé : on demandera à l’utilisateur le
nom, le numéro de dossard et son temps. On saisira pour le temps 3
valeurs : le nombre d’heures, le nombre de minutes et le nombre de
secondes.
typedef struct {
    char nom[30]; // nom du coureur
    int dossard;  // numéro de dossard du coureur
    int temps[3];  // temps à l'arrivée : temps[0] en heures, temps[1] en minutes, temps[2] en secondes
}coureur;
*/
void saisircoureur(coureur t[MAX], int * pt_n)
{
    coureur cc;
    printf("saisie du coureur arrivé. nom : ");
    scanf("%s",cc.nom);
//printf("zzzz %s",cc.nom);
    printf("dossard : ");
    scanf("%d",&cc.dossard);

    printf("temps hh mn ss : ");
    scanf("%d %d %d", &cc.temps[0], &cc.temps[1],&cc.temps[2]);

    t[*pt_n] = cc;   // printf("rrrrr  %d : \n",cc.dossard);
    *pt_n += 1;

}

/********************************************************/

/*
b) Fonction « affichercourse» : la fonction affiche les n premiers
coureurs du tableau dans l’ordre où ils ont été rentrés. On affichera
un coureur sur une ligne, en respectant la forme suivante :
Nom : Albert dossard : 1 temps : 01:20:09
Pour afficher les heures, minutes et secondes, on pourra utiliser le
formatage suivant dans un printf :
"%02d :%02d :%02d"
Le format "%02d" permet d’afficher un entier sur deux caractères,
en complétant à gauche par des zéros si nécessaire.


*/
void affichercourse(coureur t[MAX],int n)
{

    for (int i = 0; i<n; i++) {
        printf("Nom : %s  dossard : %4d  temps : %02d:%02d:%02d\n",t[i].nom,t[i].dossard, t[i].temps[0],t[i].temps[1],t[i].temps[2] );
    }
    printf("\n\n**************************************\n\n");

}

/********************************************************/

/*
• c) Fonction « sauvegardercourse » : la fonction sauvegarde dans
un fichier texte les coureurs arrivés de la course stockés dans le
tableau. On écrira les données d’un coureur sur une ligne du fichier
comme dans la fonction précédente. On pourra utiliser le formatage
précédent pour le temps (avec un « fprintf »).


*/


void sauvegardercourse(coureur t[MAX],int n, char nomfic[])
{
    FILE* fic = NULL;
    fic = fopen(nomfic, "w");
    if (fic != NULL)
    {
   fprintf(fic,"Nom     dossard      temps \n");
   for (int i = 0; i<n; i++)
   {
     fprintf(fic, "%s  %4d  %02d:%02d:%02d\n",t[i].nom,t[i].dossard, t[i].temps[0],t[i].temps[1],t[i].temps[2] );
   }
   printf("course sauvegardee dans le fichier %s\n", nomfic);
   fclose(fic); // On ferme le fichier qui a été ouvert

    }
    else
    {
        printf("Impossible d'ecrire dans le fichier %s\n", nomfic);
    }

}


/********************************************************/
/*
• d) Fonction « trier » : la fonction réalise un tri du tableau de
structures en fonction du temps. On pourra utiliser un tri à bulles
sur le tableau en utilisant le champ temps comme clé de tri. On
pourra convertir le temps en secondes pour comparer deux
coureurs.

*/
int conv(coureur c){
   return c.temps[0]*3600 + c.temps[1]*60 + c.temps[2];
}


void trier(coureur t[MAX],int  n)
{
int en_desordre = 1;
	int i,j;
	coureur temp;

	for (i = 0; (i < n) && en_desordre; ++i)
	{
		en_desordre = 0;
		for (j = 1; j < (n - i); ++j)
		{

			if ( conv(t[j-1]) > conv(t[j]) )
			{
				temp = t[j-1];
				t[j-1] = t[j];
				t[j] = temp;
				en_desordre = 1;
 			}
		}
	}



}

