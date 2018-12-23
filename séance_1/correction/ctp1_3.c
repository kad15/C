
/****Resolution de l'equation du second degre a coefficients reels****/

#include<stdio.h>
#include<math.h>

int main()
{
	/*Declaration des variables*/
	double a,b,c,sol1,sol2,det;

	/*Bloc initialisation des coefficients*/
	printf("Resolution de l'equation ax^2+bx+c=0\n");
	a= 1;
	b= 2;
	c= -3;

	/*Bloc resolution et test des coefficients*/
	if (a==0)
	{
		if(b==0)
		{
			if(c==0)
			{
                printf("Trivial\n");
			}
			else
			{
                printf("Impossible\n");
            }
        }
		else
		{
			sol1=-c/b;
			printf("Une solution : %lf\n",sol1);
		}
	}
	else
	{
        det=pow(b,2)-4*a*c;  //calcul determinant
        if (det<0)
        {
            printf("Pas de solutions reelles\n");
        }
        else
        {
            if (det==0)
            {
                sol1=(-b/(2*a));
                printf("Une solution double : %lf\n",sol1);
            }
			else
			{
                sol1=(-b-sqrt(det))/(2*a);
                sol2=(-b+sqrt(det))/(2*a);
                printf("Deux solutions : %lf   et  %lf\n",sol1,sol2);
			}
        }
	}
	return 0;
}
