/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:01:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 17:32:50 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long nbr)
{
	int	cpt;

	cpt = 0;
	if (nbr == 0)
		return (ft_printstr("(nil)"));
	cpt = 0;
	cpt += write(1, "0x", 2);
	cpt += ft_printfnumb_base_min(nbr);
	return (cpt);
}
