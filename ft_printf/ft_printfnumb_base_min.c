/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumb_base_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:31:57 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 15:20:33 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printfnumb_base_min(unsigned int nbr)
{
	unsigned int	cpt;
	char 			*str;
	
	cpt = 0;
	str = "0123456789abcdef";
	if (nbr > 16)
		ft_printfnumb_base_min(nbr / 16);
	cpt += write(1, (&str[nbr % 16]), 1);
	return (cpt);
}
