
#include <stdio.h>
int  main()
{
char c;

printf("ENTRER UN CARACTERE: ");
/* ajouter une instruction pour saisir au clavier un caractère */
scanf("%c",&c);
/*
ajouter ici les instructions qui testent si ce caractère est une voyelle :
on utilisera une ou plusieurs instructions if
*/
if (toupper(c)=='A' || toupper(c)=='E' || toupper(c)=='I' || toupper(c)=='O' || toupper(c)=='U' || toupper(c)=='Y')
    printf("CE CARACTERE EST UNE VOYELLE\n");
else
    printf("CE CARACTERE N'EST PAS UNE VOYELLE\n");

printf("POUR CONTINUER FRAPPER UNE TOUCHE ");
getchar();
return 0 ;
}
