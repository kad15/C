#include "annuaire.h"

int main(int argc,char **argv)
{
    //personne* tab[NB_MAX];
    // personne * tab[] désigne un tableau de pointeurs sur une structure de type personne
    personne** tab = malloc(sizeof(personne*)*NB_MAX);
	int nb_pers = 0;
	char sauve[16]; // contiendra le nom du fichier de sauvegarde

	if(argc==2)     //chargement du tableau à partir d'un fichier
    {   // copie dans la chaine sauve le nom du fichier fourni en paramètre limité
        strncpy(sauve,argv[1],sizeof(sauve)-1);
        sauve[sizeof(sauve)]='\0'; //on copie au rang 15 le char de fin de chaine
    }
    else
    {
       printf("nom du fichier de sauvegarde: ");
       if(saisir_chaine(sauve,sizeof(sauve))==1)
       {
            fprintf(stderr,"\nFin du programme...");
            return 1;
       }
    }

    nb_pers= chargefictext(tab,sauve);

    menu(tab,&nb_pers);

    sauvefictext(tab,nb_pers,sauve);

    return 0;
}


