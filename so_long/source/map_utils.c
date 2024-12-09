/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:14 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/10 18:14:49 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_flood_path(t_map *map, size_t ystart, size_t xstart)
{
	if (ystart >= map->line || xstart >= map->column)
		return (0);
	if (map->map[ystart][xstart] == '1')
		return (0);
	if (map->map[ystart][xstart] == 'E')
		map->exit -= 1;
	if (map->map[ystart][xstart] == 'C')
		map->collectible -= 1;
	if (map->map[ystart][xstart] == '0' || map->map[ystart][xstart] == 'P' ||
		map->map[ystart][xstart] == 'E' || map->map[ystart][xstart] == 'C')
		map->map[ystart][xstart] = '1';
	ft_flood_path(map, ystart, xstart - 1);
	ft_flood_path(map, ystart, xstart + 1);
	ft_flood_path(map, ystart - 1, xstart);
	ft_flood_path(map, ystart + 1, xstart);
	ystart = 0;
	while (ystart < map->line)
	{
		if (ft_strchr(map->map[ystart], 'E') != 0
			|| ft_strchr(map->map[ystart], 'C') != 0
			|| ft_strchr(map->map[ystart], 'P') != 0)
			return (1);
		ystart++;
	}
	return (0);
}

int	ft_path_check(t_map *map)
{
	t_map map2;
	
	map2 = *map;
	ft_pos_check(*&map);
	if (ft_flood_path(&map2, map2.ybegin, map2.xbegin) == 1)
		return (ft_putstr_fd("Error from map, No Path\n", 2), 1);
	if (map->line == map->column)
		return (ft_putstr_fd("Error from map, Map is a square\n", 2), 1);
	return (0);
}

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
void draw_map(void *mlx, void *win,t_map *map, int tile_size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, map->snow, x * tile_size, y * tile_size);
			else if (map->map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, map->sand, x * tile_size, y * tile_size);
			else
				mlx_put_image_to_window(mlx, win, map->snow, x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}
