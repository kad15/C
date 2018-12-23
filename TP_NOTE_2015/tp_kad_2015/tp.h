#ifndef _TP_H
#define _TP_H
#define MAX 1000
// structure utilisée pour mémoriser un coureur arrivé :
typedef struct {
    char nom[30]; // nom du coureur
    int dossard;  // numéro de dossard du coureur
    int temps[3];  // temps à l'arrivée : temps[0] en heures, temps[1] en minutes, temps[2] en secondes
}coureur;

// liste des fonctions à développer :
void init_course(coureur t[MAX]);
int nb_arrives(coureur t[MAX]);
void saisircoureur(coureur t[MAX],int * pt_n);
void affichercourse(coureur t[MAX],int n);
void sauvegardercourse(coureur t[MAX],int n, char nomfic[]);
void trier(coureur t[MAX],int n);

#endif
