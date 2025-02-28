/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:21:10 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:05:15 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_all *all)
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
	int	i;

	while (all->counta > 3)
	{
		count_all(all, 1);
		push_b(all);
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
	int	i;
	int	firsta;
	int	firstb;
	int	lasta;

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
	t_swap	*temp;
	int		j;

	j = 0;
	temp = all->lsta;
	while (temp && j != all->counta)
	{
		if ((i > temp->value && i < temp->chain->value ))
			return (j + 1);
		j++;
		temp = temp->chain;
	}
	return (0);
}

int	get_index(t_all *all, int i)
{
	t_swap	*temp;
	int		j;

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

void	push_b(t_all *all)
{
	if (all->countb < 3 && all->counta > 3)
		pb(all);
	else if (all->countb == 3 && check_sorted_lstb(all) == 0 && all->counta > 3)
		sort_three_lstb(all);
	else if (all->countb >= 3 && all->counta > 3)
		{
			rotate_b(all);
		}
	count_all(all, 1);
}


void	rotate_b(t_all *all)
{
	t_swap *temp;

	temp = all->lsta;
	if (check_tier(all) == 0)
		pb(all);
	else if (first_tier(all, temp->value) == 1 && check_tier(all) == 1)
			move_tier_1(all);
	else if (second_tier(all, temp->value) == 1 && check_tier(all) == 1)
			move_tier_2(all);
	else if (third_tier(all, temp->value) == 1 && check_tier(all) == 1)
			move_tier_3(all);
	else
		pb(all);
	temp = temp->chain;

}

void	move_tier_1(t_all *all)
{
	int	value;

	value = all->lstb->value;
	while (first_tier(all, value) != 1)
		{
			value = all->lstb->value;
			if (first_tier(all, value) == 1 && check_tier(all) == 1)
				break;
			else if (get_clockwise(all, value) == all->countb)
				break;
			else
				if (get_clockwise(all, value) >= all->countb / 2)
					while (first_tier(all,all->lstb->value)!= 1)
						rrb(all);
				else
					while (first_tier(all,all->lstb->value)!= 1)
						rb(all);
			if (all->counta > 3)
				pb(all);
		}
	if (first_tier(all, all->lstb->value) == 1 && all->counta > 3)
		pb(all);
	}

void	move_tier_2(t_all *all)
{
	int	value;

	value = all->lstb->value;
	while (second_tier(all, value) != 1 && check_tier(all) == 1)
		{
			value = all->lstb->value;

			if (second_tier(all, value) == 1)
				break;
			else if (get_clockwise(all, value) == all->countb)
				break;
			else
				if (get_clockwise(all, value) >= all->countb / 2)
					while (second_tier(all,all->lstb->value)!= 1)
						rrb(all);
				else
					while (second_tier(all,all->lstb->value)!= 1)
						rb(all);
			if (all->counta > 3)
				pb(all);
		}
	if (second_tier(all, all->lstb->value) == 1 && all->counta > 3)
		pb(all);
}

void	move_tier_3(t_all *all)
{
	int	value;

	value = all->lstb->value;
	while (third_tier(all, value) != 1 && check_tier(all) == 1)
	{
		value = all->lstb->value;
		if (third_tier(all, value) == 1)
			break;
		else if (get_clockwise(all, value) == all->countb)
			break;
		else
			if (get_clockwise(all, value) >= all->countb / 2)	
				while (third_tier(all,all->lstb->value)!= 1)
					rrb(all);
			else
				while (third_tier(all,all->lstb->value)!= 1)
					rb(all);
		if (all->counta > 3)
			pb(all);
	}
	if (third_tier(all, all->lstb->value) == 1 && all->counta > 3)
		pb(all);

}

int	first_tier(t_all *all, int i)
{

	count_all(all, 1);
	if (i > all->mintot + ((all->range / 3) * 2))
	{
		return (1);
	}
	return (0);
	}

int	second_tier(t_all *all, int i)
{
	count_all(all, 1);
	if (i > all->mintot + (all->range / 3) && i <= all->mintot + (all->range / 3) * 2)
		return (1);
	else
		return (0);
}

int	third_tier(t_all *all, int i)
{
	count_all(all, 1);
	if (i < all->mintot + (all->range / 3))
		return (1);
	else
		return (0);
}

int	check_tier(t_all *all)
{
	t_swap	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	temp = all->lstb;
	while (temp)
	{
		if (first_tier(all, temp->value) == 1)
			i = 1;
		else if (second_tier(all, temp->value) == 1)
			j = 1;
		else if (third_tier(all, temp->value) == 1)
			k = 1;
		temp = temp->chain;
	}
	if ( i == 1 && j == 1 && k == 1)
		return (1);
	else
		return (0);
}

int	get_clockwise(t_all *all, int i)
{
	t_swap	*temp;
	int	j;

	j = 0;
	temp = all->lstb;
	while (temp && j != all->countb)
	{	
		if (temp->chain == NULL)
			return (pb(all), 0);
		if((i < temp->value && i > temp->chain->value ))
			return (j + 1);
		j++;
		temp = temp->chain;
	}
	return (0);
}