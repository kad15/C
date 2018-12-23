
#include <stdio.h>
int fact(int n);

int main()
{
int n;
printf("ENTRER UN ENTIER: ");
scanf("%d",&n);
printf("\nn = %d  n! = %d",n,fact(n));
printf("\nPOUR CONTINUER FRAPPER UNE TOUCHE");
getchar();
return 0 ;
}

/* ajouter ici la définition de la fonction récursive fact
qui calcule la factorielle de n */
