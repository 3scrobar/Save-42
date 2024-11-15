/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:37:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 14:00:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	while (str)
		{
			if (&str != '%')
				str++;
			else
			{
				str++;
				
			}
		}

}

#include <stdio.h>

int main(void)
{
	char c = 'c';
	char *str = "test";
	int cpt = 0;
	
	cpt = ft_printf("je test le char %c, et je teste le string %s",c,str);
	printf(" \njai ecrit %i", cpt);
	return (0);
}
