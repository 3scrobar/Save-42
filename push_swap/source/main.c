/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 13:25:45 by tle-saut         ###   ########.fr       */
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
	ft_printf("Liste A\n");
	lstiter(all.lsta, ft_printfnumb_nl);
	ft_printf("Liste B\n");
	lstiter(all.lstb, ft_printfnumb_nl);
	reverse_rotate(&all.lsta);

	ft_printf("Liste A\n");
	lstiter(all.lsta, ft_printfnumb_nl);
	ft_printf("Liste B\n");
	lstiter(all.lstb, ft_printfnumb_nl);
	
	return (0);
}
int	check_args(char **str, p_swap **lst)
{
	long int	nb;
	int			i;
	int			j;

	i = 1;
	j = 0;
	nb = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && (str[i][j] != '-'))
				return (ft_putstr_fd("Error from NUMBER\n", 2), 1);
			if ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '+' || str[i][j] == '-' )
				{
					nb = atoi_long(str[i]);
					if (nb > INT_MAX || nb < INT_MIN)
						return (ft_putstr_fd("Error int\n",2),1);
					if(lstcomp(*lst, nb) != 0)
						return (ft_putstr_fd("Error dup\n", 2), 1);
					lstadd_back(lst, lstnew((int)nb));
				}
			j++;
		}
		i++;
	}
	ft_printf("\n");
	return (0);
}


