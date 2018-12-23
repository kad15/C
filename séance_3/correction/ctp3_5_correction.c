
#include <stdio.h>
#include <math.h>
void saisir(int dim, float t[]);
float moyenne(int dim, float t[]);
float ecart_type(int dim,float t[]);

int main()
{
float nombre[10];

saisir(10,nombre);
printf("MOYENNE = %f  ECART_TYPE = %f\n",moyenne(10,nombre),ecart_type(10,nombre));
printf("POUR CONTINUER FRAPPER UNE TOUCHE: ");
getchar();
return 0 ;
}

/**********************************/
void saisir(int dim, float t[])
{
int i;
printf("SAISIR %d NOMBRES SEPARES PAR RETURN: \n",dim);
for(i=0;i<dim;i++)
	{
	printf("nombre[%2d] = ",i);
	scanf("%f",&t[i]);
	}
}

/***********************************/
float moyenne(int dim, float t[])
{
int i;
float moyenne=0;
for(i=0;i<dim;i++)
	{
	moyenne = moyenne + t[i];
	}
if (dim !=0)
    return moyenne/dim;
else return 0;
}

/***********************************/
float ecart_type(int dim,float t[])
{
int i;
float moy=0,et=0;
for(i=0;i<dim;i++)
	{
	et = et + t[i]*t[i];
	}
moy = moyenne(dim,t); // calculer une seule fois.
et = et/10;
et = et - moy*moy;
et = sqrt(et);
return et;
}
