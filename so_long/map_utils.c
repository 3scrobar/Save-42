/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:14 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/09 16:06:51 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pos_check(t_map *map)
{
	while (map->map[map->yStart])
	{
		map->xStart = 0;
		while (map->map[map->yStart][map->xStart])
		{
			if (map->map[map->yStart][map->xStart] == 'P')
				break;
			map->xStart += 1;
		}
		map->yStart += 1;
	}
	ft_printf("recuperation posotion joeur");
}
int	ft_flood_path(t_map *map, int xstart, int ystart)
{
	if (map->yStart < 0 || map->xStart < 0 || map->yStart >= map->line || map->xStart >= map->column)
		return (0);
	if (map->map[ystart][xstart] == '0')
		map->map[ystart][xstart] = '1';
	else if (map->map[ystart][xstart] == 'E')
		map->exit -= 1;
	else if (map->map[ystart][xstart] == 'C')
		map->collectible -= 1;
	else if (map->map[ystart][xstart] == '1')
		return (0);
	if (map->exit < 0 || map->collectible < 0 || map->exit > 1)
		return (1);
	ft_flood_path(map,map->xStart + 1, map->yStart);
	ft_flood_path(map,map->xStart - 1, map->yStart);
	ft_flood_path(map,map->xStart, map->yStart + 1);
	ft_flood_path(map,map->xStart, map->yStart - 1);	
	return (0);
}
int	ft_path_check(t_map *map)
{
	ft_printf("check path");

	ft_pos_check(map);
	if (ft_flood_path(map, map->xStart, map->yStart) == 1)
		return (ft_printf("Error from path\n"));
	if (ft_flood_path(map, map->xStart, map->yStart) == 1)
		return (ft_printf("Error from path\n"));
	return (0);
}
char	**ft_init_tab(int fd)
{
	int		a;
	char	buffer[BUFFER_SIZE + 1];
	char	**tab;
	char	*line;

	line = NULL;
	ft_printf("debut initialisation");
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
	ft_printf("check path");

	return (tab);
}


