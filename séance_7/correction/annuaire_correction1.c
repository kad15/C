#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NB_MAX 500

typedef struct {
	char nom[20];
	char prenom[20];
	char tel[12];
	} personne;

/* fonction affichant les options offertes par le menu à l'utilisateur */
void afficherMenu();

/* fonction de saisie des personnes */
void saisirPersonne(int *ind,personne t[]);

/* fonction de suppression des personnes */
void supprimerPersonne(int *ind, personne t[]);

/*fonction d'édition de toutes les personnes */
void editerAnnuaire(int ind,personne t[]);

/* fonction  mise en majuscules */
void maj(char * ch);
/////////////////////////////////////////////////

int main()
{
    personne tab[NB_MAX];  // tableau contenant toutes les personnes
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
void saisirPersonne(int *index,personne t[]){
    char nomtmp[20];
    int sortie,i;

    printf("\tPour revenir au menu, tapez entree \n");
    do{
        sortie=0;
        /* Le premier emplacement de libre dans le tableau est à l'indice index */
        i=*index;
        if (i==NB_MAX)
        {
            printf("\ntableau complet...\nnouvelle saisie impossible\n");
            getchar();
        }
        else
        {
            //strcpy(nomtmp,"");
            nomtmp[0] ='\0';
            printf("\tNOM :");
            scanf("%19[^\n]",nomtmp);
            getchar();
            if (nomtmp[0] != '\0') // le nom n'est pas vide
            {
                sortie=1;
                maj(nomtmp);
                strcpy(t[i].nom,nomtmp);
                printf("\tPRENOM :");
                scanf("%19[^\n]",t[i].prenom);
                getchar();
                printf("\ttel :");
                scanf("%11[^\n]",t[i].tel);
                getchar();
                (*index) ++;
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
         //on remplace la personne supprimee par le dernier
         t[i] = t[*index-1];
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

