/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/13 16:29:49 by groot            ###   ########.fr       */
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
int	ft_init_img(t_data *img, t_vars *game)
{
	img->tyle_size = 70;
	img->snow = mlx_xpm_file_to_image(game->mlx, "img/snowCenter.xpm", &img->tyle_size, &img->tyle_size);
	img->sand = mlx_xpm_file_to_image(game->mlx, "img/sandCenter.xpm", &img->tyle_size, &img->tyle_size);
	img->exitdiscover = mlx_xpm_file_to_image(game->mlx, "img/window.xpm", &img->tyle_size, &img->tyle_size);
	img->exitcover = mlx_xpm_file_to_image(game->mlx, "img/door_closedMid.xpm", &img->tyle_size, &img->tyle_size);
	if (img->snow == NULL || img->sand == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}

