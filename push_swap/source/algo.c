/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:01 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 13:38:58 by tle-saut         ###   ########.fr       */
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
    if (all->lsta->value > all->lsta->chain->value && all->lsta->chain->value < all->lsta->chain->chain->value)
        sa(all);
    else if (all->lsta->value > all->lsta->chain->chain->value)
    {
        ra(all);
        sa(all);
        rra(all);
    }
    else if (all->lsta->value > all->lsta->chain->value)
        ra(all);
    else if (all->lsta->chain->value > all->lsta->chain->chain->value)
    {
        sa(all);
        ra(all);
        sa(all);
        rra(all);
    }
}