/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:29:24 by tle-saut          #+#    #+#             */
/*   Updated: 2025/03/03 15:40:13 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_push_back_a(int firsta, int firstb, int lasta, t_all *all)
{
	if ((firstb > firsta && firstb < all->lsta->chain->value)
		|| (firstb > lasta && firstb < firsta))
	{
		if (firstb > firsta && firstb < all->lsta->chain->value)
		{
			pa(all);
			sa(all);
		}
		else
			pa(all);
	}
	else if (firstb > all->maxa)
	{
		all->i = get_index(all, all->maxa);
		all->i++;
	}
	else if (firstb < all->mina)
	{
		all->i = get_index(all, all->mina);
		if (all->i == 0)
			all->i = -1;
	}
	else
		else_if_pba(all);
}

void	else_if_pba(t_all *all)
{
	all->i = get_between(all, all->lstb->value);
	if (all->i == 0)
		all->i = -1;
}

void	if_2_push_back_a(t_all *all)
{
	if (all->i > all->counta / 2)
	{
		all->i = all->counta - all->i;
		while (all->i--)
			rra(all);
		pa(all);
	}
	else if (all->i != -1 && all->i <= all->counta / 2 && all->i != 0)
	{
		while (all->i--)
			ra(all);
		pa(all);
	}
	else if (all->i == -1)
		pa(all);
}
