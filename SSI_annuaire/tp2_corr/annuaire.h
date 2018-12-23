#ifndef _ANNUAIRE_H
#define _ANNUAIRE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h> // pour la fonction toupper()

#define NB_MAX 10000001

typedef struct {
	char nom[20];
	char prenom[20];
	char tel[12];
	} personne;

/* fonction affichant les options offertes par le menu à l'utilisateur */
void affich_menu(void);

/* fonction du menu principal */
void menu(personne* t[], int* nb_pers);

/* fonction de saisie des personne */
void saisir_personne(personne* t[], int* nb_pers);

/* fonction de suppression des personnes */
void supprimer_personne(personne* t[], int* nb_pers);

/* fonction de modification des personnes */
void modifier_personne(personne* t[], int nb_pers);

/*fonction d'édition d'une personne */
void editer_personne(personne p);

/*fonction d'édition de toutes les personnes */
void editer_annuaire(personne* t[], int nb_pers);

/*fonction de chargement a partir d un fichier texte*/
int chargefictext(personne* t[],char* nomfic);

/*fonction de sauvegarde dans un fichier texte*/
void sauvefictext(personne* t[], int nb_pers,char* nomfic);

/*saisie d une chaine de longueur nmax et on vide le tampon, renvoie 1 si saisie partielle*/
int saisir_chaine(char * ch, unsigned int nmax);

/*vider le tampon sur un flux*/
void vider_tampon(FILE* flux);
#endif
