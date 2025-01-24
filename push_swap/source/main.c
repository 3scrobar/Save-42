/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:07 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/24 17:12:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list lsta;
	t_list lstb;

	(void)lstb;
	if (ac != 2)
		ft_putstr_fd("Error from argument\n",2);
	check_args(av[1]);
	give_nb(av[1], &lsta);
	ft_lstiter(&lsta, print_content);
	return (0);
}
int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] < '9') || str[i] == ' ' || str[i] == '-' )
			i++;
		else
		{
			return (ft_putstr_fd("Error put some good args\n", 2), 1);
		}
	}
	return (0);
}
int	give_nb(char *str, t_list *lst)
{
	t_list *tmp;
	int i;

	while (*str)
		{
			if (*str == ' ')
				str++;
			else
			{
				i = ft_atoi(str);
				tmp = ft_lstnew(&i);
				ft_lstadd_back(&lst, tmp);
				while (*str && *str != ' ')
					str++;
			}
		}
	return (0);
}
void print_content(void *content)
{
    printf("%d\n", *(int *)content);
}