
#include <stdio.h>
int voyelle(int c) ;

int  main()
{
char c;

printf("ENTRER UN CARACTERE: ");
/* ajouter une instruction pour saisir au clavier un caractère */
scanf("%c",&c);
/* on appelle ici la fonction "voyelle" :
*/
if (voyelle(c))
    printf("CE CARACTERE EST UNE VOYELLE\n"); // si "voyelle(c) != 0"
else
    printf("CE CARACTERE N'EST PAS UNE VOYELLE\n"); // si "voyelle(c) == 0"

printf("POUR CONTINUER FRAPPER UNE TOUCHE ");
getchar();
return 0 ;
}

int voyelle(int c)
{
    if (toupper(c)=='A' || toupper(c)=='E' || toupper(c)=='I' || toupper(c)=='O' || toupper(c)=='U' || toupper(c)=='Y')
        return 1;
    else
        return 0;
}
