#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
   int nbre, som, divi, maxi;

   float start=clock();

   for(nbre = 2; nbre <= 10000; nbre++)
   {
        som = 1;
        maxi=sqrt(nbre);
	    for(divi = 2; divi< maxi; divi++)
	    if(nbre % divi ==0)
            som = som + divi + nbre / divi;

        if(nbre == som)
            printf("%d est parfait\n",nbre);
   }

   printf("Temps d'execution : %f\n",(clock()-start)/CLOCKS_PER_SEC);

   return(0);
}
