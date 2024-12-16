/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/16 15:06:26 by tle-saut         ###   ########.fr       */
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
	all->tile_size = 64;
	all->font = mlx_xpm_file_to_image(all->mlx, "img/font.xpm", &all->tile_size, &all->tile_size);
	all->wall = mlx_xpm_file_to_image(all->mlx, "img/wall.xpm", &all->tile_size, &all->tile_size);
	//all->exitdiscover = mlx_xpm_file_to_image(all->mlx, "img/window.xpm", &all->tile_size, &all->tile_size);
	//all->exitcover = mlx_xpm_file_to_image(all->mlx, "img/door_closedMid.xpm", &all->tile_size, &all->tile_size);
	//all->collectible = mlx_xpm_file_to_image(all->mlx, "img/coins.xpm", &all->tile_size, &all->tile_size);
	all->player = mlx_xpm_file_to_image(all->mlx, "img/player.xpm", &all->tile_size, &all->tile_size);

	if (all->font == NULL || all->wall == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}

