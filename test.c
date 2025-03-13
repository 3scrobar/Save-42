#include <stdio.h>

// Fonction pour échanger deux valeurs en utilisant des pointeurs
void echanger(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Fonction pour trier un tableau d'entiers avec le tri à bulles (utilise echanger)
void trierTableau(int *tab, int taille)
{
	int echange = 1; // Variable pour vérifier si un échange a eu lieu

	while (echange)
	{
		echange = 0; // Réinitialisation de la variable
		int *ptr = tab; // Pointeur sur le premier élément du tableau

		while (ptr < tab + taille - 1)
		{ // Tant qu'on n'a pas atteint l'avant-dernier élément
			if (*ptr > *(ptr + 1))
			{ // Comparaison des éléments adjacents
				echanger(ptr, ptr + 1); // Échanger si nécessaire
				echange = 1; // Indiquer qu'un échange a eu lieu
			}
			ptr++; // Avancer le pointeur
		}
	}
}

void sort_tab(int *tab, int size)
{
	int *ptr = tab;
	int echange = 1;

	while (echange == 1)
	{
		echange = 1;
		while (ptr < tab + size - 1)
		{
			if ( *ptr > *(ptr + 1))
			{
				echanger(ptr ,ptr + 1);
				echange = 0;
			}
			ptr++;
		}
	}
}

int main()
{
	int tableau[] = {42, 12, 89, 5, 23};
	int tableau2[] = {42, 12, 89, 5, 23};

	int taille = sizeof(tableau) / sizeof(tableau[0]);

	printf("Tableau avant tri : ");
	int *ptr = tableau;
	while (ptr < tableau + taille) {
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");

	// Appel de la fonction de tri
	trierTableau(tableau, taille);

	printf("Tableau après tri : ");
	ptr = tableau; // Réinitialiser le pointeur
	while (ptr < tableau + taille) {
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");

	// Appel de la fonction de tri
	sort_tab(tableau2, taille);

	printf("Tableau après tri : ");
	ptr = tableau; // Réinitialiser le pointeur
	while (ptr < tableau + taille) {
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");

	return 0;
}
