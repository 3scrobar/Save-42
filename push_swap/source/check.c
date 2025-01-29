/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:13 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 15:10:32 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_sorted(t_all *all)
{
    p_swap *temp;

    temp = all->lsta;
    while (temp->chain)
    {
        if (temp->value > temp->chain->value)
            return(0);
        temp = temp->chain;
    }
    ft_printf("OK\n");
    return(1);
}

void    count_all(t_all *all)
{
    p_swap *temp;

    temp = all->lsta;
    all->min = 0;
    all->max = 0;
    all->sorted = 0;
    while (temp)
    {
        if (temp->value < all->min)
            all->min = temp->value;
        if (temp->value > all->max)
            all->max = temp->value;
        temp = temp->chain;
    }
    all->count = lstsize(all->lsta);
}

int	check_args(char **str, p_swap **lst, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac > 2)
	{
		if (while_check_args(lst, i, str) == 1)
			return (1);
	}
	else
	{
		while_check_args_string(lst, i, j, str);
	}
	
	ft_printf("\n");
	return (0);
}

int    while_check_args_string(p_swap **lst, int i, int j, char **str)
{
    long int nb;

    nb = 0;
    while (str[i][j])
    {
        if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '-' && str[i][j] != ' ')
            return (ft_putstr_fd("Error from NUMBER\n", 2), 1);
        if (str[i][j] == ' ')
            j++;
        else if ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '-' )
            {
                nb = atoi_long(str[i], j);
                if (nb > INT_MAX || nb < INT_MIN)
                    return (ft_putstr_fd("Error int\n",2),1);
                if(lstcomp(*lst, nb) != 0)
                    return (ft_putstr_fd("Error dup\n", 2), 1);
                lstadd_back(lst, lstnew((int)nb));
                j++;
            }
    }
    return(0);
}

int    while_check_args(p_swap **lst, int i, char **str)
{
    long int nb;

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
                    return (ft_putstr_fd("Error int\n",2),1);
                if(lstcomp(*lst, nb) != 0)
                    return (ft_putstr_fd("Error dup\n", 2), 1);
                lstadd_back(lst, lstnew((int)nb));
            }
		i++;
	}
    return(0);
}

int is_valid_args(char *str)
{
    int i;

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
