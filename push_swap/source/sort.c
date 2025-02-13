/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:33:46 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/13 18:05:28 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void    sort_two(t_all *all)
{
    if (all->lsta->value > all->lsta->chain->value)
        sa(all);
}

void    sort_three_lsta(t_all *all)
{
    int first;
    int second;
    int third;

    first = all->lsta->value;
    second = all->lsta->chain->value;
    third = all->lsta->chain->chain->value;
    if (first > second && first > third)
        ra(all);
    else if (first < second && first > third)
        rra(all);
    else if (first > second && first < third)
        sa(all);
    else if (first < second && first < third && second > third)
        ra(all);
    else if (first > second && first < third && second < third)
        sa(all);


}

void    sort_three_lstb(t_all *all)
{
    int first;
    int second;
    int third;

    first = all->lstb->value;
    second = all->lstb->chain->value;
    third = all->lstb->chain->chain->value;
    if (first > second && first > third && second < third)
        {
            rrb(all);
            sb(all);
        }
    else if (first < second && first > third && second > third)
            sb(all);
    else if (first > second && first < third && second < third)
        rrb(all);
    else if (first < second && second < third)
        {
            rb(all);
            sb(all);
        }
}
