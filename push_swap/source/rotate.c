/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:41:54 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 22:59:40 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(p_swap **lst)
{
	p_swap *temp;

	temp = *lst;
	*lst = (*lst)->chain;
	temp->chain = NULL;
	lstadd_back(lst, temp);
}

void    ra(t_all *all)
{
    rotate(&all->lsta);
    ft_printf("ra\n");
}

void    rb(t_all *all)
{
    rotate(&all->lstb);
    ft_printf("rb\n");
}

void rr(t_all *all)
{
    rotate(&all->lsta);
    rotate(&all->lstb);
    ft_printf("rr\n");
}