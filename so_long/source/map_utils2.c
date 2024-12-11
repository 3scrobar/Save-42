/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 17:22:37 by tle-saut         ###   ########.fr       */
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
	all->img->tyle_size = 70;
	all->img->snow = mlx_xpm_file_to_image(all->game->mlx, "img/snowCenter.xpm", &all->img->tyle_size, &all->img->tyle_size);
	all->img->sand = mlx_xpm_file_to_image(all->game->mlx, "img/sandCenter.xpm", &all->img->tyle_size, &all->img->tyle_size);
	all->img->exitdiscover = mlx_xpm_file_to_image(all->game->mlx, "img/window.xpm", &all->img->tyle_size, &all->img->tyle_size);
	all->img->exitcover = mlx_xpm_file_to_image(all->game->mlx, "img/door_closedMid.xpm", &all->img->tyle_size, &all->img->tyle_size);
	if (all->img->snow == NULL || all->img->sand == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}

