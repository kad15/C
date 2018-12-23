#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "annuaire.h"






void chargerFichierTexte(char * nomfic, taille, personne * tab){
    int i =0;
    int booltrue = 1; // faux = à 0 vrai sinon
    char ligne[50];
	FILE* f=fopen(nomfic,"r");
	if(f!=NULL)
	{
		do {
            fgets(ligne,50,f);
            sscanf(ligne,"%s",tab[i].nom);
            fgets(ligne,50,f);
            sscanf(ligne,"%s",tab[i].prenom);
            if(fgets(ligne,50,f) !=NULL)
            {
                sscanf(ligne,"%s",tab[i].tel);
            }
            else
                booltrue = 0;
            i++;
            }
        while (booltrue);
        fclose(f);
	}
	else
	{
 		fprintf("afficher_fichier : impossible ouvrir %\n",nomfic);
 		exit(1);
	}
}



void sauverFichierTexte(char * nomfic, int taille, personne *tab){
    int i;
    FILE *f=fopen(nomfic,"a");
	if(f!=NULL){
	//fprintf(f, "%s \n",texte);
	for(i=0;i<taille;i++){
        fprintf(f,"%s \n", tab[i].nom);
        fprintf(f,"%s \n", tab[i].prenom);
        fprintf(f,"%s \n", tab[i].tel);
	}
	fclose(f);
	}
	else
	{
		printf("ecrirefichier:Impossible ouvrir fichier %s !\n", nomfic);
		exit(1);
	}

}

/* ******************************** */
/* fonction affichant les options offertes par le menu à l'utilisateur */
void afficherMenu(){

    printf("\t\t\t\t MENU PRINCIPAL\n\n\n\n");
    printf("\t\t Saisir des personnes          A\n");
    printf("\t\t Supprimer des personnes       S\n");
    printf("\t\t Visualiser l'annuaire         V\n");
    printf("\t\t Enregistrer l'annuaire        E\n");
    printf("\t\t Enregistrer l'annuaire        C\n");
    printf("\t\t Quitter                       Q\n\n");
    printf("\t\t Votre choix :");
}

/* ***************************** */
/* fonction de saisie des personnes avec tri alphabétique sur le nom */
void saisirPersonne(int *index,personne t[]){
    personne p;
    int sortie, trouve, i;

    printf("\tPour revenir au menu, tapez entree \n");
    do{
        sortie=0;
        if (*index==NB_MAX)
        {
            printf("\ntableau complet...\nnouvelle saisie impossible\n");
            getchar();
        }
        else
        {
            //strcpy(nomtmp,"");
            p.nom[0] ='\0';
            printf("\tNOM :");
            scanf("%19[^\n]",p.nom);
            getchar();
            if (p.nom[0] != '\0') // le nom n'est pas vide
            {
                sortie=1;
                maj(p.nom);
                printf("\tPRENOM :");
                scanf("%19[^\n]",p.prenom);
                getchar();
                printf("\ttel :");
                scanf("%11[^\n]",p.tel);
                getchar();
                // recherche du bon indice où insérer cette personne  :
                i=0;
                trouve=0;
                while(i< *index && !trouve)  // on recherche la personne plus grande
                    {
                    if ((strcmp(t[i].nom,p.nom) > 0)) // emplacement trouvé
                        {
                        //on insère la nouvelle personne : pour cela, on décale vers la fin
                        int j=i;
                        for (j= *index;j>i; j--)
                            t[j]=t[j-1];
                        // on insère la nouvelle personne :
                        t[i]=p;
                        trouve=1;
                        }
                    else
                        i++;
                    }
                if (i== *index || i==0) // insertion en tête ou à la fin
                    t[i]=p;
                (*index) ++; // on incrémente le nombre de personnes
            }
        }
    }while(sortie);
}

/* *************************************** */
/* fonction de suppression des personnes   */
void supprimerPersonne(int *index, personne t[]) {
   char nomtmp[20];
   int i;
   int sortie=0;

   printf("quelle personne voulez-vous supprimer :");
   scanf("%19[^\n]",nomtmp);
   maj(nomtmp);
   getchar();
   i=0;
   while(i< *index && !sortie)  // on recherche le nom
   {
      if (!(strcmp(t[i].nom,nomtmp))) // le nom est trouvé
      {
         //on décale vers la gauche toutes les personnes en écrasant la personne trouvée
         int j;
         for (j=i;j<*index-1; j++)
            t[j]=t[j+1];
         (*index) --;  // on décrémente le nombre de personnes
         sortie=1;
      }
      else i++;
   }
   if (!sortie)
      printf("\n personne non trouvée !!!!!!!\n");
   else
      printf("\n La personne %s a été supprimée !\n",nomtmp);
}

/* ***************************************** */
/*fonction d'édition de toutes les personnes */
void editerAnnuaire(int index,personne t[]){
    int i=0;
    if(index == 0)
        printf("annuaire vide !\n");
    while(i<index)
	 {
        printf("\nnom :%s \nprenom :%s \ntel :%s \n\n",t[i].nom,t[i].prenom,t[i].tel);
        i++;
	 }
}

/* ***************************************** */
/* fonction  mise en majuscules */
void maj(char * ch)
{
    int i,imax=strlen(ch);
    for (i=0;i<imax;i++)
        ch[i]=toupper(ch[i]);

}

