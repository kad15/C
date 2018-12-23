/************ calcule si un nombre est premier ***********/
#include <stdio.h>
int main()
{
int n,i, premier=1;
int boucle=1;
char chaine[10]="";

while (boucle == 1)
{
    premier=1;
    printf("ENTRER UN ENTIER: ");
    scanf("%9[^\n]",chaine);
    getchar();
    boucle=sscanf(chaine,"%d",&n);
    strcpy(chaine,"");
    if (boucle ==1)
        {
            i=2;
            if (n == 1)
                premier=0;
            while ((i < n-1) && (premier != 0) )
                {
                    if ( n%i == 0)
                        premier=0;
                    i++;
                }
            if (premier == 0)
                printf("Le nombre %d n'est pas premier ! \n",n);
            else
                printf("Le nombre %d est premier ! \n",n);
        }

}
printf("\nFIN DU PROGRAMME");
getchar();
return 0 ;
}


