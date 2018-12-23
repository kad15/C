/* structure et tableaux de structures */

#include <stdio.h>
#include <stdlib.h>

// on va définir un nouveau type : structure eleve.
typedef struct {
    char nom[20];
    float note;
    } eleve;

void saisir_eleve(eleve * e);
void afficher_eleve(eleve e);

int main()
{
    eleve moi;
    eleve eux[2];

    saisir_eleve( & moi);
    afficher_eleve( moi);

    getchar();
    saisir_eleve( & eux[0]);
    getchar();
    saisir_eleve( eux+1);  // idem que : saisir_eleve(& eux[1]);


    afficher_eleve(eux[0]);
    afficher_eleve(eux[1]); // idem que : afficher_eleve( *(eux+1) );

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
