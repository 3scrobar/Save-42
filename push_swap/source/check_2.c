/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:51:14 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:53:53 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	while_check_args_string(t_swap **lst, int i, int j, char **str)
{
	long int	nb;

	nb = 0;
	while (str[i][j])
	{
		if ((str[i][j] < '0' || str[i][j] > '9')
			&& str[i][j] != '-' && str[i][j] != ' ')
			return (ft_putstr_fd("Error from NUMBER\n", 2), 1);
		if (str[i][j] == ' ')
			j++;
		else if ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '-' )
		{
			nb = atoi_long(str[i], j);
			if (nb > INT_MAX || nb < INT_MIN)
				return (ft_putstr_fd("Error int\n", 2), 1);
			if (lstcomp(*lst, nb) != 0)
				return (ft_putstr_fd("Error dup\n", 2), 1);
			lstadd_back(lst, lstnew((int)nb));
			j++;
		}
	}
	return (0);
}

int	while_check_args(t_swap **lst, int i, char **str)
{
	long int	nb;

	nb = 0;
	i = 1;
	while (str[i])
	{
		if (is_valid_args(str[i]) == 0)
			return (ft_putstr_fd("Error from NUMBER\n", 2), 1);
		if (is_valid_args(str[i]) == 1)
		{
			nb = atoi_long(str[i], 0);
			if (nb > INT_MAX || nb < INT_MIN)
				return (ft_putstr_fd("Error int\n", 2), 1);
			if (lstcomp(*lst, nb) != 0)
				return (ft_putstr_fd("Error dup\n", 2), 1);
			lstadd_back(lst, lstnew((int)nb));
		}
		i++;
	}
	return (0);
}

int	is_valid_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}
