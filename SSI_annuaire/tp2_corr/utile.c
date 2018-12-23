#include "annuaire.h"

int saisir_chaine(char * ch,unsigned int nmax)
{
    char temp[nmax];

    if(fgets(temp,nmax,stdin)==NULL)
    {
        fprintf(stderr,"erreur saisie");
        return 1;
    }
    else
    {
        char * pos = strchr (temp,'\n') ;
        if (pos !=NULL )
        {
            *pos ='\0';
            strncpy(ch,temp,nmax-1);
            ch[nmax-1]='\0';
            return 0;
        }
        else
        {
            //on vide le tampon
            vider_tampon(stdin);
            fprintf(stderr,"saisie trop longue");
            return 1;
        }
    }
}
void vider_tampon(FILE* flux)
{
    int c = 0;
    while (c != '\n' && c != EOF){
        c = fgetc(flux);
    }
}
