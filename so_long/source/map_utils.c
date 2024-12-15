/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:14 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/15 17:34:38 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//check depart Pos
//give xbegin , ybegin
int	ft_pos_check(t_map *map)
{
	while (map->map[map->ybegin])
	{
		map->xbegin = 0;
		while (map->map[map->ybegin][map->xbegin])
		{
			if (map->map[map->ybegin][map->xbegin] == 'P')
				return (0);
			map->xbegin += 1;
		}
		map->ybegin += 1;
	}
	return (0);
}
//check path of everything
int	ft_flood_path(t_map *map, size_t ystart, size_t xstart, char **tab)
{
	if (ystart >= map->line || xstart >= map->column)
		return (0);
	if (tab[ystart][xstart] == '1')
		return (0);
	if (tab[ystart][xstart] == 'E')
		map->exit -= 1;
	if (tab[ystart][xstart] == 'C')
		map->collectible -= 1;
	if (tab[ystart][xstart] == '0' || tab[ystart][xstart] == 'P' ||
		tab[ystart][xstart] == 'E' || tab[ystart][xstart] == 'C')
		tab[ystart][xstart] = '1';
	ft_flood_path(map, ystart, xstart - 1, tab);
	ft_flood_path(map, ystart, xstart + 1, tab);
	ft_flood_path(map, ystart - 1, xstart, tab);
	ft_flood_path(map, ystart + 1, xstart, tab);
	ystart = 0;
	while (ystart < map->line)
	{
		if (ft_strchr(tab[ystart], 'E') != 0
			|| ft_strchr(tab[ystart], 'C') != 0
			|| ft_strchr(tab[ystart], 'P') != 0)
			return (1);
		ystart++;
	}
	return (0);
}

int	ft_path_check(t_map *map)
{

	ft_pos_check(map);
	if (ft_flood_path(map, map->ybegin, map->xbegin, map->map) == 1)
		return (ft_putstr_fd("Error from map, No Path\n", 2), 1);
	if (map->line == map->column)
		return (ft_putstr_fd("Error from map, Map is a square\n", 2), 1);
	return (0);
}
//fill map tab
char	**ft_init_tab(int fd)
{
	int		a;
	char	buffer[BUFFER_SIZE + 1];
	char	**tab;
	char	*line;

	line = NULL;
	while (1)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a < 1)
			break ;
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoinfree(&line, buffer);
	}
	tab = ft_split(line, '\n');
	free(line);
	return (tab);
}
//draw map
void draw_map(t_all *all)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (all->map.map[y])
	{
		x = 0;
		while (all->map.map[y][x])
		{
			if (all->map.map[y][x] == '0' || all->map.map[y][x] == 'P')
				mlx_put_image_to_window(all->game.mlx, all->game.win, all->img.font, x * all->img.tyle_size, y * all->img.tyle_size);
			else if (all->map.map[y][x] == '1')
				mlx_put_image_to_window(all->game.mlx, all->game.win, all->img.wall, x * all->img.tyle_size, y * all->img.tyle_size);
			//else if(all->map.map[y][x] == 'E')
			//{
				//if(all->map.collectible != 0)
					//mlx_put_image_to_window(all->game.mlx, all->game.win, all->img.exitcover, x * all->img.tyle_size, y * all->img.tyle_size);
				//else
					//mlx_put_image_to_window(all->game.mlx, all->game.win, all->img.exitdiscover, x * all->img.tyle_size, y * all->img.tyle_size);
			//}
			//else if (all->map.map[y][x] == 'C')
				//mlx_put_image_to_window(all->game.mlx, all->game.win, all->img.collectible, x * all->img.tyle_size, y * all->img.tyle_size);
			x++;
		}
		y++;
	}
}
