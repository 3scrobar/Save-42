/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:40:22 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/30 19:16:27 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstiter(p_swap *lst, int (*f)(int))
{
	while (lst != NULL)
	{
		f(lst -> value);
		lst = lst->chain;
	}
}

void	lstdelone(p_swap *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	del(lst -> value);
	free(lst);
}

void	lstclear(p_swap **lst, void (*del)(int))
{
	p_swap	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)->chain;
		lstdelone(*lst, del);
		*lst = temp;
	}
}

void	lstadd_front(p_swap **lst, p_swap *new)
{
	new->chain = *lst;
	*lst = new;
}

void	lstadd_back(p_swap **lst, p_swap *new)
{
	p_swap	*new_one;

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

int lst_givelast(p_swap *lst)
{
	p_swap *temp;

	temp = lst;
	while (temp->chain)
		temp = temp->chain;
	return (temp->value);
}
