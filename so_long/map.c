/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 21:09:43 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the map structure with the map file
int	ft_init_map(t_map *map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error from file reading\n", 2), 1);
	map->map = ft_init_tab(fd);
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->column = 0;
	map->line = 0;
	map->xStart = 0;
	map->yStart = 0;
	close(fd);
	return (ft_total_check(map));
}

//check if the map is valid with check of border
int	ft_parsing(t_map *map)
{
	int	len;

	while (map->map[map->line])
	{
		map->column = 0;
		while (map->map[map->line][map->column])
		{
			len = ft_strlen(map->map[map->line]);
			if (map->map[0][map->column] != '1' || map->map[map->line][0] != '1'
				|| map->map[map->line][len - 1] != '1'
				|| map->map[map->line][0] != '1')
				return (1);
			map->column += 1;
		}
		map->line += 1;
	}
	return (0);
}

//check if the map is valid with the collectible, player and exit
int	ft_checkmap_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->column = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->column)
			return (1);
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] == 'C')
				map->collectible += 1;
			j++;
		}
		i++;
	}
	return (0);
}

//check if the map as the right number of player, exit and collectible
int	ft_total_check(t_map *map)
{
	if (ft_checkmap_line(map) != 0)
		return (ft_putstr_fd("Error, Line is not the same size\n", 2), 1);
	if (ft_parsing(map) == 1)
		return (ft_putstr_fd("Error from border\n", 2), 1);
	if (map->player != 1)
		return (ft_putstr_fd("Error from map, NO Starting POS\n", 2), 1);
	else if (map->collectible == 0)
		return (ft_putstr_fd("Error from map, NO Collectible\n", 2), 1);
	else if (map->exit != 1)
		return (ft_putstr_fd("Error from map, NO Exit POS\n", 2), 1);
	if (ft_path_check(map) != 0)
		return (1);
	return (0);
}
