// TP 1  Partie 4 : nombre de nombres premiers <= n

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int nmax,n, premier;
    int d;
    double dmax;
    int nbpremier=0;

    printf("Donnez un nombre : ");
	scanf("%d",&nmax);

	float start = clock();

    for(n=2; n <= nmax; n++)
	{

        // recherche si n est premier :
        premier=1; //on part de l'hypothèse que n est premier

        d=2;
        dmax=sqrt(n);
        while  ((d<=dmax) && (premier ==1))
            if ((n%d) ==0)
                premier= 0;
            else
                d++;

        // incrémentation du nb de nb premiers :
        if(premier)
            nbpremier++;
    }
    printf("Temps d'execution : %f\n",(clock()-start)/CLOCKS_PER_SEC);
    printf("Le nombre de nombres premiers entre 0 et %d est  : %d\n",nmax,nbpremier);
    return 0;
}

