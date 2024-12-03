/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 17:21:23 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_map *map, char *path)
{
	map->map = NULL;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
}

int	ft_parsing(t_map *map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			len = ft_strlen(map->map[i]);
			if (map->map[0][j] != '1' || map->map[i][0] != '1'
				|| map->map[i][len - 1] != '1' || map->map[i][0] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (ft_checkmap_line(map), 1);
}

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
int	ft_total_check(t_map *map)
{
	if (map->player > 1 || map->exit > 1)
		return (write(1, "Error from map", 14), 0);
	else if (map->collectible == 0)
		return (write(1, "Error from map", 14), 0);
	return (1);
}
