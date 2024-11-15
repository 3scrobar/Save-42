/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnum_base_maj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:06:05 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 17:31:51 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printfnumb_base_maj(unsigned int nbr)
{
	unsigned int	cpt;
	char			*str;

	cpt = 0;
	str = "0123456789ABCDEF";
	if (nbr >= 16)
		cpt += ft_printfnumb_base_maj(nbr / 16);
	cpt += write(1, &str[nbr % 16], 1);
	return (cpt);
}
