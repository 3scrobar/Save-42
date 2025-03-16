#include <unistd.h>
#include <stdio.h>

void afficherBits(unsigned char octet)
{
	unsigned char mask = 0b10000000;
	int i = 0;
	while (i < 8)
	{
		if ((mask & octet) != 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask = mask >> 1;
		i++;
		if (i == 4)
		write(1,"  ",2);

	}
	write(1, "\n", 1);
}
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char reversed = 0;
	int i = 0;

	while (i < 8)
	{
		reversed = (reversed << 1) | (octet & 0b00000001);
		octet = octet >> 1;
		i++;
	}
	return reversed;
}

unsigned char swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
int main()
{
	unsigned char octet = 0b11100010;
	write(1,"Original :\n",12);
	afficherBits(octet);
	write(1,"Swap Bits :\n",13);
	afficherBits(swap_bits(octet));
	write(1,"Reverse Bits\n",14);
	afficherBits(reverse_bits(octet));
	return 0;
}
