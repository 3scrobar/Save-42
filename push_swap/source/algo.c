/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:01 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/30 18:52:28 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_all *all)
{
    if (all->lsta->value > all->lsta->chain->value)
        sa(all);
}

void    sort_three(t_all *all)
{
    if (all->lsta->value > all->lsta->chain->value && all->lsta->value < all->lsta->chain->chain->value)
        sa(all);
    if (all->lsta->value > all->lsta->chain->value && all->lsta->value > all->lsta->chain->chain->value)
    {
        sa(all);
        rra(all);
    }
    if (all->lsta->value < all->lsta->chain->value && all->lsta->value > all->lsta->chain->chain->value)
        ra(all);
    if (all->lsta->value < all->lsta->chain->value && all->lsta->chain->value > all->lsta->chain->chain->value)
    {
        sa(all);
        ra(all);
    }
}

void    sort_multiple(t_all *all)
{
    while (all->counta > 3 && all->first == 0)
    {
        push_lstb(all);
        count_all_lsta(all, 1);
        all->first = 1;
    }
    sort_three(all);
    count_all_lstb(all, 1);
    while (all->countb > 0)
    {
        if (all->lstb->value < all->mina)
            pa(all);
        else if (all->lstb->value < all->maxa)
        {
            pa(all);
            ra(all);
        }
        else if (all->lstb->value > all->lsta->value && all->lstb->value > all->lsta->chain->value)
            {
                ra(all);
                pa(all);
                rra(all);
            }
        else if (all->lstb->value > all->lsta->value && all->lstb->value < all->lsta->chain->value)
            {
                pa(all);
                sa(all);
            }
        else if (count_all_lstb(all, 0) != 1)
            rb(all);
        count_all_lstb(all, 0);
        count_all_lsta(all, 1);
    }
    if (count_all_lstb(all, 0) == 1)
        pa(all);
}

void    push_lstb(t_all *all)
{
    if(all->countb == 0)
        pb(all);
    count_all_lstb(all, 1);
    if (all->lsta->value < all->minb)
        pb(all);
    else if (all->lsta->value < all->maxb)
    {
        pb(all);
        rb(all);
    }
    else if (all->lsta->value > all->lstb->value && all->lsta->value > all->lstb->chain->value)
        {
            rb(all);
            pb(all);
            rrb(all);
        }
    else if (all->lsta->value > all->lstb->value && all->lsta->chain->value > all->lstb->chain->value)
        {
            pb(all);
            sb(all);
        }
    else if (count_all_lstb(all, 1) != 1)
        ra(all);
}