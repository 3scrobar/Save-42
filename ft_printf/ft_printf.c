/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:37:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/14 15:49:30 by tle-saut         ###   ########.fr       */
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
			selec = ft_check(str[++i]);
		if (selec == 'c')
			cpt = cpt + ft_printchar(va_arg(args, char));
		if (selec == 's')
			cpt = cpt + ft_printstr(va_arg(args, char *));
	}
}

int main(void)
{
	char c =
}
