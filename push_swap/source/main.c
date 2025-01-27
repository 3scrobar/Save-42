/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/27 19:19:40 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	p_swap *lista;
	p_swap *listb;

	lista = NULL;
	listb = NULL;
	if (ac != 2)
		return (ft_putstr_fd("Error from argument\n",2), 1);
	check_args(av[1], lista);
	ra(&lista);
	lstiter(lista, ft_printfnumb);
	
	return (0);
}
int	check_args(char *str, p_swap *lst)
{
	long int	i;

	i = 0;
	while (*str)
	{
		if ((*str < '0' || *str > '9') && (*str != '-'))
			return (ft_putstr_fd("Error from NUMBER\n", 2), 1);
		if ((*str >= '0' && *str <= '9') || *str == '+' || *str == '-' )
			{
				i = atoi_long(str);
				if (i > INT_MAX || i < INT_MIN)
					return (ft_putstr_fd("Error int\n",2),1);
				if(lstcomp(lst, i) != 0)
					return (ft_putstr_fd("Error dup\n", 2), 1);
				lstadd_back(&lst, lstnew((int)i));
			}
			
		 while (*str && *str != ' ')
				str++;
		if (*str != '\0')
			str++;
	}
	lstiter(lst, ft_printfnumb);
	
	return (0);
}

void	ra(p_swap **lst)
{
	p_swap *temp;
	
	ft_printf("%d\n", (*lst)->value);
	temp = *lst;
	ft_printf("%d", temp->value);
	temp->chain = NULL;
	lstadd_back(lst, temp);
	*lst = (*lst)->chain;
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

void	lstadd_front(p_swap **lst, p_swap *new)
{
	new->chain = *lst;
	*lst = new;
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

void	lstdelone(p_swap *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	del(lst -> value);
	free(lst);
}

void	lstiter(p_swap *lst, int (*f)(int))
{
	while (lst != NULL)
	{
		f(lst -> value);
		lst = lst->chain;
	}
}
int	lstcomp(p_swap *lst, int nbr)
{
	while (lst != NULL)
	{
		if(nbr == lst->value)
			return(1);
		lst = lst->chain;
	}
	return (0);
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
long int	atoi_long(const char *nptr)
{
	int			i;
	int			neg;
	long int	c;

	i = 0;
	c = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = (c * 10) + (nptr[i] - '0');
		i++;
	}
	return (c * neg);
}
