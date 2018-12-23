/* saisie d'une chaîne de caractères de taille non définie */
#include <stdio.h>
#include <stdlib.h>

/* fonction qui saisit une chaîne de taille non définie (réservation dynamique) */
/* retourne la taille de la chaîne (nombre de caractères + '\0') */
int saisir_chaine(char * *ch);

int main()
{
char *adr_deb=NULL;
int taille=0;

printf("\nENTRER UN TEXTE ('\n' pour terminer): ");
taille=saisir_chaine(&adr_deb);

/* resultats */
printf("\nCHAINE SAISIE : %s\n",adr_deb);
printf("\nTAILLE : %d\n",taille);
free(adr_deb); // libération mémoire de la zone réservée
adr_deb=NULL;
printf("\nPOUR CONTINUER FRAPPER UNE TOUCHE ");
getchar();
return 0 ;
}
/********************************/

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
