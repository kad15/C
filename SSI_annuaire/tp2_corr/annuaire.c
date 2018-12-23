#include "annuaire.h"

/* fonction affichant les options offertes par le menu à l'utilisateur */
void affich_menu(void){
	system("clear");	//efface l ecran
    printf("\t\t\t\t MENU PRINCIPAL\n\n\n\n");
    printf("\t\t Saisir des personnes          A\n");
    printf("\t\t Modifier des personnes        M\n");
    printf("\t\t Supprimer des personnes       S\n");
    printf("\t\t Visualiser l'annuaire         V\n");
    printf("\t\t Quitter                       Q\n\n");
    printf("\t\t Votre choix :");
}

/* fonction du menu principal */
void menu(personne* t[], int* nb_pers){
    char rep[3]="E";    //
    do {
        affich_menu();
        saisir_chaine(rep,3);
        switch(toupper(rep[0])) {
            case 'A' : saisir_personne(t,nb_pers);break;
            case 'M' : modifier_personne(t,*nb_pers);break;
            case 'S' : supprimer_personne(t,nb_pers);break;
            case 'V' : editer_annuaire(t,*nb_pers);break;
            case 'Q' : break;
            case 'E' : ;
            default	 : printf("erreur de saisie");
		}
    }while (toupper(rep[0]) != 'Q');
}

/* fonction de saisie des personnes */
void saisir_personne(personne* t[],int* nb_pers){

    system("clear");

    if (*nb_pers==NB_MAX){
    	printf("\ntableau complet...\nnouvelle saisie impossible\n");
    	getchar();
        }
    else
    {
    	t[*nb_pers]=malloc(sizeof(personne));
    	//saisie nom
    	printf("\tNOM :");
        while(saisir_chaine(t[*nb_pers]->nom,20))
        {
            printf("\tNOM :");
        }
        //saisie prenom
        printf("\tPRENOM :");
        while(saisir_chaine(t[*nb_pers]->prenom,20))
        {
            printf("\tPRENOM :");
        }
        //saisie tel
        printf("\ttel :");
        while(saisir_chaine(t[*nb_pers]->tel,12))
        {
            printf("\ttel :");
        }
        (*nb_pers)++;
     }
}

/* fonction de suppression des personnes */
void supprimer_personne(personne* t[], int* nb_pers) {
    char tmp[20];
    int i=0,trouve=0;

    system("clear");
    printf("quelle personne voulez-vous supprimer :");
    saisir_chaine(tmp,sizeof(tmp));

	while (i< *nb_pers && !trouve)  // on recherche le nom
	{
        if (!(strcmp(t[i]->nom,tmp))) // le nom est trouvé
		{
            t[i]=t[*nb_pers-1];
            (*nb_pers)--;
            printf("\nContact supprime");
            trouve=1;
     	}
		i++;
	}
	if (!trouve)
		printf("\n La personne ne setrouve pas dans l'annuaire");
	getchar();
}

/* fonction de modification d'une personne */
void modifier_personne(personne* t[], int nb_pers) {
    char tmp[20];
    int i=0,trouve=0;

    system("clear");
    printf("quelle personne voulez-vous modifier :");
    saisir_chaine(tmp,sizeof(tmp));

    while (i<nb_pers && !trouve)  // on recherche le nom
	{
        if (!strcmp(t[i]->nom,tmp)) // le nom est trouvé
		{
            editer_personne(*(t[i]));
            //saisie nom
            printf("\tNOM :");
            while(saisir_chaine(t[i]->nom,20))
            {
                printf("\tNOM :");
            }
            //saisie prenom
            printf("\tPRENOM :");
            while(saisir_chaine(t[i]->prenom,20))
            {
                printf("\tPRENOM :");
            }
            //saisie tel
            printf("\ttel :");

            while(saisir_chaine(t[i]->tel,12));
            {
                printf("\ttel :");
            }
        	trouve=1;
        	printf("\n Contact modifie");
     	}
		i++;
	}

	if (!trouve)
		printf("\n La personne ne se trouve pas dans l'annuaire");
	getchar();
}

/*fonction d'édition d'une personne */
void editer_personne(personne p) {
    printf("\nnom :%s \nprenom :%s \ntel :%s \n\n",p.nom,p.prenom,p.tel);
}

/*fonction d'édition de toutes les personnes */
void editer_annuaire(personne* t[], int nb_pers) {
    int i=0;

    if(nb_pers==0)
        printf("annuaire vide !\n");
    while(i<nb_pers)
		editer_personne(*(t[i++]));

	getchar();	//permet ici de conserver l affichage avant retour au menu
}
