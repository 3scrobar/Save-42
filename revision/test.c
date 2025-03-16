#include <stdio.h>

// Fonction pour échanger deux valeurs en utilisant des pointeurs
void echanger(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void trierTableau(int *tab, int taille)
{
	int echange = 1;

	while (echange)
	{
		echange = 0;
		int *ptr = tab;

		while (ptr < tab + taille - 1)
		{ 
			if (*ptr > *(ptr + 1))
			{ 
				echanger(ptr, ptr + 1); 
				echange = 1;
			}
			ptr++;
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

	
	trierTableau(tableau, taille);

	printf("Tableau après tri : ");
	ptr = tableau;
	while (ptr < tableau + taille) {
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");

	
	sort_tab(tableau2, taille);

	printf("Tableau après tri : ");
	ptr = tableau;
	while (ptr < tableau + taille) {
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");

	return 0;
}
