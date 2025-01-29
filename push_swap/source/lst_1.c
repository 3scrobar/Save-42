/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:38:00 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 14:03:08 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(p_swap *lst)
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

p_swap	*lstnew(int value)
{
	p_swap	*new_node;

	new_node = malloc(sizeof(p_swap));
	if (new_node == NULL)
		return (NULL);
	new_node -> chain = NULL;
	new_node -> value = value;
	return (new_node);
}

int	lstcomp(p_swap *lst, int nbr)
{
    p_swap *temp;
    
    temp = lst;
	while (temp != NULL)
	{
		if(nbr == temp->value)
			return(1);
		temp = temp->chain;
	}
	return (0);
}

p_swap	*lstmap(p_swap *lst, int (*f)(int), void (*del)(int), void (*delv)(void *))
{
	p_swap	*current;
	p_swap	*result;
	p_swap	*new_node;

	result = NULL;
	current = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (current != NULL)
	{
		new_node = lstnew(f(current->value));
		if (new_node == NULL)
		{
			delv(new_node);
			lstclear(&result, del);
			return (NULL);
		}
		lstadd_back(&result, new_node);
		current = current->chain;
	}
	return (result);
}

p_swap	*lstlast(p_swap *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->chain != NULL)
	{
		lst = lst->chain;
	}
	return (lst);
}