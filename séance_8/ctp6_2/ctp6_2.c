#include <stdio.h>
#include <stdlib.h>

#include "ctp6_2.h"

/* fonction affichant le contenu d'un fichier texte � l'�cran */
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

/* fonction �crivant dans un fichier texte le contenu du deuxi�me param�tre : */
void ecrire_fichier(char * nomfic, char * texte){
FILE * fic=fopen(nomfic,"a");
if (fic != NULL)
    {
        fprintf(fic,"%s \n",texte);
        fclose(fic);
    }
else
    {
        printf("pb d'ouverture du fichier %s en �criture!!!",nomfic);
    }
}

/****************************/
/* fonction qui saisit au clavier une cha�ne de longueur quelconque,
    ==> r�servation dynamique de la cha�ne
*/
int saisir_chaine(char * *ch)
{
    char c;
    int taille=1;
    // r�servation initiale de la cha�ne :
    if (*ch != NULL)
        free(*ch);
    *ch = (char*)calloc(taille,sizeof(char));	/* cha�ne de taille initiale 1 caract�re */

    while ( (c=getchar()) != '\n' )
    {
        // on alloue une case en plus :
        *ch=realloc(*ch,sizeof(char)+taille);
        taille++;
        // on d�place le caract�re de fin de cha�ne :
        *(*ch + taille-1) = *(*ch + taille-2);
        // on stocke le caract�re tap� :
        *(*ch + taille-2) = c;
    }

    return taille;

}
