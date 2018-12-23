#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    double nb;
    int n, premier;
    int d;
    double dmax;
    int terme;

    float start=clock();

    for(n=1; n <= 30; n++)
	{
        terme =(int)( pow(2,(n + 1)) - 1);
        // recherche si terme est premier :
        premier=1; //on part de l'hypothèse que le terme est premier
        if(terme !=1)
            {
                d=2;
                dmax=sqrt(terme);
                while  ((d<=dmax) && (premier ==1))
                    if ((terme%d) ==0)
                        premier= 0;
                    else
                        d++;
            }
        else premier=0;

        // calcul du nb parfait si terme est premier :
        if(premier)
	    {
            nb = pow(2,n) * terme ;
		    printf("%.0lf est parfait\n",nb);
	    }
    }
    printf("Temps d'execution : %f\n",(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}


