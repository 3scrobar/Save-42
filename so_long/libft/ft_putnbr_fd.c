/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:07:56 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 15:44:26 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	size_t	cpt;
	
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
			cpt += ft_putnbr_fd(n / 10, fd);
		}
		n = (n % 10) + 48;
		cpt += write(fd, &n, 1);
	}
	return (cpt);
}
