/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 16:12:39 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the map structure with the map file
int	ft_init_map(t_map *map, char *path)
{
	int		fd;
	int		i;
	
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error from file reading\n", 24),0);
	map->map = ft_init_tab(fd);
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->column = 0;
	map->line = 0;
	map->xStart  = 0;
	map->yStart = 0;
	close(fd);
	return (1);
}
//check if the map is valid with check of border
int	ft_parsing(t_map *map)
{

	int	len;
	ft_printf("parsing\n");

	while (map->map[map->line])
	{
		map->column = 0;
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
	ft_printf("end parsing\n");

	return (ft_checkmap_line(map), 1);
}
//check if the map is valid with the collectible, player and exit
int	ft_checkmap_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("comptage des items\n");

	while (map->map[i])
	{
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
	ft_printf("fin comptage\n");
	
	return (1);
}
//check if the map as the right number of player, exit and collectible
int	ft_total_check(t_map *map)
{
	ft_printf("debut total check\n");

	if (map->player != 1)
		return (ft_putstr_fd("Error from map, No Starting POS\n",2), 0);
	else if (map->collectible == 0)
		return (ft_putstr_fd("Error from map, NO Collectible\n",2), 0);
	else if (map->exit != 1)
		return (ft_putstr_fd("Error from map, NO Exit POS\n",2), 0);
	ft_printf("end total check\n");
	ft_path_check(map);

	return (1);
}
