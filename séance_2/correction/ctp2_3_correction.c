
#include <stdio.h>
int main()
{
int n,i,fac= 1;
printf("ENTRER UN ENTIER: ");
scanf("%d",&n);
for (i=1;i<=n;i++)
    fac= fac * i;
printf("\nn = %d  n! = %d",n,fac);
printf("\nPOUR CONTINUER FRAPPER UNE TOUCHE");
getchar();
return 0 ;
}


