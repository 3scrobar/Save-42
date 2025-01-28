/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:40:22 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 12:41:40 by tle-saut         ###   ########.fr       */
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
