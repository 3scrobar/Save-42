/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:37:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 16:55:01 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ft_printf(const char *str, ...)
{
	unsigned int	cpt;
	va_list			args;
	va_start(args, str);
	
	cpt = 0;
	while (*str)
		{
			if (*str != '%')
			{
				cpt += write(1, str, 1);
				str++;
			}
			else
			{
				str++;
				cpt += ft_check(args, *str);
				str++;
			}
		}
	return (cpt);
}

#include <stdio.h>

int main(void)
{

	int cpt = 0;

	cpt = ft_printf("1 printf %p ", 16);
	printf("                    jai ecrit %i\n", cpt);
	cpt = printf("2 printf %p ", 16);
	printf("                    jai ecrit %i\n", cpt);

	return (0);
}
