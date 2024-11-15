/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:58:05 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 14:15:53 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char c, int i)
{
	unsigned int	cpt;

	cpt = 0;
	if (c == 'c')
		cpt += ft_printchar(va_arg(args, int));
	else if (c == 's')
		cpt += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else if (c == '%')
		cpt += write(1,'%',1);

}
