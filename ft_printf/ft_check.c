/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:58:05 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 15:56:08 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char c)
{
	unsigned int	cpt;

	cpt = 0;
	if (c == 'c')
		cpt += ft_printchar(va_arg(args, int));
	else if (c == 's')
		cpt += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		cpt += ft_printfnumb(va_arg(args, int));
	else if (c == 'u')
		cpt += ft_printfnumb(va_arg(args, unsigned int));
	else if (c == 'x')
		cpt += ft_printfnumb_base_min(va_arg(args, unsigned int));
	else if (c == 'X')
		cpt += ft_printfnumb_base_maj(va_arg(args, unsigned int));
	else if (c == '%')
		cpt += write(1,"%",1);
	else if (c == 'p')
	{
		cpt += write(1, "0x", 2);
		cpt += ft_printfnumb_base_min(va_arg(args, unsigned int));
	}
	return (cpt);
}
