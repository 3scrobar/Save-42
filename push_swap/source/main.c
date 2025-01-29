/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 13:52:09 by tle-saut         ###   ########.fr       */
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
	if (check_args(av, &all.lsta) != 0)
		return (ft_putstr_fd("Error from check_args\n",2), 1);
	print_lst(&all);

	print_lst(&all);
	
	return (0);
}


void	print_lst(t_all *all)
{
	ft_printf("Liste A\n");
	lstiter(all->lsta, ft_printfnumb_nl);
	ft_printf("Liste B\n");
	lstiter(all->lstb, ft_printfnumb_nl);
}
