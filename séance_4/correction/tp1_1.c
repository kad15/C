#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nbre,som,divi;

    float start=clock();

    for(nbre = 2; nbre <= 10000; nbre++)
	{
        som = 1;
        for(divi = 2; divi< nbre; divi++)
            if(nbre % divi ==0)
                som = som + divi;

        if(nbre == som)
	           printf("%d est parfait\n",nbre);
    }

    printf("Temps d'execution1 : %f\n",(clock()-start)/(CLOCKS_PER_SEC));

    return(0);
}

