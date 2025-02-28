/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:13:02 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:22:31 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_swap	*temp;

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
			break ;
		else if (get_clockwise(all, value) == all->countb)
			break ;
		else
			if (get_clockwise(all, value) >= all->countb / 2)
				while (first_tier(all,all->lstb->value) != 1)
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
