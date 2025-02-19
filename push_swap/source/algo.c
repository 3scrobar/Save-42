/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:21:10 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/19 17:25:49 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algo(t_all *all)
{
	if (lstsize(all->lsta) == 2)
		sort_two(all);
	else if (lstsize(all->lsta) == 3)
		sort_three_lsta(all);
	else if (check_list_sort(all->lsta) == 0)
		sort_more(all);
}

void	sort_more(t_all *all)
{
	int firstb;
	int lastb;
	int firsta;
	int i;

	while (all->counta > 3)
	{
		if (all->countb != 0)
		{
			firstb = all->lstb->value;
			lastb = lst_givelast(all->lstb);
		}
		firsta = all->lsta->value;
		if (all->countb == 0)
			pb(all);
		else if (firsta > firstb)
			pb(all);
		else if (firsta < lastb)
			{
				pb(all);
				rb(all);
			}
		else
			pb(all);
		count_all(all, 1);
	}
	sort_three_lsta(all);
	while (all->countb != 0)
	{
		push_back_a(all);
		count_all(all, 1);
	}
	while (check_list_sort(all->lsta) == 0)
	{
		i = get_index(all, all->mina);
		if (i > all->counta / 2)
			while (all->lsta->value != all->mina)
				rra(all);
		else
			while (all->lsta->value != all->mina)
				ra(all);
	}
}

void	push_back_a(t_all *all)
{
	int i;
	int firsta;
	int firstb;
	int lasta;

	i = 0;
	if (all->countb != 0)
		firstb = all->lstb->value;
	else
		firstb = 0;
	firsta = all->lsta->value;
	lasta = lst_givelast(all->lsta);
	if ((firstb > firsta && firstb < all->lsta->chain->value) || (firstb > lasta && firstb < firsta))
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
		i = get_index(all, all->maxa);
		printf("i = %d\n", i);
		i++;
	}
	else if (firstb < all->mina)
	{
		i = get_index(all, all->mina);
		if (i == 0)
			i = -1;
	}
	else
		{
			i = get_between(all, all->lstb->value);
			if (i == 0)
				i = -1;
		}
	if (i > all->counta / 2)
		{
			i = all->counta - i;
			while (i--)
				rra(all);
			pa(all);
		}
	else if (i != -1 && i <= all->counta / 2 && i != 0)
	{
		while (i--)
			ra(all);
		pa(all);
	}
	else if (i == -1)
		pa(all);
}

int	get_between(t_all *all, int i)
{
	t_swap *temp;
	int j;

	j = 0;
	temp = all->lsta;
	while (temp && j != all->counta)
	{
		if((i > temp->value && i < temp->chain->value ))
			return (j + 1);
		j++;
		temp = temp->chain;
	}
	return (0);
}

int	get_index(t_all *all, int i)
{
	t_swap *temp;
	int j;

	j = 0;
	temp = all->lsta;
	while (temp)
	{
		if (temp->value == i)
			return (j);
		j++;
		temp = temp->chain;
	}
	return (0);
}