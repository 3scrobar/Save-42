/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:40:22 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:56:10 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstiter(t_swap *lst, int (*f)(int))
{
	while (lst != NULL)
	{
		f(lst -> value);
		lst = lst->chain;
	}
}

void	lstclear(t_swap *lst)
{
	t_swap	*temp;
	t_swap	*current;

	if (lst == NULL)
		return ;
	current = lst;
	while (current != NULL)
	{
		temp = current;
		current = current->chain;
		free(temp);
	}
}

void	lstadd_front(t_swap **lst, t_swap *new)
{
	new->chain = *lst;
	*lst = new;
}

void	lstadd_back(t_swap **lst, t_swap *new)
{
	t_swap	*new_one;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_one = *lst;
	while (new_one->chain != NULL)
		new_one = new_one->chain;
	new_one->chain = new;
}

int	lst_givelast(t_swap *lst)
{
	t_swap	*temp;

	temp = lst;
	while (temp->chain)
		temp = temp->chain;
	return (temp->value);
}
