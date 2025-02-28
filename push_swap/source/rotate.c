/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:41:54 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 19:05:07 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_swap **lst)
{
	t_swap	*temp;

	temp = *lst;
	*lst = (*lst)->chain;
	temp->chain = NULL;
	lstadd_back(lst, temp);
}

//move up lista
void	ra(t_all *all)
{
	rotate(&all->lsta);
	ft_printf("ra\n");
}

//move up lisb
void	rb(t_all *all)
{
	rotate(&all->lstb);
	ft_printf("rb\n");
}

//move up lista & listb
void	rr(t_all *all)
{
	rotate(&all->lsta);
	rotate(&all->lstb);
	ft_printf("rr\n");
}
