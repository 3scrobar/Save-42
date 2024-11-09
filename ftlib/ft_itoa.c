/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:38:30 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/09 15:00:18 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str, int i)
{
	int start;
	int end;
	char temp;

	start = 0;
	end = i - 1;
	while (start < end)
	{
		// Échanger les caractères
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
char *ft_itoa(int n)
{
	char	*str;
	int		isNegative;
	int		i;

	i = 0;
	isNegative = 1;
	if (n ==-2147483648 )
		str = "-2147483648";
	if (n < 0)
	{
		isNegative = 1;
		n = n * -1;
	}
	if (isNegative)
		str[i++] = '-';
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';// Récupère le dernier chiffre et l'ajoute à la chaîne
		n /= 10;// Divise la valeur par 10
	}
	str[i] = '\0';
	return (ft_reverse(str, i));
}
