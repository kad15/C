#include <stdio.h>
#include <stdlib.h>

#define TAILLE 6
#define TRUE 1;
#define FALSE 0;

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bulle(int tab[], int taille)
{
    for (int i=0; i<taille-1; i++)
        for(int j=i+1; j<taille; j++)
            if (tab[i]>tab[j]) swap(tab+i,tab+j);
}

void bulle_opt(int tab[], int taille)
{
    int swapped = TRUE;
    for (int i=0; i<taille-1; i++)
        for(int j=i+1; j<taille; j++)
            if (tab[i]>tab[j])
            {
              swap(tab+i,tab+j);
              swapped = TRUE;
            }
    if (!swapped) exit(0);

}

void print_tab(int tab[], int taille)
{
    printf("debut tableau\n");
    for(int i=0; i<taille; i++)
        printf("%d\n",tab[i]);
    printf("fin tableau\n");

}

int main()
{

    int t[TAILLE] = {5,6,7,1,2,3};
    printf("tableau avant tri : \n");
    print_tab(t,TAILLE);
    bulle_opt(t,TAILLE);
    printf("tableau apres tri : \n");
    print_tab(t,TAILLE);

    /* test swap : ok
    int a=2, b=3;
    printf("avant swap a = %d ; b = %d\n",a,b);
    swap(&a,&b);
    printf("apres swap a = %d ; b = %d\n",a,b);
    */
    return 0;
}

