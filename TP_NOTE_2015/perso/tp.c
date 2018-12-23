#include <stdio.h>
#include <stdlib.h>
#include "tp.h"

/*
typedef struct {
    char nom[30]; // nom du coureur
    int dossard;  // numéro de dossard du coureur
    int temps[3];  // temps à l'arrivée : temps[0] en heures, temps[1] en minutes, temps[2] en secondes
}coureur;
*/
//**********************************************
void saisircoureur(int * n, coureur t[MAX])
{
    char tt[20];
    printf("Nom du coureur ? ");
    getchar();
    scanf("%50[^\n]", t[*n].nom);
    printf("Numero de dossard ? ");
    getchar();
    scanf("%d", &t[*n].dossard);
    printf("Temps coureur au format hh mn sec ? ");
    getchar();
    scanf("%20[^\n]", tt);
    sscanf(tt,"%d %d %d", &t[*n].temps[0], &t[*n].temps[1], &t[*n].temps[2]);
    (*n)++;
}

//***********************************************
void affichercourse(int n, coureur t[MAX])
{
    int i = 0;
    for (i=0; i<n; i++)
    {
        printf("Nom : %s dossard : %d temps : %02d:%02d:%02d \n", t[i].nom,t[i].dossard, t[i].temps[0], t[i].temps[1], t[i].temps[2]);
    }

}


//************************************************
void sauvegardercourse(int n, coureur t[])
{
    int i = 0;
    char nomfic[50];
    printf("Nom du fichier de sauvegarde ? ");
    scanf("%50s",nomfic);
    FILE * fic = NULL;
    fic=fopen(nomfic,"w");

    if((fic=fopen(nomfic,"w"))==NULL)
    {
        printf("Ouverture du fichier impossible");
        getchar();
        exit(1);
    }
    else // ouverture du fichier ok
    {
        fprintf(fic,"coureur  dossard temps \n");
        for (i=0; i<n; i++)
        {
            if (fprintf(fic, "%s %d %02d:%02d:%02d \n", t[i].nom, t[i].dossard, t[i].temps[0], t[i].temps[1], t[i].temps[2])==5)
                printf("transfert reussi dans le fichier %s ", nomfic);
                }
    fclose(fic);
        }



}

//************************************************
void trier()
{
}
