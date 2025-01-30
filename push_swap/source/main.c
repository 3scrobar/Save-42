/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/30 18:02:13 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all all;

	all.lsta = NULL;
	all.lstb = NULL;
	if (ac < 2)
		return (ft_putstr_fd("Error from argument\n",2), 1);
	if (check_args(av, &all.lsta, ac) != 0)
		return (ft_putstr_fd("Error from check_args\n",2), 1);
	count_all(&all);
	check_sort(&all);
	return (0);
}

int	check_sort(t_all *all)
{
	while (check_list_sort(all->lsta) != 1)
		{
			count_all_lsta(all, 1);
			if (check_list_sort(all->lsta) == 0 && all->counta == 2)
				sort_two(all);
			while (check_list_sort(all->lsta) == 0 && all->counta == 3)
				sort_three(all);
			while (check_list_sort(all->lsta) == 0 && all->counta > 3)
				sort_multiple(all);
		}
	
	return (0);
}

int	check_list_sort(p_swap *lst)
{
	p_swap *temp;

	temp = lst;
	while (temp->chain != NULL)
	{
		if (temp->value > temp->chain->value)
			return (0);
		temp = temp->chain;
	}
	return (1);
}

void	count_all(t_all *all)
{
	all->counta = lstsize(all->lsta);
	all->countb = lstsize(all->lstb);
}