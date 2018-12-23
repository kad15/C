/*
tri_à_bulles(Tableau T)
   pour i allant de taille de T - 1 à 1
       pour j allant de 0 à i - 1
           si T[j+1] < T[j]
               échanger(T[j+1], T[j])

*/


#define TRUE 1;
#define FALSE 0;

void tri_a_bulle(int t[], int const n) 
{
 	int j   = 0; /* Variable de boucle */
 	int tmp = 0; /* Variable de stockage temporaire */

	/* Booléen marquant l'arrêt du tri si le tableau est ordonné */
	int en_desordre = TRUE; 
	/* Boucle de répétition du tri et le test qui
	 arrête le tri dès que le tableau est ordonné(en_desordre=FALSE) */
	while (en_desordre)
	{
		/* Supposons le tableau ordonné */
		en_desordre = FALSE;
		/* Vérification des éléments des places j et j+1 */
		for (j = 0; j < n-1; j++)
		{
			/* Si les 2 éléments sont mal triés */
			if(t[j] > t[j+1])
			{
				/* Inversion des 2 éléments */
 				tmp = t[j+1];
 				t[j+1] = t[j];
 				t[j] = tmp;

 				/* Le tableau n'est toujours pas trié */
				en_desordre = TRUE;
 			}
		}
	}
}

//Version optimisée évitant de parcourir la fin du tableau déjà triée.

void tri_a_bulle(int* t, int const size) 
{
	int en_desordre = 1;
	int i,j,temp;

	for (i = 0; (i < size) && en_desordre; ++i)
	{
		en_desordre = 0;
		for (j = 1; j < (size - i); ++j)
		{
			if (t[j-1] > t[j])
			{
				temp = t[j-1];
				t[j-1] = t[j];
				t[j] = temp;
				en_desordre = 1;
 			}
		}
	}
}


