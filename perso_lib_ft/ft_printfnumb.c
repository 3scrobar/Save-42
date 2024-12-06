/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:10 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 14:11:47 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfnumb(int n)
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
	return (cpt);
}