/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:15:56 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/04 17:23:46 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_swap **lst)
{
	t_swap *temp;
	t_swap *last;
	t_swap *second_last;

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

//move down lista
void	rra(t_all *all)
{
	reverse_rotate(&all->lsta);
	ft_printf("rra\n");
}

//move down listb
void	rrb(t_all *all)
{
	reverse_rotate(&all->lstb);
	ft_printf("rrb\n");
}

//move down lista & listb
void	rrr(t_all *all)
{
	reverse_rotate(&all->lsta);
	reverse_rotate(&all->lstb);
	ft_printf("rrr\n");
}
