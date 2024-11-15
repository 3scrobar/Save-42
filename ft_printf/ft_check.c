/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:58:05 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 14:10:38 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char str, int i)
{
	unsigned int	cpt;

	cpt = 0;
	if (&str == 'c')
		cpt = ft_printchar(va_args(args, int));
}
