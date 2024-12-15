/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/15 18:21:19 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//free a tab of char
void free_tab(char **map)
{
	int	i;
	
	i = 0;
	if (!map)
		return;
	if (map)
		while(map[i])
			free(map[i++]);
	free(map);
}
//init all the img
int	ft_init_img(t_all *all)
{
	all->map.tile_size = 64;
	all->img.font = mlx_xpm_file_to_image(all->game.mlx, "img/font.xpm", &all->img.tyle_size, &all->img.tyle_size);
	all->img.wall = mlx_xpm_file_to_image(all->game.mlx, "img/wall.xpm", &all->img.tyle_size, &all->img.tyle_size);
	//all->img.exitdiscover = mlx_xpm_file_to_image(all->game.mlx, "img/window.xpm", &all->img.tyle_size, &all->img.tyle_size);
	//all->img.exitcover = mlx_xpm_file_to_image(all->game.mlx, "img/door_closedMid.xpm", &all->img.tyle_size, &all->img.tyle_size);
	//all->img.collectible = mlx_xpm_file_to_image(all->game.mlx, "img/coins.xpm", &all->img.tyle_size, &all->img.tyle_size);
	all->img.player = mlx_xpm_file_to_image(all->game.mlx, "img/player.xpm", &all->img.tyle_size, &all->img.tyle_size);

	if (all->img.font == NULL || all->img.wall == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}

