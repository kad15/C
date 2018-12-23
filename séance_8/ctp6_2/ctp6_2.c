#include <stdio.h>
#include <stdlib.h>

#include "ctp6_2.h"

/* fonction affichant le contenu d'un fichier texte à l'écran */
void afficher_fichier(char * nomfic)
{
FILE * fic=fopen(nomfic,"r");
char temp[80];
if (fic != NULL)
    {
        int i=1;
        while((fgets(temp,80,fic)))
		{
			printf("ligne %d : %s \n",i,temp);
			i++;
		}
        fclose(fic);
    }
else
    {
        printf("pb d'ouverture du fichier %s en lecture!!!",nomfic);
    }
}

/* fonction écrivant dans un fichier texte le contenu du deuxième paramètre : */
void ecrire_fichier(char * nomfic, char * texte){
FILE * fic=fopen(nomfic,"a");
if (fic != NULL)
    {
        fprintf(fic,"%s \n",texte);
        fclose(fic);
    }
else
    {
        printf("pb d'ouverture du fichier %s en écriture!!!",nomfic);
    }
}

/****************************/
/* fonction qui saisit au clavier une chaîne de longueur quelconque,
    ==> réservation dynamique de la chaîne
*/
int saisir_chaine(char * *ch)
{
    char c;
    int taille=1;
    // réservation initiale de la chaîne :
    if (*ch != NULL)
        free(*ch);
    *ch = (char*)calloc(taille,sizeof(char));	/* chaîne de taille initiale 1 caractère */

    while ( (c=getchar()) != '\n' )
    {
        // on alloue une case en plus :
        *ch=realloc(*ch,sizeof(char)+taille);
        taille++;
        // on déplace le caractère de fin de chaîne :
        *(*ch + taille-1) = *(*ch + taille-2);
        // on stocke le caractère tapé :
        *(*ch + taille-2) = c;
    }

    return taille;

}
