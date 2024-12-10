/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/10 14:35:18 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (ac != 2)
		return (ft_putstr_fd("Error from Arguments\n", 2), 1);
	if (ft_init_map(&map, av[1]) == 1)
		return (1);
	else
		ft_printf("Map Valide, Launch The Game .....\n");
	window = mlx_new_window(mlx,800,600,"so_long");
	if (window == NULL)
		return 1;
	mlx_loop(mlx);


		
	return (0);
}
