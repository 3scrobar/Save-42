/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:33:34 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/13 18:11:03 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void    algo(t_all *all)
{
	count_all_lsta(all, 1);
	while (check_sorted_lsta(all) != 1 || all->countb != 0)
		{
	        count_all_lsta(all, 1);
			if (check_sorted_lsta(all) == 0 && all->counta == 2)
				sort_two(all);
			while (check_sorted_lsta(all) == 0 && all->counta == 3)
				sort_three_lsta(all);
            while (all->counta > 3 && check_sorted_lsta(all) == 0)
            {
                push_b(all);
                count_all_lsta(all, 1);
                count_all_lstb(all, 1);
            }
            while (all->counta == 3 && check_sorted_lsta(all) == 0)
                sort_three_lsta(all);
            while (all->countb > 0)
                {
                    if (all->lstb->value < all->lsta->value)
                        pa(all);
                    else if (all->lstb->value > lst_givelast(all->lsta))
                        {
                            pa(all);
                            ra(all);
                        }
                    else if (all->lstb->value < all->lsta->chain->value)
                        {
                            pa(all);
                            sa(all);
                        }
                    else if (all->lstb->value > lst_give_bef_last(all->lsta) && all->lstb->value < lst_givelast(all->lsta))
                        {
                            rra(all);
                            pa(all);
                            ra(all);
                            ra(all);
                        }
                    else
                            ra(all);
                    count_all_lstb(all, 1);
                    count_all_lsta(all, 1);
                }
        }
}
void    push_b(t_all *all)
{
    count_all_lstb(all, 1);
    count_all_lsta(all, 1);
    while (all->counta > 3)
        {
            if (all->counta == 3 && check_sorted_lsta(all) == 0)
                sort_three_lsta(all);
            if (all->countb == 3 && check_sorted_lstb(all) == 0)
                sort_three_lstb(all);
            if (all->countb == 0)
                pb(all);
            else if (all->lsta->value > all->lstb->value)
                pb(all);
            else if (all->lsta->value < lst_givelast(all->lstb))
                {
                    pb(all);
                    rb(all);
                }
            else if (all->lsta->value > lst_givelast(all->lstb) && all->lsta->value < lst_give_bef_last(all->lstb))
                {
                    rrb(all);
                    pb(all);
                    rb(all);
                    rb(all);
                }
            else
                pb(all);
            count_all_lstb(all, 1);
            count_all_lsta(all, 1);
        }
    
}

int    lst_give_bef_last(t_swap *lst)
{
    t_swap *temp;

    temp = lst;
    while (temp->chain->chain)
        temp = temp->chain;
    return (temp->value);
}

void    push_back_a(t_all *all)
{   
    int i;

    count_all_lstb(all, 1);
    i = all->countb - 1;
    if (all->countb == 0)
        return ;
    if (lst_givelast(all->lstb) < all->lsta->value)
            return ;
    while (i > 0)
        {
            rrb(all);
            i--;
        }
    while (all->countb > 0)
        {
            pa(all);
            count_all_lstb(all, 1);
        }
    

}

