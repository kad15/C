#include "annuaire.h"

int chargefictext(personne* t[],char* nomfic)
{
	FILE *fic;
	int nb_pers=0,continuer=0;
	char tampon[80];

	if((fic=fopen(nomfic,"r"))==NULL)
    {
		char rep[3] ="N";
        printf("ouverture impossible, on continue ?");
        saisir_chaine(rep,3);
        if (toupper(rep[0]) != 'O')
            exit(1);
	}
	else
	{
		continuer= (fgets(tampon,80,fic)!=NULL);
		vider_tampon(fic);
		while(continuer)
		{
			t[nb_pers]=malloc(sizeof(personne));
			sscanf(tampon,"%[^\n]",tampon);		// suppression caractere fin de chaine
			char* tmp = strrchr(tampon,';');	//permet de renvoyer la dernier position du ;
			strncpy(t[nb_pers]->tel,tmp+1,11);  //recopie du numtel
			t[nb_pers]->tel[12]='\0';
			tmp[0]=0;						// on efface le dernier ;
			tmp = strrchr(tampon,';');
			strncpy(t[nb_pers]->prenom,tmp+1,19);
			t[nb_pers]->prenom[19]='\0';
			tmp[0]=0;
			strncpy(t[nb_pers]->nom,tmp+1,19);
			t[nb_pers]->nom[19]='\0';
			nb_pers++;
			continuer= (fgets(tampon,80,fic)!=NULL);
            vider_tampon(fic);

		}
		fclose(fic);
	}

	return nb_pers;
}

void sauvefictext(personne* t[],int nb_pers,char*nomfic)
{
	FILE *fic;
	int i;
   	char tampon[60];

	if((fic=fopen(nomfic,"w"))==NULL)
	{
		printf("Pb fichier, sauvegarde impossible");
		getchar();
		exit(1);
	}
	else
	{
		for(i=0;i<nb_pers;i++)
		{
      		tampon[0]='\0';
			strcat(tampon,t[i]->nom);
         	strcat(tampon,";");
         	strcat(tampon,t[i]->prenom);
         	strcat(tampon,";");
         	strcat(tampon,t[i]->tel);
         	strcat(tampon,"\n");
         	fputs(tampon,fic);
         	free(t[i]);
		}

		fclose(fic);
	}
}
