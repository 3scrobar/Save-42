/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:15:56 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 23:00:20 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(p_swap **lst)
{
	p_swap *temp;
	p_swap *last;
	p_swap *second_last;

	if (*lst == NULL || (*lst)->chain == NULL)
		return;

	temp = *lst;
	while (temp->chain && temp->chain->chain)
	{
		temp = temp->chain;
	}

	second_last = temp;
	last = temp->chain;

	second_last->chain = NULL;
	last->chain = *lst;
	*lst = last;
}

void	rra(t_all *all)
{
	reverse_rotate(&all->lsta);
	ft_printf("rra\n");
}

void	rrb(t_all *all)
{
	reverse_rotate(&all->lstb);
	ft_printf("rrb\n");
}

void	rrr(t_all *all)
{
	reverse_rotate(&all->lsta);
	reverse_rotate(&all->lstb);
	ft_printf("rrr\n");
}
