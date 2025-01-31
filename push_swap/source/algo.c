/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:01 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/31 14:18:38 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_all *all)
{
    if (all->lsta->value > all->lsta->chain->value)
        sa(all);
}

void    sort_three(p_swap *lst, t_all *all)
{
    while (check_list_sort(lst) == 0)
    {
        if (lst->value > lst->chain->value && lst->value < lst->chain->chain->value)
            sa(all);
        else if (lst->value > lst->chain->value && lst->value > lst->chain->chain->value)
        {
            sa(all);
            rra(all);
        }
        else if (lst->value < lst->chain->value && lst->value > lst->chain->chain->value)
            ra(all);
        else if (lst->value < lst->chain->value && lst->chain->value > lst->chain->chain->value)
        {
            sa(all);
            ra(all);
        }
    }
    
}

void    sort_three_reverse(p_swap *lst, t_all *all)
{
    while (check_list_sort(lst) == 0)
    {
        if (lst->value < lst->chain->value && lst->value > lst->chain->chain->value)
            sb(all);
        else if (lst->value < lst->chain->value && lst->value < lst->chain->chain->value)
        {
            sb(all);
            rb(all);
        }
        else if (lst->value > lst->chain->value && lst->value < lst->chain->chain->value)
            rb(all);
        else if (lst->value > lst->chain->value && lst->chain->value < lst->chain->chain->value)
        {
            sb(all);
            rb(all);
        }
    }
}

void    sort_multiple(t_all *all)
{
    while (all->counta > 3 && all->first == 0)
    {
        push_lstb(all);
        count_all_lsta(all, 1);
        while (all->countb == 3 && check_list_sort_reverse(all->lstb) != 1)
            sort_three_reverse(all->lstb, all);
    }
    while (check_list_sort(all->lsta) == 0)
        sort_three(all->lsta, all);
    count_all_lstb(all, 1);
    while (all->countb > 0)
    {
        if (all->countb == 3 && check_list_sort_reverse(all->lstb) == 0)
            sort_three_reverse(all->lstb, all);
        else if (all->lstb->value > lst_givelast(all->lsta))
        {
            pa(all);
            ra(all);
        }
        else if (all->lstb->value < all->lsta->value)
            pa(all);
        else if (all->lstb->value < all->lsta->chain->value)
            {
                ra(all);
                pa(all);
                rra(all);
            }
        else
            {
                pa(all);
                ra(all);
            }
        count_all_lstb(all,1);
    }
}

void    push_lstb(t_all *all)
{
    count_all_lstb(all, 1);
    if(all->countb == 0)
        pb(all);
    else if (all->lsta->value > all->maxb)
        pb(all);
    else if (all->lsta->value < all->minb)
    {
        pb(all);
        rb(all);
    }
    else if (all->lsta->value < lst_givelast(all->lstb))
        {
            pb(all);
            rb(all);
        }
    else
        pb(all);

}