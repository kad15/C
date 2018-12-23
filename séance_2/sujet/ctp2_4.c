/************ calcule si un nombre est premier ***********/
#include <stdio.h>
int main()
{
    int n,i, resultat=0;
    printf("ENTRER UN ENTIER: ");
    scanf("%d",&n);

    /*
     ajouter ici une boucle qui recherche un diviseur possible de n :
     on utilisera l'opérateur %  (modulo) qui retourne le reste de la division entière
     entre deux nombres.
     Exemple :si a=4 et b=2
              r=a%b
              r est égal à 0, donc b est un diviseur de a.
     */

    if (resultat == 1)
        printf("Le nombre %d est premier ! \n",n);
    else
        printf("Le nombre %d n'est pas premier ! \n",n);

    return 0 ;
}


