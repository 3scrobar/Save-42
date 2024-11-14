/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:58:05 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/14 14:12:56 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_check(char *str)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	
	while (str[i])
	{
		if (str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			i++;
			if (str[i] != '%')
				return (str[i]);
		}
	}
}
int	ft_printchar()
{
	
}
