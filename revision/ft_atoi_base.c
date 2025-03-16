/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:05:30 by anporced          #+#    #+#             */
/*   Updated: 2025/03/16 16:19:03 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int get_value(char c)
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
	value = get_value(s[i]);
	while (value >= 0 && value < base)
	{
		i++;
		result = result * base + value;
		value = is_print(s[i]);
	}
	return (signe * result);
}

int main()
{
	printf("%d\n", ft_atoi_base("101", 2));    // 5 (binaire)
	printf("%d\n", ft_atoi_base("1A", 16));    // 26 (hexadécimal)
	printf("%d\n", ft_atoi_base("-FF", 16));   // -255
	printf("%d\n", ft_atoi_base("f1ef", 16));     // 35
	printf("%d\n", ft_atoi_base("100", 10));   // 100
	printf("%d\n", ft_atoi_base("G", 16));     // 0 (G n'existe pas en base 16)
	return 0;
}
