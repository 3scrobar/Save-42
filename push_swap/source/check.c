/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:13 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/24 15:01:41 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_sorted_lsta(t_all *all)
{
    t_swap *temp;

    temp = all->lsta;
    while (temp->chain)
    {
        if (temp->value > temp->chain->value)
            return(0);
        temp = temp->chain;
    }
    return(1);
}

int    check_sorted_lstb(t_all *all)
{
    t_swap *temp;

    temp = all->lstb;
    while (temp->chain)
    {
        if (temp->value < temp->chain->value)
            return(0);
        temp = temp->chain;
    }
    return(1);
}

int    count_all_lsta(t_all *all, int a)
{
    t_swap *temp;

    temp = all->lsta;
    all->mina = INT_MAX;
    all->maxa = INT_MIN;
    all->first = 1;
    if (a == 1)
        {
            while (temp)
            {
                if (temp->value < all->mina)
                    all->mina = temp->value;
                if (temp->value > all->maxa)
                    all->maxa = temp->value;
                temp = temp->chain;
            }
        }
    all->counta = lstsize(all->lsta);
    return (all->counta);
}

int    count_all_lstb(t_all *all, int a)
{
    t_swap *temp;

    temp = all->lstb;
    all->minb = INT_MAX;
    all->maxb = INT_MIN;
    if (a == 1)
        {
            while (temp)
            {
                if (temp->value < all->minb)
                    all->minb = temp->value;
                if (temp->value > all->maxb)
                    all->maxb = temp->value;
                temp = temp->chain;
            }
        }
    all->countb = lstsize(all->lstb);
    return (all->countb);
}

int	check_args(char **str, t_swap **lst, int ac)
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
	return (0);
}

int    while_check_args_string(t_swap **lst, int i, int j, char **str)
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

int    while_check_args(t_swap **lst, int i, char **str)
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
