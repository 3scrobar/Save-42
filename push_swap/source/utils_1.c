/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:38:21 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 13:04:12 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	atoi_long(const char *nptr)
{
	int			i;
	int			neg;
	long int	c;

	i = 0;
	c = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = (c * 10) + (nptr[i] - '0');
		i++;
	}
	return (c * neg);
}

int	ft_printfnumb_nl(int n)
{
	int	cpt;

	cpt = 0;
	if (n == -2147483648)
	{
		cpt += write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			cpt += write(1, "-", 1);
		}
		if (n >= 10)
		{
			cpt += ft_printfnumb(n / 10);
		}
		n = (n % 10) + 48;
		cpt += write(1, &n, 1);
	}
    ft_printf("\n");
	return (cpt);
}