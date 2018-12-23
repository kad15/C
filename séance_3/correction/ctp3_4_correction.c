
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

int fact(int n)
{
int i;
if (n==0)  // condition d'arrêt de la fonction récursive
    return 1;
else
    return n*fact(n-1);
}
