/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:38:30 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/09 17:16:19 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n)
{
	int	len;
	
	len = 0;
	if (n <= 0)
		len++;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
char	*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		i;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nlen(n);
	i = 1;
	negative = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

#include <stdio.h>

int main(void)
{
	int test_values[] = {12345, -12345, 67890, -1, 2147483647, -2147483648};
	// Tester ft_itoa avec plusieurs valeurs
	for (int i = 0; i < 6; i++)
	{
		printf("ft_itoa(%d) = %s\n", test_values[i], ft_itoa(test_values[i]));
	}
}