/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:57:35 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all	all;

	all.lsta = NULL;
	all.lstb = NULL;
	all.first = 0;
	if (ac < 2)
		return (ft_putstr_fd("Error from argument\n", 2), 1);
	if (check_args(av, &all.lsta, ac) != 0)
		return (ft_putstr_fd("Error from check_args\n", 2), 1);
	count_all(&all, 1);
	while (check_sorted_lsta(&all) == 0)
		algo(&all);
	lstclear(all.lsta);
	return (0);
}

int	check_list_sort(t_swap *lst)
{
	t_swap	*temp;

	if (lst == NULL)
		return (1);
	temp = lst;
	while (temp->chain != NULL)
	{
		if (temp->value > temp->chain->value)
			return (0);
		temp = temp->chain;
	}
	return (1);
}

void	count_all(t_all *all, int i)
{
	all->minb = INT_MAX;
	all->maxb = INT_MIN;
	all->mina = INT_MAX;
	all->maxa = INT_MIN;
	count_all_lsta(all, i);
	count_all_lstb(all, i);
	if (all->mina < all->minb)
		all->mintot = all->mina;
	else
		all->mintot = all->minb;
	if (all->maxa > all->maxb)
		all->maxtot = all->maxa;
	else
		all->maxtot = all->maxb;
	all->range = all->maxtot - all->mintot;
	while (all->range % 3 != 0)
		all->range++;
}
