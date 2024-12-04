/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 17:34:12 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	i = ft_init_map(&map, av[1]);
	if (ac != 2)
		return (write(2, "Error from argument\n", 21), 1);
	if (i == 0)
		return (1);
	if (ft_parsing(map) == 0 || ft_total_check(&map) == 0)
		return (write(2, "Error from map\n", 16), 1);
	return (0);
}
