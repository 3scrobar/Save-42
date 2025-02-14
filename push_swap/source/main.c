/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/14 15:33:51 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all all;

	all.lsta = NULL;
	all.lstb = NULL;
	all.first = 0;
	if (ac < 2)
		return (ft_putstr_fd("Error from argument\n",2), 1);
	if (check_args(av, &all.lsta, ac) != 0)
		return (ft_putstr_fd("Error from check_args\n",2), 1);
	count_all(&all, 1);
	while (check_sorted_lsta(&all) == 0)
		algo(&all);
	//print_lst(&all);
	return (0);
}


int	check_list_sort(t_swap *lst)
{
	t_swap *temp;

	if (lst == NULL)
		return (1);
	temp = lst;
	while (temp->chain != NULL)
		{
			if (temp->value > temp->chain->value)
				return (0);
			temp = temp->chain;
		}
	return (1);
}

void	count_all(t_all *all, int i)
{
	count_all_lsta(all, i);
	count_all_lstb(all, i);
}