/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/24 15:04:55 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_putstr_fd("Error from argument",2);
	
	
	
	return (0);
}
int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] < '9') || str[i] == ' ' || str[i] == '-' )
			i++;
		else
			return(ft_putstr_fd("Error put some good args", 2));
	}

	return (0);
}
