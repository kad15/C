/* manipulations sur les chaînes de caractères */
/* saisie de deux mots (mot1 et mot2)*/
/* concaténation de n fois mot1 suivi de mot2 avec un espace entre, pas d'espace à la fin */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saisir_chaine(char * *ch);
void traitement(int n,char* mot1,char * mot2,char ** resultat);
/*
La fonction doit construire dans resultat une chaîne constituée de la
concaténation n fois de mot1 suiv de mot2 avec un espace entre les deux mots.
Exemple : mot1="bon" , mot2="jour" , n=1 : resultat="bon jour"
          mot1="bon" , mot2="jour" , n=2 : resultat="bon jour bon jour"

*/

/********************/
int main()
{
char * resultat=NULL;
char *mot1=NULL;
char *mot2=NULL;
int n=0;

printf("TAPER LE MOT1 :");
saisir_chaine(&mot1);

printf("TAPER LE MOT2 :");
saisir_chaine(&mot2);

printf("TAPER LE NOMBRE N :");
scanf("%d",&n);

traitement(n,mot1,mot2, &resultat);
printf("RESULTAT :%s\n",resultat);
free(resultat);
resultat=NULL;
free(mot1);
mot1=NULL;
free(mot2);
mot2=NULL;
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
/****************************/
void traitement(int n,char* mot1,char * mot2,char ** resultat)
{
    /* version utilisant les fonctions de "string.h" */
    /* on construit la concaténation des deux mots avec un espace entre :*/
    char *mot=(char*)calloc(strlen(mot1)+strlen(mot2)+2,sizeof(char));
    /*  calcul de la longueur total de la chaîne resultat : */
    int len=n*(strlen(mot1)+strlen(mot2)+1)+(n-1)+1;
    int i=0;

    strcpy(mot,mot1);
    strcat(mot," ");
    strcat(mot,mot2);

    /* réservation dynamique de resultat : */
    *resultat=(char*)calloc(len,sizeof(char));
    for (i=0;i<n;i++)
    {
        strcat(*resultat,mot);
        if (i<n-1)
            strcat(*resultat," ");
    }
    free(mot);
    mot=NULL;

}
