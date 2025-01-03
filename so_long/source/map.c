/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/20 16:12:43 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the map structure with the map file
int	ft_init_map(t_all *map, char *path)
{
	int		fd;
	int		a;

	a = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error from file reading\n", 2), 1);
	map->map = ft_init_tab(fd);
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->column = 0;
	map->line = ft_tablen(map->map);
	map->xbegin = 0;
	map->ybegin = 0;
	a += ft_checkmap_line(map);
	a += ft_pos_check(map);
	a += ft_parsing(map);
	close(fd);
	if(a == 0)
		return (0);
	else
		return(1);
}

//check if the map is valid with check of border
//need column and line
int	ft_parsing(t_all *map)
{
	int	len;

	while (map->map[map->line])
	{
		map->column = 0;
		len = ft_strlen(map->map[0]);
		while (map->map[map->line][map->column])
		{
			if (map->map[0][map->column] != '1' || map->map[map->line][0] != '1'
				|| map->map[map->line][len - 1] != '1'
				|| map->map[ft_tablen(map->map)][map->column] != '1')
				return (ft_putstr_fd("Error from map border\n", 2), 1);
			map->column += 1;
		}
		map->line += 1;
	}
	return (0);
}
//check size of tab
int	ft_tablen(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

//check if the map is valid with the collectible, player and exit
//give column , C , P, E
int	ft_checkmap_line(t_all *map)
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

//all the check for the map
int	ft_total_check(char *path)
{
	t_all	map;
	
	ft_init_map(&map, path);
	if (ft_checkmap_line(&map) != 0)
		return (ft_putstr_fd("Error, Line is not the same size\n", 2), 1);
	if (ft_parsing(&map) == 1)
		return (ft_putstr_fd("Error from border\n", 2), 1);
	if (map.player != 2)
		return (ft_putstr_fd("Error from map, Starting POS\n", 2), 1);
	else if (map.collectible <= 0)
		return (ft_putstr_fd("Error from map, Collectible\n", 2), 1);
	else if (map.exit != 2)
		return (ft_putstr_fd("Error from map, Exit POS\n", 2), 1);
	if (ft_path_check(&map) != 0)
		return (1);
	return (0);
}
