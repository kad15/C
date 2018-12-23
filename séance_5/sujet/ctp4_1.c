
#include <stdio.h>
#include <stdlib.h>
int main()
{
float *adr1,*adr2;
float f=-15.78;

adr1=&f; // adr1 pointeur sur une variable de la pile
adr2 = (float*)malloc(sizeof(float)); // adr2 pointeur vers le tas : allocation obligatoire.
*adr1 = -5.78;  //  f est modifié !!
*adr2 = 365.89;
printf("&f = %p f = %f \n adr1 = %p *adr1 = %f \n adr2 = %p *adr2 = %f\n",&f,f,adr1,*adr1,adr2,*adr2);

/* ajouter ici la ou les instructions de libération des zones mémoires */

printf("\nPOUR CONTINUER FRAPPER UNE TOUCHE ");
getchar();
return 0 ;
}
