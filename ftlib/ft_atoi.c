/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:56:04 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 13:37:49 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	c;
	int	i;
	int	neg;

	i = 0;
	neg = 2;
	while (nptr[i])
	{
		if (nptr[i] == '-' )
		{
			neg = 1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			neg = 0;
			c = (c * 10) + (nptr[i] - '0');
			i++;
		}
		if (neg == 1)
			return (c * -1);
		if (neg == 0)
			return (c);
		i++;
	}
	return (0);
}
