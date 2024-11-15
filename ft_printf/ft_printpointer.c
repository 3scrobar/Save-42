/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:01:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 16:39:01 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(size_t point)
{
	unsigned int	cpt;
	
	cpt += write(1, "0x", 2);
	cpt += ft_printfnumb_base_min(va_arg(args, unsigned int));
}
