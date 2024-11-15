/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:10 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 14:17:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int cpt;

	cpt = 0;
	if (n == -2147483648)
	{
		cpt += write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			cpt += write(fd, "-", 1);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		n = (n % 10) + 48;
		cpt += write(fd, &n, 1);
	}
	return(cpt);
}
