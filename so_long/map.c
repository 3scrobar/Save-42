/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 14:26:09 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the map structure with the map file
int	ft_init_map(t_map *map, char *path)
{
	char	**tab;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error from map reading", 22),0);
	while (fd != 0)
		{
			tab[i] = get_next_line(fd);
			i++;
		}
	map->map = tab;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->column = 0;
	map->line = 0;
}
//check if the map is valid with check of border
int	ft_parsing(t_map *map)
{

	int	len;

	while (map->map[map->line])
	{
		while (map->map[map->line][map->column])
		{
			len = ft_strlen(map->map[map->line]);
			if (map->map[0][map->column] != '1' || map->map[map->line][0] != '1'
				|| map->map[map->line][len - 1] != '1' || map->map[map->line][0] != '1')
				return (0);
			map->column += 1;
		}
		map->line += 1;
	}
	return (ft_checkmap_line(map), 1);
}
//check if the map is valid with the collectible, player and exit
int	ft_checkmap_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
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
	return (1);
}
//check if the map as the right number of player, exit and collectible
int	ft_total_check(t_map *map)
{
	if (map->player > 1 || map->exit > 1)
		return (write(2, "Error from map", 14), 0);
	else if (map->collectible == 0)
		return (write(2, "Error from map", 14), 0);
	return (1);
}
