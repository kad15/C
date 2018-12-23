#include "tp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
a - Fonction « initApt» : fonction qui initialise chaque case du
tableau en affectant la valeur de l'expression INITAPT au nom de
chaque aéroport.
*/

// initialisation de chaque case du tableau (champ nom égal à INITAPT):
void initApt(TableauApt tapt)
{
    for(int i = 0; i<MAX; i++) {
        strcpy(tapt[i].nom, INITAPT);
    }

}



// rajoute un aéroport dans le tableau "tapt" par saisie clavier :
void saisirApt(TableauApt tapt)
{

// on cherche la premiere place libre
    int i =0;
// strcmp renvoie 0 si les chaines sont identiques mais 0 correspond à FAUX dans le while
// si on rencontre un INITAPT, on a 0 et on sort du while
    while (strcmp(tapt[i].nom, INITAPT)) {
        i++;
    }
    if (i>=MAX) printf("Tableau plein ! \n");
// en sortie du while i donnele rang du 1er emplacement vide
//printf("Saisir le code Aeroport suivi du nombre de pistes et du nom de ces dernieres. \n");    printf("Exemple : LFPO 2 27 09\n\n\n");
    printf("Saisir le code Aeroport 4 caracteres majuscule. Exemple : LFPO \n");
    scanf("%4s",tapt[i].nom);

    printf("Saisir le nombre de pistes de l'aéroport.  \n");
    scanf("%d", &tapt[i].nbpistes);
    // reservation de nbpistes chaine de 10 char
    tapt[i].nomspistes = (chaine*)calloc(tapt[i].nbpistes, sizeof(chaine));  // tableau dynamique à allouer contenant le nom de chacune des pistes
    for (int n = 0; n<tapt[i].nbpistes; n++) {
        printf("Saisir le nom de piste . Exemple : 27 \n");
        scanf("%9s",tapt[i].nomspistes[n]); // nompistes
    }


}



/*

Fonction « afficherApt» : la fonction affiche les aéroports
stockés dans le tableau : on affichera le nom, le nombre de pistes et
le nom de chacune des pistes de chaque aéroport.

*/
// affichage des données de chaque aeroport à l'écran :
void afficherApt(TableauApt tapt)
{

    for(int i = 0; i<MAX; i++) {
        if (strcmp(tapt[i].nom, INITAPT)) {
            printf("Aeroport : %4s, Nombre de pistes : %d, liste des pistes : ", tapt[i].nom, tapt[i].nbpistes);
            for (int n = 0; n<tapt[i].nbpistes; n++) printf(" %2s", tapt[i].nomspistes[n]);
            printf("\n");
        }
    }

    printf("\n\n\n");
}





/*
d) Fonction « sauvegarderApt » : la fonction sauvegarde dans un
fichier texte chacun des aéroports stockés dans le tableau. On écrira
les données d’un aéroport sur une ligne du fichier.
Avec l’exemple précédent, on écrira la ligne suivante :
LFPO 2 27 09
*/
// sauvegarde dans le fichier des données de chaque aeroport du tableau :
void sauvegarderApt(TableauApt tapt, char * nomfic)
{
    FILE * fic= NULL;
    fic = fopen(nomfic,"a+");
    char buf1[81];
    char buf2[61];
    if(fic == NULL) {
        printf("erreur lecture fichier");
    } else {
        for (int i = 0; i<MAX; i++) {
            if (strcmp(tapt[i].nom, INITAPT)) {
                sprintf(buf1," %4s %d ", tapt[i].nom, tapt[i].nbpistes);

                for (int n = 0; n<tapt[i].nbpistes; n++) {
                    sprintf(buf2," %2s ", tapt[i].nomspistes[n]);
                    strcat(buf1,buf2);
                }
                strcat(buf1,"\n");
                fputs(buf1,fic);
                //if(fputs(buf1,fic)!=EOF) printf("sauvegarde reussie !\n");
            }
        }

        fclose(fic);
    }
}
/*
d) Fonction « trierApt » : la fonction réalise un tri du tableau en
fonction du nombre de pistes croissant. On pourra utiliser un tri par
sélection (voir algo ci-dessous) sur le tableau en utilisant le champ
« nbpistes » comme clé de tri.
*/

void trierApt(TableauApt tapt)
{
    int en_desordre = 1;
    for (int i = 0; (i < MAX) && en_desordre; ++i) {
        en_desordre = 0;
        for (int j = 1; j < (MAX - i); ++j) {
            if (tapt[j-1].nbpistes > tapt[j].nbpistes) {

                swap(&tapt[j-1], &tapt[j]);
                en_desordre = 1;
            }
        }
    }
}


/*
void swap(int* a, int* b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}





void swap(Apt  apt1, Apt  apt2) {
    chaine nom;
    strcpy(nom, apt1.nom);
    strcpy(apt1.nom,apt2.nom);
    strcpy(apt2.nom,nom);

    int tmp;
    tmp = apt1.nbpistes;
    apt1.nbpistes = apt2.nbpistes;
    apt2.nbpistes = tmp;

    chaine * ptr;
    ptr = apt1.nomspistes;
    apt1.nomspistes = apt2.nomspistes;
    apt2.nomspistes = ptr;

}
*/

void swap(Apt  * apt1, Apt  * apt2)
{
    Apt temp;
    temp = *apt1;
    *apt1 = *apt2;
    *apt2 = temp;

}
