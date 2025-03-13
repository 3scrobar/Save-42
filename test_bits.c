#include <unistd.h>

// Fonction pour afficher les bits d'un entier (sans for, avec while)
void afficherBits(unsigned char octet)
{
	unsigned char mask = 0b10000000; // On commence par le bit le plus à gauche (128)
	int i = 0;
	write(1,"Les bits sont :\n",16);
	while (i < 8)
	{
		if ((mask & octet) != 0) // Vérifie si le bit est activé
			write(1, "1", 1);
		else
			write(1, "0", 1);
		
		mask = mask >> 1; // Décalage à droite pour passer au bit suivant
		i++;
		if (i == 4)
		write(1,"  ",2);
	}
	write(1, "\n", 1); // Nouvelle ligne pour plus de lisibilité
}
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char reversed = 0;
	int i = 0;
	while (i < 8)
		{
			reversed = reversed | (octet & 0b00000001);
			reversed = reversed << 1;
			octet = octet >> 1;
			i++;
			if (i == 4)
				write(1,"  ",2);
		}
	return(reversed);
}

unsigned char swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
int main()
{
	unsigned char octet = 0b10110111;
	afficherBits(octet);
	afficherBits(swap_bits(octet));
	afficherBits(reverse_bits(octet));
	return 0;
}
