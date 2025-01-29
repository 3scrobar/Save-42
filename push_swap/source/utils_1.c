/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:38:21 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 15:13:30 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	atoi_long(const char *nptr, int j)
{
	int			neg;
	long int	c;

	c = 0;
	neg = 1;
	while (nptr[j] == ' ' || (nptr[j] >= 9 && nptr[j] <= 13))
		j++;
	if (nptr[j] == '-' || nptr[j] == '+')
	{
		if (nptr[j] == '-')
			neg = -1;
		j++;
	}
	while (nptr[j] >= '0' && nptr[j] <= '9')
	{
		c = (c * 10) + (nptr[j] - '0');
		j++;
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

void	print_lst(t_all *all)
{
	ft_printf("Liste A\n");
	lstiter(all->lsta, ft_printfnumb_nl);
	ft_printf("Liste B\n");
	lstiter(all->lstb, ft_printfnumb_nl);
}
