/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:01 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 15:38:42 by toto             ###   ########.fr       */
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