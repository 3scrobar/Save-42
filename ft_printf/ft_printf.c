/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:37:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 15:38:05 by tle-saut         ###   ########.fr       */
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
	char c = 'c';
	char *str = "test";
	int cpt = 0;
	
	cpt = ft_printf("je test le char \n%c\nje teste le string \n%s\nje teste les nombre\n%d\n%i\n les bases\n%x\n%X\n et pourcent \n%%\n",c,str,42,21,17,17);
	printf("jai ecrit %i", cpt);
	return (0);
}
