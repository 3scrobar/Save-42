/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:37:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/14 15:59:15 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *str, ...)
{
	char			selec;
	int				i;
	unsigned int	cpt;
	va_list	args;
	va_start(args, str);

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i]!= '%')
			write(1, &str[i], 1);
		else
			selec = ft_check((char *)str, (int)i);
		if (selec == 'c')
			cpt = cpt + ft_printchar(va_arg(args, char));
		if (selec == 's')
			cpt = cpt + ft_printstr(va_arg(args, char *));
	}
}
#include <stdio.h>

int main(void)
{
	char c = 'c';
	char *str = "test";
	int cpt = 0;
	
	cpt = ft_printf("je te le char %c, et je teste le string",c);
	printf(" \njai ecrit %i", cpt);
	return (0);
}
