/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:14 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/06 17:36:55 by tle-saut         ###   ########.fr       */
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
}
int	ft_flood_path(t_map map)
{


}
void	ft_path_check(t_map *map)
{

	ft_pos_check(map);
	ft_flood_path(map);
	
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


