#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define LG 80
typedef char chaine[20];
int main(){

chaine * tab;
int * adr1, *adr2, *adr3;
adr1 = (int*)calloc(100, sizeof(int));
printf("alloc 100 octets en %p\n",adr1);

adr2 = malloc(50);
printf("alloc 50 octets en %p\n",adr2);

 free(adr1);
 printf("libé de 100 octets en %p\n",adr1);
adr1=NULL;

adr3=malloc(40);

printf("alloc de 40 octet en %p\n",adr3);

tab = (chaine*)calloc(10,sizeof(chaine));

for(int i = 0;i<10;i++){
strcpy(tab[i],"lundi");
}
printf("adr de tab %s\n",*(tab+9));

free(tab);

printf("adr de tab %s\n",*(tab+9));
return 0;
}


/*


int main(){

char ch[20];

int n;
n=

return 0;
}



int main(){


char ch[20]="bonjour";  A L'INITIALISATION ON PEUT AFFECTÉ LE TABLEAU DE CHAR MAIS PAS ENSUITE
printf("%s",ch);

// erreur ch est une constante pointeur qui correspond
// à l'adresse que le compilateur a attribué au tableau ch.

//ch n'est pas une lvalue'. il n'est donc pas question de lui attribuer une autre valeur
// en l'occurence l'adresse attribuée par le compilateur à la constante chaine "bonjour"
char ch[20];
ch = "bonjour";

return 0;
}



int main(){
//strcpy(but,source)

char ch1[20]="xxxxxxxxxxxxxxxxxx";
char ch2[20];

printf("donner mot : ");

gets(ch2);
strncpy(ch1,ch2,6);
printf("%s",ch1);
// si ch2 a 5 chars ou moins + le \0 alors ch1==ch2 mais sinon le char \0 n'est pas copié et on a 123456xxxxxxxx
return 0;
}


int main(){
char ch1[50]="bonjour";
char * ch2 = " monsieur";
printf ("avant : %s\n", ch1);
// ne concatène à ch1 que 9 char de la chaine  ch2
strncat(ch1,ch2,9);
printf("après : %s",ch1);
//stricmp strnicmp  ne tiennent pas compte des majuscules

return 0;
}





int main(){

int n, cpt;
char c;
char ligne [LG+1];


do{
printf("donner un entier et un char : ");
gets(stdin,ligne);
cpt = sscanf(ligne,"%d %c",&n,&c);

}
while (cpt<2);
printf("merci pour %d %c\n",n,c);

return 0;
}




int main()
{
char nom[20], prenom[20],ville[25];
printf("quelle est votre ville : ");
gets(ville);
printf("donnez votre nom et prenom :");
scanf("%s %s",nom,prenom);
printf("Bonjour %s %s qui habitez à ",nom,prenom);

return 0;
}





main()
{
 int n;
do{
printf("donner un nbr : ");
 scanf("%d",&n);
//while((getchar())!='\n');
getchar();
printf("voici son carré : %d\n",n*n);
}
while(n);


}


int main(int argc, char * argv[]){
int n,p;
printf("donner val n : ");
scanf("%d", &n);
while( (getchar())!='\n') ;
printf("merci pour la val n = %d\n", n);
printf("donner val pour p : ");
scanf("%d", &p);
printf("merci pour la val p = %d\n",p);


return 0;
}



int split(char* str, const char delimeter, char*** args) {
    int cnt = 1;
    char* t = str;

    while (*t == delimeter) t++;

    char* t2 = t;
    while (*(t2++))
        if (*t2 == delimeter && *(t2 + 1) != delimeter && *(t2 + 1) != 0) cnt++;

    (*args) = malloc(sizeof(char*) * cnt);

    for(int i = 0; i < cnt; i++) {
        char* ts = t;
        while (*t != delimeter && *t != 0) t++;

        int len = (t - ts + 1);
        (*args)[i] = malloc(sizeof(char) * len);
        memcpy((*args)[i], ts, sizeof(char) * (len - 1));
        (*args)[i][len - 1] = 0;

        while (*t == delimeter) t++;
    }

    return cnt;
}




int main()
{
	char chaine[] = "LFPO 2 27 09"
        int a=0;
	int b=0;
	int t[5] ;//= {0};


        printf("\nnbtoken=%d\n", split(chaine, ' ',
        for (int i = 0;i<5;i++)
	{
		printf("%d ",t[i]);

	}
       printf("\n");
if(!0) printf("on est entre ds le if\n");
	printf("Enter value of a: ");
	scanf("%d",&a);

	printf("Enter value of b: ");
	scanf("%i",&b);

	printf("a=%d, b=%d\n",a,b);

	return 0;
}


int main(int argc, char * argv[])
{

char s[4];

*s = "abc";

printf("chaine vaut ; %s\n",s);
return 0;
}


int main(int argc, char *argv[])

{

    char chaine[] = "Salut";

    int longueurChaine = 0;


    // On récupère la longueur de la chaîne dans longueurChaine

    longueurChaine = strlen(chaine);


    // On affiche la longueur de la chaîne

    printf("La chaine %s fait %d caracteres de long", chaine, longueurChaine);


    return 0;

}



int main(int argc, char * argv[])
{

char str[]="texte";
char cpy[2]={0};

//strcpy(cpy,str);

printf("chaine vaut ; %s\n",str);
printf("chaine vaut : %s\n", cpy);
printf("%d\n",strcmp(str,cpy));
return 0;
}

*/
