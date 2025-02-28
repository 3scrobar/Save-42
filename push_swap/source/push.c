/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:11 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 19:02:10 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_swap **lst1, t_swap **lst2)
{
	t_swap	*temp;

	if (*lst1 == NULL)
		return ;
	temp = *lst1;
	if (*lst2 == NULL)
	{
		*lst2 = temp;
		*lst1 = (*lst1)->chain;
		temp->chain = NULL;
		return ;
	}
	*lst1 = (*lst1)->chain;
	temp->chain = *lst2;
	*lst2 = temp;
}

//push b -> a
void	pa(t_all *all)
{
	push(&all->lstb, &all->lsta);
	ft_printf("pa\n");
}

//push a -> b
void	pb(t_all *all)
{
	push(&all->lsta, &all->lstb);
	ft_printf("pb\n");
}
