/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 16:31:02 by tle-saut         ###   ########.fr       */
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
int	ft_init_img(t_vars *mlx, t_data *img)
{
	img->tyle_size = 70;
	img->snow = mlx_xpm_file_to_image(mlx->mlx, "img/snowCenter.xpm", &img->tyle_size, &img->tyle_size);
	img->sand = mlx_xpm_file_to_image(mlx->mlx, "img/sandCenter.xpm", &img->tyle_size, &img->tyle_size);
	img->exitdiscover = mlx_xpm_file_to_image(mlx->mlx, "img/window.xpm", &img->tyle_size, &img->tyle_size);
	
	if (img->snow == NULL || img->sand == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}

