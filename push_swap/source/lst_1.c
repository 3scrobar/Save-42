/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:38:00 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:55:35 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_swap *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> chain;
		i++;
	}
	return (i);
}

t_swap	*lstnew(int value)
{
	t_swap	*new_node;

	new_node = malloc(sizeof(t_swap));
	if (new_node == NULL)
		return (NULL);
	new_node -> chain = NULL;
	new_node -> value = value;
	return (new_node);
}

int	lstcomp(t_swap *lst, int nbr)
{
	t_swap	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (nbr == temp->value)
			return (1);
		temp = temp->chain;
	}
	return (0);
}

t_swap	*lstlast(t_swap *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->chain != NULL)
	{
		lst = lst->chain;
	}
	return (lst);
}
