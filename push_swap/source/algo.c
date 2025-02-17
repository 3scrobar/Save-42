/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:33:34 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/17 16:09:46 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void    algo(t_all *all)
{
	while (check_sorted_lsta(all) == 0)
	{
		count_all(all, 1);
		if (all->counta == 2)
			sort_two(all);
		else if (all->counta == 3)
			sort_three_lsta(all);
		else if (all->counta > 3)
			sort_more(all);
		count_all(all, 1);
	}
}

void	sort_more(t_all *all)
{
	push_b(all);
	while (check_sorted_lsta(all) == 0 || all->countb != 0 )
	{
		while (all->counta == 3 && check_list_sort(all->lsta) == 0)
			sort_three_lsta(all);
		if (check_list_sort(all->lsta) == 1 && all->countb == 0)
			return;
		push_back_a(all);
		if (check_list_sort(all->lsta) == 0)
			push_b(all);
		count_all(all, 1);

	}

}

void	push_b(t_all *all)
{
	while (all->counta > 3 && check_list_sort(all->lsta) == 0)
	{
		if (all->countb == 0)
			pb(all);
		count_all(all, 1);
		if (all->countb == 3 && check_list_sort(all->lstb) == 0)
			sort_three_lstb(all);
		else if (all->counta == 3)
			break;
		else
			pb(all);
		count_all(all, 1);
	}
}

void    push_back_a(t_all *all)
{
	int i;
	int j;

	j = 0;
	count_all(all, 1);
	while (all->countb != 0)
	{
		if (all->lstb->value > all->maxa)
		{
			pa(all);
			print_lst(all);
			printf("%d", all->countb);
			if(all->lstb)
				if (all->lstb->value > lst_givelast(all->lsta) && all->lstb->value < all->lsta->value)
					{
						pa(all);
						sa(all);
					}
		}
		else if (get_between(all, all->lstb->value) != 0)
			{
				i = get_between(all, all->lstb->value);
				j = get_between(all, all->lstb->value);
				mv_index(all, i);
				pa(all);

			}

		else if (all->lstb->value < all->lsta->value)
			pa(all);
		else if (all->lstb->value > lst_givelast(all->lsta))
			{
				pa(all);
				ra(all);
			}
		count_all(all, 1);
	}
	while (all->lsta->value != all->mina)
		{

			if (j > all->counta / 2)
				while (all->lsta->value != all->mina)
					ra(all);
			else 
				while (all->lsta->value != all->mina)
					rra(all);
		}
}

void	mv_index(t_all *all, int i)
{
	if ( i > all->counta / 2)
		{
			i /= 2;
			while (i > 0)
			{
				rra(all);
				i--;
			}
		}
	else
		while (i > 0)
		{
			ra(all);
			i--;
		}
	pa(all);
	count_all(all, 1);
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

int	get_between(t_all *all, int i)
{
	t_swap *temp;
	int j;

	j = 0;
	temp = all->lsta;
	while (temp && j != all->counta - 1)
	{
		if((i > temp->value && i < temp->chain->value )||( i < temp->value && i > temp->chain->value))
			return (j + 1);
		j++;
		temp = temp->chain;
	}
	return (0);
}

int	 lst_give_bef_last(t_swap *lst)
{
	t_swap *temp;

	temp = lst;
	while (temp->chain->chain)
		temp = temp->chain;
	return (temp->value);
}

