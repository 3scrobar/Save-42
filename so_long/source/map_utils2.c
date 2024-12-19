/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/19 17:37:04 by tle-saut         ###   ########.fr       */
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
	all->imgwind = mlx_new_image(all->mlx, all->column * all->tile_size, all->line * all->tile_size);
	all->tile_size = 64;
	all->imgfont = mlx_xpm_file_to_image(all->mlx, "img/font.xpm", &all->tile_size, &all->tile_size);
	all->imgwall = mlx_xpm_file_to_image(all->mlx, "img/wall.xpm", &all->tile_size, &all->tile_size);
	//all->exitdiscover = mlx_xpm_file_to_image(all->mlx, "img/window.xpm", &all->tile_size, &all->tile_size);
	//all->exitcover = mlx_xpm_file_to_image(all->mlx, "img/door_closedMid.xpm", &all->tile_size, &all->tile_size);
	//all->collectible = mlx_xpm_file_to_image(all->mlx, "img/coins.xpm", &all->tile_size, &all->tile_size);
	all->imgplayer = mlx_xpm_file_to_image(all->mlx, "img/player.xpm", &all->tile_size, &all->tile_size);

	if (all->imgfont == NULL || all->imgwall == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}

