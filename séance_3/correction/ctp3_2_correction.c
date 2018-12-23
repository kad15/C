

#include <stdio.h>
#define N 2
#define determ(a,b,c,d) (((a)*(d))-((c)*(b)))

int main()
{
int mat[N][N],det,i,j;
/* saisie */
printf("ENTRER SUCCESSIVEMENT LES VALEURS DEMANDEES: \n");
printf("mat[0][0] = ");
scanf("%d",&mat[0][0]);
printf("mat[1][0] = ");
scanf("%d",&mat[1][0]);
printf("mat[0][1] = ");
scanf("%d",&mat[0][1]);
printf("mat[1][1] = ");
scanf("%d",&mat[1][1]);

/* calcul du déterminant : */
det = mat[0][0]*mat[1][1]-mat[1][0]*mat[0][1];
// on aurait pu écrire : det= determ(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);

/* affichage de la matrice :*/
for (i=0; i<N; i++) {
    for (j=0;j<N;j++)
        printf("%5d",mat[i][j]);
    printf("\n");
}
printf("DETERMINANT = %d\n",det);
printf("POUR CONTINUER FRAPPER  UNE TOUCHE: ");
getchar();
return 0 ;
}

