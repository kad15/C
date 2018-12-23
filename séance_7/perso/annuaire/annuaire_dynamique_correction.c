//#include <stdlib.h>
#include "halloc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NB_MAX 100

typedef struct {
	char nom[20];
	char prenom[20];
	char tel[12];
	} personne;

/* fonction affichant les options offertes par le menu à l'utilisateur */
void afficherMenu();

/* fonction de saisie des personnes */
void saisirPersonne(int *ind,personne *t[]);

/* fonction de suppression des personnes */
void supprimerPersonne(int *ind, personne * t[]);

/*fonction d'édition de toutes les personnes */
void editerAnnuaire(int ind,personne *t[]);

/* fonction  mise en majuscules */
void maj(char * ch);

int main()
{
    personne * tab[NB_MAX];  // tableau de pointeurs
    int index=0; // nombre de personnes réelles dans le tableau

    char rep;
    do {
        afficherMenu();
        rep=toupper(getchar());
        getchar();   //pour lire le caractere de passage à la ligne
        switch(rep) {
            case 'A' : saisirPersonne(&index,tab);break; //passage par adresse car modification de index ds la fonction
            case 'S' : supprimerPersonne(&index,tab);break;
            case 'V' : editerAnnuaire(index,tab);break;
            case 'Q' : break;
		}
    }while (rep != 'Q');
     ConteneurMalloc_Affiche (true); // affiche les fuites mémoires
    getchar();
    return 0;
}

/* ******************************** */
/* fonction affichant les options offertes par le menu à l'utilisateur */
void afficherMenu(){

    printf("\t\t\t\t MENU PRINCIPAL\n\n\n\n");
    printf("\t\t Saisir des personnes          A\n");
    printf("\t\t Supprimer des personnes       S\n");
    printf("\t\t Visualiser l'annuaire         V\n");
    printf("\t\t Quitter                       Q\n\n");
    printf("\t\t Votre choix :");
}

/* ***************************** */
/* fonction de saisie des personnes */
void saisirPersonne(int *index,personne ** t){
    int sortie,trouve,i;

    printf("\tPour revenir au menu, tapez entree \n");
    do{
        personne *p=NULL;
        sortie=0;
        /* on réalloue le tableau pour l'agrandir de la taille d'une structure en plus */
        p=(personne *)calloc(1,sizeof(personne));
        if ( p == NULL)  // pb d'allocation !!
            {
                 fprintf(stderr,"allocation impossible");
                 exit(EXIT_FAILURE);  // on arrête le main !!!
            }
        /* sinon allocation ok : on continue */

        p->nom[0] ='\0';
        printf("\tNOM :");
        scanf("%19[^\n]",p->nom);
        getchar();
        if (p->nom[0] != '\0') // le nom n'est pas vide
            {
                sortie=1;
                maj(p->nom);
                printf("\tPRENOM :");
                scanf("%19[^\n]",p->prenom);
                getchar();
                printf("\ttel :");
                scanf("%11[^\n]",p->tel);
                getchar();
                // recherche du bon indice où insérer cette personne  :
                i=0;
                trouve=0;
                while(i< *index && !trouve)  // on recherche la personne plus grande
                    {
                    if ((strcmp(t[i]->nom,p->nom) > 0)) // emplacement trouvé
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
        else free(p);
        } while(sortie);
}

/* *************************************** */
/* fonction de suppression des personnes   */
void supprimerPersonne(int *index, personne * t[]) {
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
      if (!(strcmp(t[i]->nom,nomtmp))) // le nom est trouvé
      {
         //on décale vers la gauche toutes les personnes en écrasant la personne trouvée
         int j;
         // on libère d'abord la personne trouvée :
         free(t[i]);
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
void editerAnnuaire(int index,personne *t[]){
    int i=0;
    if(index == 0)
        printf("annuaire vide !\n");
    while(i<index)
	 {
        printf("\nnom :%s \nprenom :%s \ntel :%s \n\n",t[i]->nom,t[i]->prenom,t[i]->tel);
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
