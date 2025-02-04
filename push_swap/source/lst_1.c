/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:38:00 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/04 17:22:56 by toto             ###   ########.fr       */
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
    t_swap *temp;
    
    temp = lst;
	while (temp != NULL)
	{
		if(nbr == temp->value)
			return(1);
		temp = temp->chain;
	}
	return (0);
}

t_swap	*lstmap(t_swap *lst, int (*f)(int), void (*del)(int), void (*delv)(void *))
{
	t_swap	*current;
	t_swap	*result;
	t_swap	*new_node;

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