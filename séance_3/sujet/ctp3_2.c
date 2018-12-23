

#include <stdio.h>
#define N 2
#define determ(a,b,c,d) (((a)*(d))-((c)*(b)))

int main()
{
int mat[N][N],det,i,j;
/* saisie */
printf("ENTRER SUCCESSIVEMENT LES VALEURS DEMANDEES: \n");
/* ajouter les instructions pour saisir au clavier chaque valeur de la matrice 2x2 mat : */


/* ajouter les instructions du calcul du déterminant :
det=(mat[0][0] x mat[1][1]) - (mat[1][0] x mat[0][1])*/
/* on pourra utiliser la macro determ définie ci-dessus */


/* ajouter les instructions d'affichage de la matrice :*/

printf("DETERMINANT = %d\n",det);
printf("POUR CONTINUER FRAPPER  UNE TOUCHE: ");
getchar();
return 0 ;
}

