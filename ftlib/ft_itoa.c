/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:38:30 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/09 16:42:00 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *str, int i, int neg)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = i;
	if (neg == 1)
		str[end - 1] == '-';
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
int	ft_nlen(int n)
{
	int	len;
	
	len = 0;
	if (n <= 0)
		len++;
	if (n < 0)
		n = -n;
	while (n)
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

	i = 0;
	negative = 0;
	str = malloc(sizeof(char) * (ft_nlen(n) + 1));
	if ()
	if (n == 0)
		str = "0";
	else if (n == -2147483648)
		str = "-2147483648";
	else if (n < 0)
		negative = 1;
	while (n != 0 && str != "-2147483648")
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
		str[i + 1] = 0;
	str = ft_reverse(str, i, negative);
	return (ft_strdup(str));
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
