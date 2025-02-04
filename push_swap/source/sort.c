/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:33:46 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/04 17:33:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void    sort_two(t_swap *lst)
{
    if (lst->value > lst->chain->value)
        sa(lst);
}

void    sort_three_lsta(t_swap *lst)
{
    int first;
    int second;
    int third;

    first = lst->value;
    second = lst->chain->value;
    third = lst->chain->chain->value;
    if (first > second && first > third)
        ra(lst);
    else if (first < second && first > third)
        rra(lst);
    else if (first < second && first < third && second > third)
        sa(lst);
}

void    sort_three_lstb(t_swap *lst)
{
    int first;
    int second;
    int third;

    first = lst->value;
    second = lst->chain->value;
    third = lst->chain->chain->value;
    if (first > second && first > third)
        rb(lst);
    else if (first < second && first > third)
        rrb(lst);
    else if (first < second && first < third && second > third)
        sb(lst);
}
