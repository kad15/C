
#include <stdio.h>
#include <math.h>
void saisir(int dim, float t[]);
// la fonction "saisir" permet de saisir au clavier "dim" valeurs stockées
// dans le tableau "t".
float moyenne(int dim, float t[]);
// la fonction "moyenne" permet de calculer la moyenne des "dim" valeurs du tableau "t".
float ecart_type(int dim,float t[]);
// la fonction "ecart_type" permet de calculer l'écart-type des "dim" premières valeurs
// du tableau "t".

int main()
{
float nombre[10];

saisir(10,nombre);
printf("MOYENNE = %f  ECART_TYPE = %f\n",moyenne(10,nombre),ecart_type(10,nombre));
printf("POUR CONTINUER FRAPPER UNE TOUCHE: ");
getchar();
return 0 ;
}

/* ajouter les définitions des fonctions manquantes : saisir, moyenne et ecart_type */
