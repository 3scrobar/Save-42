/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:13 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:51:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_lsta(t_all *all)
{
	t_swap	*temp;

	temp = all->lsta;
	while (temp->chain)
	{
		if (temp->value > temp->chain->value)
			return (0);
		temp = temp->chain;
	}
	return (1);
}

int	check_sorted_lstb(t_all *all)
{
	t_swap	*temp;

	temp = all->lstb;
	while (temp->chain)
	{
		if (temp->value < temp->chain->value)
			return (0);
		temp = temp->chain;
	}
	return (1);
}

int	count_all_lsta(t_all *all, int a)
{
	t_swap	*temp;

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

int	count_all_lstb(t_all *all, int a)
{
	t_swap	*temp;

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
