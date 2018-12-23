/* structure dynamique et tableaux de structures dynamiques */

#include <stdio.h>
#include <stdlib.h>

// on va définir un nouveau type : structure eleve.
typedef struct {
    char nom[20];
    float note;
    } eleve;

void saisir_eleve(eleve * e);
void afficher_eleve(eleve e);
void reserver_eleve(int dim,eleve **e );
void liberer_eleve(eleve **e );

int main()
{
    eleve *moi=NULL;
    eleve *eux=NULL;

    reserver_eleve(1,&moi);
    reserver_eleve(2,&eux);

    saisir_eleve( moi);
    afficher_eleve( *moi);
    liberer_eleve(&moi);

    getchar();
    saisir_eleve( eux);
    getchar();
    saisir_eleve( eux+1);  // idem que : saisir_eleve(& eux[1]);


    afficher_eleve(eux[0]);
    afficher_eleve(eux[1]); // idem que : afficher_eleve( *(eux+1) );
    liberer_eleve(&eux);

    printf("\nPOUR CONTINUER FRAPPER UNE TOUCHE ");
    getchar();
    return 0 ;
}

// ajouter ici les définitions des deux fonctions déclarées ci-dessus.
void saisir_eleve(eleve * e)
{
    printf("TAPER LE NOM DE L'ELEVE :");
    scanf("%20[^\n]",e->nom);
    printf("TAPER LA NOTE DE L'ELEVE :");
    scanf("%f",&e->note);
}

/***************************/
void afficher_eleve(eleve e)
{
    printf("NOM DE L'ELEVE :%s\n",e.nom);
    printf("NOTE DE L'ELEVE :%f\n",e.note);
}

/*******************************/
void reserver_eleve(int dim,eleve **e )
{
    if (dim>0)
        *e=(eleve*)calloc(dim,sizeof(eleve));
    else *e=NULL;
}

/******************************/
void liberer_eleve(eleve **e )
{
    if (*e != NULL)
        {
            free(*e);
            *e=NULL;
        }
    else    printf(" pointeur nul sur libération !!!!");

}

