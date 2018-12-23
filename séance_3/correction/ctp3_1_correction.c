
#include <stdio.h>
#include <math.h>
#define NB 10

int main()
{
float nombre[NB],moyenne = 0,ecart_type = 0;
int i;

/* saisie des nombres */
printf("SAISIR %d NOMBRES SEPARES PAR RETURN: \n",NB);
for(i=0;i<NB;i++)
	{
	printf("nombre[%1d] = ",i);
	scanf("%f",&nombre[i]);
	}
/* calculs */
for(i=0;i<NB;i++)
	{
	moyenne = moyenne + nombre[i];
	ecart_type = ecart_type + nombre[i]*nombre[i];
	}
moyenne = moyenne/NB;
ecart_type = ecart_type/NB;
ecart_type = ecart_type - moyenne*moyenne;
ecart_type = sqrt(ecart_type);	/* racine */
printf("MOYENNE = %f  ECART_TYPE = %f\n",moyenne,ecart_type);
printf("POUR CONTINUER FRAPPER UNE TOUCHE: ");
getchar();
return 0 ;
}
