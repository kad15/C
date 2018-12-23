#include <stdio.h>

int main()
{
    // l'opérateur sizeof retourne un entier long :
    printf("TAILLE D'UN CARACTERE:%ld\n",sizeof(char));
    printf("TAILLE D'UN ENTIER:%ld\n",sizeof(int));
    printf("TAILLE D'UN ENTIER LONG :%ld\n",sizeof(long));
    printf("TAILLE D'UN REEL:%ld\n",sizeof(float));
    printf("TAILLE D'UN DOUBLE:%ld\n",sizeof(double));

    return 0 ;
}
