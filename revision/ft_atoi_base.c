/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoutaie <asoutaie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:05:30 by anporced          #+#    #+#             */
/*   Updated: 2025/02/25 19:57:57 by asoutaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_print(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *s, int base)
{
	int i = 0;
	int value = 0;
	int signe = 1;
	int result = 0;

	if (base < 2 || base > 36)
		return (0);
	if (s[i] == '-')
	{
		signe = -1;
		i++;
	}
	value = is_print(s[i]);
	while (value >= 0 && value < base)
	{
		i++;
		result = result * base + value;
		value = is_print(s[i]);
	}
	return (signe * result);
}

// int main()
// {
// 	printf("%d\n", ft_atoi_base("-10", 10));
// 	printf("%d\n", ft_atoi_base("15", 16));
// 	printf("%d\n", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.", 16));
// 	printf("%d\n", ft_atoi_base("00001010", 2));
// }
